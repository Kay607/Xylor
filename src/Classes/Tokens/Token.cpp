//
// Created by uffan on 26/10/2024.
//

#include "Token.h"

#include <vector>

constexpr unsigned int hash(const char* s, const int off = 0)
{
    return !s[off] ? 5381 : (hash(s, off + 1) * 33) ^ s[off];
}

Token Token::GenerateToken(const std::vector<Token>& tokenStream, const std::string& keyword)
{
    Token token;

    token.tokenIdentifier = keyword;

    TokenType type = {};

    switch (hash(keyword.c_str()))
    {
    case hash("int"):
    case hash("float"):
    case hash("string"):
    case hash("double"):
    case hash("char"):
    case hash("long"):
    case hash("bool"):
    case hash("void"):
        type = TokenType::Type;
        break;
    case hash("+"):
    case hash("+="):
    case hash("-"):
    case hash("-="):
    case hash("*"):
    case hash("*="):
    case hash("/"):
    case hash("/="):
    case hash("^"):
    case hash("="):
    case hash("=="):
    case hash("!="):
    case hash("<"):
    case hash(">"):
    case hash("("):
    case hash(")"):
    case hash("=>"):
    case hash("{"):
    case hash("}"):
    case hash("<="):
    case hash(">="):
    case hash("and"):
    case hash("pass"):
        type = TokenType::Operator;
        break;
    case hash(";"):
        type = TokenType::SemiColon;
        break;
    default:
        if (tokenStream[tokenStream.size() - 1].tokenType == TokenType::Type)
            type = TokenType::Identifier;
        else
            type = TokenType::Value;
    }

    token.tokenType = type;

    return token;
}

Token::operator std::string() const
{
    std::string type;

    switch (tokenType)
    {
    case TokenType::Operator:
        type = "Operator";
        break;
    case TokenType::SemiColon:
        type = "SemiColon";
        break;
    case TokenType::Identifier:
        type = "Identifier";
        break;
    case TokenType::Value:
        type = "Value";
        break;
    case TokenType::Type:
        type = "Type";
        break;
    }

    return std::string("[Name: '" + tokenIdentifier + "', Type: '" + type + "']");
}
