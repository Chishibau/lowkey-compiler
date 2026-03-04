#ifndef lowkey_chunk_h
#define lowkey_chunk_h

#include "common.h"

enum class OpCode {
    OP_RETURN,
};

class Chunk {
public:
    Chunk();
    void reset();
    void write(uint8_t byte);
    void free();

private:
    int count;
    int capacity;
    uint8_t* code;
};

#endif