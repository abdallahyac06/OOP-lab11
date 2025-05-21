#include <iostream>
#include "table.hpp"

template <typename T>
Table<T>::Table(int r, int c) : rowsize(r), columnsize(c) {
    if (rowsize < 1 || columnsize < 1) {
        throw std::invalid_argument("Invalid array size.");
    }
    data = new T[rowsize * columnsize];
}

template <typename T>
Table<T>::~Table() {
    delete[] data;
    data = nullptr;
}

template <typename T>
T &Table<T>::operator()(int r, int c) {
    if (r < 0 || r >= rowsize || c < 0 || c >= columnsize) {
        throw OutOfRangeError();
    }
    return data[r * columnsize + c];
}

template <typename T>
const T &Table<T>::operator()(int r, int c) const {
    if (r < 0 || r >= rowsize || c < 0 || c >= columnsize) {
        throw OutOfRangeError();
    }
    return data[r * columnsize + c];
}

template <typename T>
const Table<T> &Table<T>::operator=(const Table<T> &other) {
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

template <typename T>
bool Table<T>::operator!=(const Table &other) const {
    return !(this->operator==(other));
}

template <typename T>
bool Table<T>::operator==(const Table &other) const {
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

template <typename T>
std::ostream &operator<<(std::ostream &os, const Table<T> &arr) {
    for (int i = 0; i < arr.rowsize; ++i) {
        for (int j = 0; j < arr.columnsize; ++j) {
            os << arr(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}

template <typename T>
std::istream &operator>>(std::istream &is, Table<T> &arr) {
    for (int i = 0; i < arr.rowsize; ++i) {
        for (int j = 0; j < arr.columnsize; ++j) {
            is >> arr(i, j);
        }
    }
    return is;
}