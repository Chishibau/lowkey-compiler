#pragma once

#include "common.h"
#include "opcode.h"
#include "value.h"

// represents a chunk of bytecodes and contains an array of constants
class Chunk {
public:
    std::vector<uint8_t> code;
    std::vector<Value> constants;

    Chunk();
    void write(uint8_t byte);
    int addConstant(Value value);
};