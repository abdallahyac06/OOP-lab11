#include <iostream>

template <typename T1, typename T2>
Pair<T1, T2>::Pair(const T1 &t, const T2 &u) : first(t), second(u) {}

template <typename T1, typename T2>
T1 &Pair<T1, T2>::get_first() {
    return first;
}

template <typename T1, typename T2>
T2 &Pair<T1, T2>::get_second() {
    return second;
}

template <typename T1, typename T2>
const T1 &Pair<T1, T2>::get_first() const {
    return first;
}

template <typename T1, typename T2>
const T2 &Pair<T1, T2>::get_second() const {
    return second;
}

template <typename T1, typename T2>
void print_pair(const Pair<T1, T2> &p) {
    std::cout << '(' << p.get_first() << ", " << p.get_second() << ")\n";
}