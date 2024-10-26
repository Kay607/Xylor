#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>

#include "Enums/TokenType.h"

std::vector<std::string> split_sentence(std::string sen)
{
    // Create a stringStream object
    std::stringstream ss(sen);

    // Variable to hold each word
    std::string word;

    // Vector to store the words
    std::vector<std::string> words;

    // Extract words from the sentence
    while (ss >> word)
    {
        // Add the word to the vector
        words.push_back(word);
    }

    return words;
}

class Token
{
public:
    std::string tokenIdentifier;
    TokenType tokenType;


    static Token GenerateToken(std::string keyword)
    {
        Token token;

        token.tokenIdentifier = keyword;

        TokenType type;

        switch (keyword)
        {
        case "int":
            type = TokenType::Type;
        }

        token.tokenType = type;

        return token;
    }
};

void skipBOM(std::istream& in)
{
    char test[4] = {0};
    in.read(test, 3);
    if (strcmp(test, "\xEF\xBB\xBF") == 0)
        return;
    in.seekg(0);
}

#ifndef XY_TESTING
int main()
{
    std::ifstream code("../../XY Files/test.xy");

    if (!code.is_open())
    {
        std::cout << "File not found" << std::endl;
        return 1;
    }

    skipBOM(code);

    std::string lines;
    std::vector<std::string> line;

    std::vector<Token> tokens;

    while (std::getline(code, lines))
        line.push_back(lines);

    auto words = split_sentence(line[0]);

    for (const auto& word : words)
    {
        std::cout << word << std::endl;
    }

    return 0;
}
#endif
