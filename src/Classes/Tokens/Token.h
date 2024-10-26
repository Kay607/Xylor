//
// Created by uffan on 26/10/2024.
//

#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <vector>

#include "../../Enums/TokenType.h"

enum class TokenType;


class Token
{
public:
    std::string tokenIdentifier;
    TokenType tokenType;

    static Token GenerateToken(const std::vector<Token>& tokenStream, const std::string& keyword);

    operator std::string() const;
};


#endif //TOKEN_H
