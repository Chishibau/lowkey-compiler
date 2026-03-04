#include <iostream>
#include "common.h"
#include "chunk.h"

int main(int argc, char* argv[]) {
    Chunk* chunk = new Chunk();
    chunk->write(OpCode::OP_RETURN);
    chunk->free();

    return 0;
}

