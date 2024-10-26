#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>

#include "Classes/Tokens/Token.h"

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

    std::vector<Token> tokenStream;

    while (std::getline(code, lines))
        line.push_back(lines);

    auto words = split_sentence(line[3]);


    int i = 0;

    tokenStream.reserve(words.size());
    for (const auto& word : words)
    {
        tokenStream.push_back(Token::GenerateToken(tokenStream, word));
        std::cout << std::string(tokenStream[i]) << std::endl;
        i++;
    }

    return 0;
}
#endif
