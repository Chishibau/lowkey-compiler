#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

Chunk::Chunk() {
    this->code = {};
    this->constants = {};
}

void Chunk::write(uint8_t byte) {
    this->code.push_back(byte);
}

int Chunk::addConstant(Value value) {
    this->constants.push_back(value);
    return this->constants.size() - 1;
};