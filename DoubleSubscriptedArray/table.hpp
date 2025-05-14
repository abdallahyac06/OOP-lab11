#ifndef TABLE_HPP
#define TABLE_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Table {
private:
    int rowsize;
    int columnsize;
    T *data;

public:
    Table(int = 10, int = 10);
    ~Table();
    T &operator()(int, int);
    const T &operator()(int, int) const;
    const Table<T> &operator=(const Table<T> &);
    bool operator!=(const Table<T> &) const;
    bool operator==(const Table<T> &) const;

    template <typename U>
    friend std::ostream &operator<<(std::ostream &, const Table<U> &);
    template <typename U>
    friend std::istream &operator>>(std::istream &,  Table<U> &);
};

class OutOfRangeError : public std::exception {
    public:
        virtual const char *what() const noexcept override {
            return "The index is out of range";
        }
};

#include "table.tpp"

#endif