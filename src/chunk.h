#pragma once

#include "common.h"
#include "opcode.h"

class Chunk {
public:
    Chunk();
    void reset();
    void write(uint8_t byte);
    void free();
    int getCount();
    int getCapacity();
    uint8_t* getCode();

private:
    int count;
    int capacity;
    uint8_t* code;
};