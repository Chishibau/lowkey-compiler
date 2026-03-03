#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <optional>
#include <vector>
#include "scanner.h"

int main(int argc, char* argv[]) {
    // check if a single source file is given as an argument
    if (argc != 2) {
        std::cout << "Please provide a single source file to be compiled..." << std::endl;
        return EXIT_FAILURE;
    }
    
    // read the entire source file
    std::string contents;
    {
    std::ifstream file(argv[1]);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open source file...");
    }
    std::stringstream source;
    source << file.rdbuf();
    contents = source.str();
    }

    std::cout << contents << std::endl;

    tokenize(contents);

    return 0;
}