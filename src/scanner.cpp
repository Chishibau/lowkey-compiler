#include <iostream>
#include <string>
#include <optional>
#include <vector>

enum class TokenType {
    EXIT,
    INT_LIT,
    SEMI
};

struct Token {
    TokenType type;
    std::optional<std::string> val;
};

class Scanner {
    public:
        std::vector<Token> tokenize(const std::string& str) {
            for (char c : str) {
                std::cout << c << std::endl;
            }
        
            return {};
        }

    private:
        
};
