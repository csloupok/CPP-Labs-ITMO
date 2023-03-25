//
// Created by Eldar Kasymov on 01.06.2022.
//

#pragma once

#include <stddef.h>

class DataPool {
private:
    void *base;
    size_t size;
public:
    DataPool(void *_base, size_t _size);

    void *allocate(size_t bytes);

    void deallocate(void *p);
};
