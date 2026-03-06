#pragma once

#include "common.h"
#include "chunk.h"

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

class VM {
    public:
        static Chunk* chunk;
        static uint8_t* ip;

        VM();
        InterpretResult interpret(Chunk* chunk);
        static InterpretResult run();
};