#include "vm.h"

VM::VM() {
    // this->chunk = new Chunk();
}

InterpretResult VM::interpret(Chunk* chunk) {
    this->chunk = chunk;
    this->ip = chunk->code.data();
    return run();
}

InterpretResult VM::run() {
    #define READ_BYTE() (*ip++)
    #define READ_CONSTANT() (chunk->constants[READ_BYTE()])
    for (;;) {
        uint8_t instruction;
        switch (instruction = READ_BYTE()) {
            case OP_CONSTANT: {
                Value constant = READ_CONSTANT();
                printValue(constant);
                printf("\n");
                break;
            }
            case OP_RETURN: {
                return INTERPRET_OK;
            }
        }
    }

    #undef READ_BYTE
    #undef READ_CONSTANT
}