#pragma once

#include <iterator>

template<class T>
class CircularBuffer {
private:
    size_t capacity{};
    T *buf;
    int start = 0;
    int final = 0;

public:
    class Iterator : public std::iterator<std::random_access_iterator_tag, T> {
    private:
        T *iterPointer;
    public:

        Iterator() : iterPointer{nullptr} {}

        explicit Iterator(T *p) : iterPointer{p} {}

        Iterator(const Iterator &iterator) : iterPointer{iterator.iterPointer} {}

        Iterator operator+(int n) {
            return Iterator(iterPointer + n);
        }

        Iterator operator-(int n) {
            return Iterator(iterPointer - n);
        }

        Iterator &operator+=(T n) {
            iterPointer += n;
            return *this;
        }

        Iterator &operator-=(T n) {
            iterPointer -= n;
            return *this;
        }

        Iterator &operator++() {
            iterPointer++;
            return *this;
        }

        Iterator &operator--() {
            iterPointer--;
            return *this;
        }

        Iterator operator++(T) {
            Iterator iterator{*this};
            ++iterPointer;
            return iterator;
        }

        Iterator operator--(T) {
            Iterator iterator{*this};
            --iterPointer;
            return iterator;
        }

        auto operator-(const Iterator &iterator) {
            return (iterPointer - iterator.iterPointer);
        }

        T &operator*() const {
            return *iterPointer;
        }

        T *operator->() const {
            return iterPointer;
        }

        T &operator[](const int n) {
            return iterPointer[n];
        }

        bool operator==(const Iterator &iterator) const {
            return iterator.iterPointer == this->iterPointer;
        }

        bool operator!=(const Iterator &iterator) const {
            return iterator.iterPointer != this->iterPointer;
        }

        bool operator<(const Iterator &iterator) const {
            return iterator.iterPointer < this->iterPointer;
        }

        bool operator>(const Iterator &iterator) const {
            return iterator.iterPointer > this->iterPointer;
        }

        bool operator>=(const Iterator &iterator) const {
            return iterator.iterPointer >= this->iterPointer;
        }

        bool operator<=(const Iterator &iterator) const {
            return iterator.iterPointer <= this->iterPointer;
        }
    };

public:
    CircularBuffer() = default;

    explicit CircularBuffer(size_t capacity) : capacity{capacity} {
        buf = new T[capacity];
        start = 0;
        final = 0;
    }

    ~CircularBuffer() {
        delete[] buf;
    }

    Iterator begin() const {
        return Iterator(buf + start);
    }

    Iterator end() const {
        return Iterator(buf + final);
    }

    T &front() const {
        return buf[start];
    }

    T &back() const {
        return buf[final - 1];
    }

    T &operator[](int n) {
        return buf[n % capacity];
    }

    void push_front(const T &value) {
        if (final == capacity) {
            buf[start] = value;
            return;
        }
        for (int i = final; i >= start; i--)
            buf[i + 1] = buf[i];
        buf[start] = value;
        final++;
    }

    void push_back(const T &value) {
        if (final == capacity)
            final--;
        buf[final] = value;
        if (final != capacity + 1)
            final++;
    }

    void pop_front() {
        buf[start] = 0;
        start++;
    }

    void pop_back() {
        buf[final] = 0;
        final--;
    }

    void resize(const int n) {
        T *newBuf = new T[n];
        for (int i = 0; i < n; i++) {
            if (i < capacity)
                newBuf[i] = buf[i];
            else
                newBuf[i] = 0;
        }
        delete[] buf;
        buf = newBuf;
        capacity = n;
        final = start + capacity;
    }
};
