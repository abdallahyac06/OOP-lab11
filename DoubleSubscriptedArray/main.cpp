#include "table.hpp"
#include <iostream>

int main() {
    Table<int> t(3, 2);
    std::cin >> t;
    std::cout << t;
    return 0;
}