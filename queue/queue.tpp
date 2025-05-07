#include <iostream>

template <typename T>
Queue<T>::Queue(int size) : Qsize(size), last(-1) {
    queueptr = new T[Qsize];
}

template <typename T>
Queue<T>::~Queue() {
    delete[] queueptr;
}

template <typename T>
bool Queue<T>::push(const T &item) {
    if (isFull()) {
        return false;
    }
    queueptr[++last] = item;
    return true;
}

template <typename T>
bool Queue<T>::pop(T &item) {
    if (isEmpty()) {
        return false;
    }
    item = queueptr[0];
    for (int i = 0; i < last; ++i) {
        queueptr[i] = queueptr[i + 1];
    }
    --last;
    return true;
}

template <typename T>
bool Queue<T>::isFull() const {
    return last == Qsize - 1;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return last == -1;
}

template <typename T>
void Queue<T>::print() const {
    if (isEmpty()) {
        std::cout << "Queue is empty.";
    } else {
        std::cout << queueptr[0];
        for (int i = 1; i <= last; ++i) {
            std::cout << ", " << queueptr[i];
        }
    }
    std::cout << std::endl;
}