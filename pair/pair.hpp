#ifndef PAIR_HPP
#define PAIR_HPP

template <typename T1, typename T2>
class Pair {
public:
    Pair() = default;
    Pair(const T1 &, const T2 &);
    T1 &get_first();
    T2 &get_second();
    const T1 &get_first() const;
    const T2 &get_second() const;

private:
    T1 first;
    T2 second;
};

#include "pair.tpp"

#endif