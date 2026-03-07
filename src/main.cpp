#include <iostream>
#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, char* argv[]) {
    VM vm;
    Chunk* chunk = new Chunk();
    int constant = chunk->addConstant(1.2);

    chunk->write(OP_CONSTANT, 123);
    chunk->write(constant, 123);
    chunk->write(OP_RETURN, 123);

    disassembleChunk(chunk, "test chunk");
    vm.interpret(chunk);
    delete(chunk);

    return 0;
}

