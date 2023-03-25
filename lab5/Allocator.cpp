//
// Created by Eldar Kasymov on 01.06.2022.
//

#include "Allocator.h"

namespace Allocator {
    struct BlockData {
        int reserved = 1;
        int size = 31;
    };
}

using Allocator::BlockData;

DataPool::DataPool(void *_base, size_t _size) : base(_base), size(_size) {
    BlockData *first_block = (BlockData *) _base;
    first_block->reserved = 0;
    first_block->size = _size;
}

void *DataPool::allocate(size_t bytes) {
    bytes += (bytes & 3) ? 4 - (bytes & 3) : 0;
    size_t block = bytes + sizeof(BlockData);
    BlockData *p;
    const BlockData *last = (BlockData *) ((int *) base + size);
    for (p = (BlockData *) base; p < last; p = (BlockData *) ((int *) p + p->size)) {
        if (p->reserved == 1 || p->size < block) {
            continue;
        }
        p->reserved = 1;
        if (p->size > block) {
            BlockData *next = (BlockData *) ((int *) p + block);
            next->reserved = 0;
            next->size = p->size - block;
        }
        p->size = block;
        return p + 1;
    }
    return nullptr;
}

void DataPool::deallocate(void *p) {
    BlockData *block = (BlockData *) p - 1;
    if (block < base || block > (BlockData *) ((int *) base + size)) {
        return;
    }

    BlockData *next = (BlockData *) ((int *) block + block->size);
    if (next != (BlockData *) ((int *) base + size)) {
        if (next->reserved == 0) {
            block->size += next->size;
        }
    }
    block->reserved = 0;
    BlockData *prev = (BlockData *) base;
    while (prev < block) {
        BlockData *prenex = (BlockData *) ((int *) prev + prev->size);
        if (prenex != block) {
            prev = prenex;
            continue;
        }

        if (prev->reserved == 0) {
            prev->size += block->size;
        }
        return;
    }
}



