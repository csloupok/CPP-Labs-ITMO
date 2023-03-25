#include <iostream>
#include <algorithm>
#include "CircularBuffer.h"

void output(int x) {
    std::cout << x;
}

int main() {
    CircularBuffer<int> circularBuffer(5);

    circularBuffer.push_front(1);
    circularBuffer.push_back(2);
    circularBuffer.push_front(3);
    circularBuffer.push_back(4);
    circularBuffer.push_front(5);

    std::for_each(circularBuffer.begin(), circularBuffer.end(), output);

    std::cout << std::endl;

    for (auto &i: circularBuffer)
        std::cout << i << " ";
    std::cout << std::endl;

    circularBuffer.resize(3);

    for (auto &i: circularBuffer)
        std::cout << i << " ";
    std::cout << std::endl;

    std::sort(circularBuffer.begin(), circularBuffer.end());

    for (auto &i: circularBuffer)
        std::cout << i << " ";
    std::cout << std::endl;

    circularBuffer.pop_back();
    circularBuffer.pop_front();

    for (auto &i: circularBuffer) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << circularBuffer[1];
    return 0;
}