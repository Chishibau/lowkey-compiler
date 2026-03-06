#pragma once

#include "common.h"
#include "opcode.h"
#include "value.h"

// represents a chunk of bytecodes and contains an array of constants
class Chunk {
public:
    std::vector<uint8_t> code;
    std::vector<Value> constants;
    std::vector<int> lineNum;
    std::vector<int> lineStarts;

    Chunk();
    void write(uint8_t byte, int line);
    int addConstant(Value value);
    int getLine(int offset);
};