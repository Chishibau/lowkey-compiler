#include "vm.h"

VM::VM() {
    this->chunk = new Chunk();
}

VM::~VM() {
    delete(this->chunk);
}

InterpretResult VM::interpret(Chunk* chunk) {
    this->chunk = chunk;
    this->ip = 0;
    return run();
}

InterpretResult VM::run() {
    #define READ_BYTE() (ip = ip++)
    #define READ_CONSTANT() (chunk->constants[READ_BYTE()])
    for (;;) {
    #ifdef DEBUG_TRACE_EXECUTION
        printf("        ");
        std::stack<int> temp;
        while (!stack.empty()) {
            temp.push(stack.top());
            stack.pop();
        }
        while (!temp.empty()) {
            printf("[ ");
            printValue(temp.top());
            printf(" ]");
            stack.push(temp.top());
            temp.pop();
        }
        printf("\n");
        disassembleInstruction(chunk, ip);
    #endif

        uint8_t instruction;
        switch (instruction = READ_BYTE()) {
            case OP_CONSTANT: {
                Value constant = READ_CONSTANT();
                stack.push(constant);
                break;
            }
            case OP_RETURN: {
                printValue(stack.top());
                printf("\n");
                stack.pop();
                return INTERPRET_OK;
            }
        }
    }

    #undef READ_BYTE
    #undef READ_CONSTANT
}