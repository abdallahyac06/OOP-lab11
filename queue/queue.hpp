#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T>
class Queue {
private:
    int Qsize;
    int last;
    T *queueptr;

public:
    Queue(int = 10);
    ~Queue();
    bool push(const T &);
    bool pop(T &);
    bool isFull() const;
    bool isEmpty() const;
    void print() const;
};

#include "queue.tpp"

#endif