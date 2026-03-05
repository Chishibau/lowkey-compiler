#include <iostream>
#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, char* argv[]) {
    Chunk* chunk = new Chunk();
    int constant = chunk->addConstant(1.2);

    chunk->write(OP_CONSTANT);
    chunk->write(constant);
    chunk->write(OP_RETURN);

    disassembleChunk(chunk, "test chunk");

    delete(chunk);

    return 0;
}

