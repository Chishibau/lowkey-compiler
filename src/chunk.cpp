#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

Chunk::Chunk() {
    this->code = {};
    this->constants = {};
}

void Chunk::write(uint8_t byte, int line) {
    this->code.push_back(byte);

    if (lineNum.empty() || line != lineNum.back()) {
        this->lineNum.push_back(line);
        this->lineStarts.push_back(code.size() - 1);
    } 
}

int Chunk::addConstant(Value value) {
    this->constants.push_back(value);
    return this->constants.size() - 1;
}

int Chunk::getLine(int offset) {
    for (int i = 0; i < lineStarts.size(); i++) {
        if (i == lineStarts.size() - 1 || offset < lineStarts[i + 1]) {
            return lineNum[i];
        }
    }

    return -1; // error value if line not found
}