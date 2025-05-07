#ifndef DOUBLESUBSCRIPTEDARRAY_H
#define DOUBLESUBSCRIPTEDARRAY_H

#include <iostream>

class DoubleSubscriptedArray {
private:
    int rowsize;
    int columnsize;
    int *data;

public:
    DoubleSubscriptedArray(int = 10, int = 10 );
    ~DoubleSubscriptedArray();
    int &operator()(int, int);
    const int &operator()(int, int) const;
    const DoubleSubscriptedArray &operator=(const DoubleSubscriptedArray &);
    bool operator!=(const DoubleSubscriptedArray &) const;
    bool operator==(const DoubleSubscriptedArray &) const;
    
    friend std::ostream &operator<<(std::ostream &, const DoubleSubscriptedArray &);
    friend std::istream &operator>>(std::istream &,  DoubleSubscriptedArray &);
};

#endif