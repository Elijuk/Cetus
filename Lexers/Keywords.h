#ifndef PRIVATE_PROJECTS_KEYWORDS_H
#define PRIVATE_PROJECTS_KEYWORDS_H

#include  "Token.h"
#include <string_view>
#include <unordered_map>

typedef std::unordered_map<std::string_view, TokenType> keyword_umap;

inline keyword_umap all_keywords {
    // variables types
    {"int", TokenType::Int},
    {"double", TokenType::Double},
    {"float", TokenType::Float},
    {"string", TokenType::String},
    {"char", TokenType::Char},
    {"bool", TokenType::Bool},
        {"true", TokenType::True},
        {"false", TokenType::False},
    {"var", TokenType::Var},

    // selection
    {"if", TokenType::If},
    {"elf", TokenType::ElseIf},
    {"else", TokenType::Else},

    // iteration
    {"while", TokenType::While},
    {"for", TokenType::For},

    // functions
    {"void", TokenType::Void},
    {"return", TokenType::Return},
};

#endif //PRIVATE_PROJECTS_KEYWORDS_H