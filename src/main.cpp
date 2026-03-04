#include <iostream>
#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, char* argv[]) {
    Chunk* chunk = new Chunk();
    chunk->write(OpCode::OP_RETURN);

    disassembleChunk(chunk, "test chunk");

    chunk->free();
    return 0;
}

