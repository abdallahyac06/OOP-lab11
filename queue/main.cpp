#include <iostream>
#include "queue.hpp"

int main() {
    Queue<int> q(5);
    int item = 0;

    while (q.push(++item)) {
        std::cout << "Pushed: " << item << std::endl;
    }
    std::cout << "Queue is full." << std::endl;
    q.print();

    while (q.pop(item)) {
        std::cout << "Popped: " << item << std::endl;
    }
    std::cout << "Queue is empty." << std::endl;
    q.print();

    return 0;
}