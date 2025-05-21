#include "DoubleSubscriptedArray.h"
#include <iostream>
#include <stdexcept>

DoubleSubscriptedArray::DoubleSubscriptedArray(int r, int c) : rowsize(r), columnsize(c) {
    if (rowsize < 1 || columnsize < 1) {
        throw std::invalid_argument("Invalid array size.");
    }
    data = new int[rowsize * columnsize];
}

DoubleSubscriptedArray::~DoubleSubscriptedArray() {
    delete[] data;
}

int &DoubleSubscriptedArray::operator()(int r, int c) {
    if (r < 0 || r >= rowsize || c < 0 || c >= columnsize) {
        throw std::out_of_range("Index out of range.");
    }
    return data[r * columnsize + c];
}

const int &DoubleSubscriptedArray::operator()(int r, int c) const {
    if (r < 0 || r >= rowsize || c < 0 || c >= columnsize) {
        throw std::out_of_range("Index out of range.");
    }
    return data[r * columnsize + c];
}

const DoubleSubscriptedArray &DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray &other) {
    if (this != &other) {
        if (rowsize != other.rowsize || columnsize != other.columnsize) {
            delete[] data;
            rowsize = other.rowsize;
            columnsize = other.columnsize;
            data = new int[rowsize * columnsize];
        }
        for (int i = 0; i < rowsize * columnsize; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

bool DoubleSubscriptedArray::operator!=(const DoubleSubscriptedArray &other) const {
    return !(this->operator==(other));
}

bool DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray &other) const {
    if (rowsize != other.rowsize || columnsize != other.columnsize) {
        return false;
    }
    for (int i = 0; i < rowsize * columnsize; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, const DoubleSubscriptedArray &arr) {
    for (int i = 0; i < arr.rowsize; ++i) {
        for (int j = 0; j < arr.columnsize; ++j) {
            os << arr(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}

std::istream &operator>>(std::istream &is, DoubleSubscriptedArray &arr) {
    for (int i = 0; i < arr.rowsize; ++i) {
        for (int j = 0; j < arr.columnsize; ++j) {
            is >> arr(i, j);
        }
    }
    return is;
}