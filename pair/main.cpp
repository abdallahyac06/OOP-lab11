#include "pair.hpp"

int main() {
    Pair<int, int> p1(1, 2);
    print_pair(p1);

    Pair<double, double> p2;
    p2.get_first() = 3.14159;
    p2.get_second() = 1.61803;
    print_pair(p2);

    Pair<std::string, int> p3("Hello", 42);
    print_pair(p3);

    return 0;
}