#include "table.hpp"
#include <iostream>

int main()
{

    try
    {
        Table<int> t(3, 2);
        t(0, 0) = 1;
        t(0, 1) = 2;
        t(1, 0) = 3;
        t(1, 1) = 4;
        t(2, 0) = 5;
        t(2, 1) = 6;
        std::cout << "Table t:\n"
                  << t << std::endl;

        Table<int> t2(2, 2);
        std::cout << "Table t2:\n"
                  << t2 << std::endl;
        t2 = t;
        if (t == t2)
        {
            std::cout << "Tables are equal after assignment." << std::endl;
        }
        else
        {
            std::cout << "Tables are not equal after assignment." << std::endl;
        }
        std::cout << "Table t2 after assignment:\n" << t2 << std::endl;
        std::cout << "t2(3, 3): " << t2(3, 3) << std::endl;
    }
    catch (const std::exception &oof)
    {
        std::cout << oof.what() << std::endl;
    }

    return 0;
}