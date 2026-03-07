#pragma once

#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "value.h"
#include <stack>

#define STACK_MAX 256

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;



class VM {
    public:
        Chunk* chunk;
        uint8_t ip;
        std::stack<Value> stack;

        VM();
        ~VM();
        InterpretResult interpret(Chunk* chunk);
        
    private:
        InterpretResult run();
};