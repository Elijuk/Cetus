#pragma once

#ifndef CETUSCOMPILER_DEFAULTOPERATORS_H
#define CETUSCOMPILER_DEFAULTOPERATORS_H

#include "Token.h"

#include <string_view>
#include <unordered_map>

namespace CetusOperator {
    typedef std::unordered_map<std::string_view, TokenType> operator_umap;

    inline std::string_view operator_string = "=+-*/%<>!&|^@?$~:#();";

    inline operator_umap default_operator {
        {"=", TokenType::Assign},
        {"+", TokenType::Plus},
        {"-", TokenType::Minus},
        {"*", TokenType::Star},
        {"/", TokenType::Slash},
        {"(", TokenType::LParen},
        {")", TokenType::RParen},
        {";", TokenType::SemiColon},
    };

    bool isOperatorChar(char c);
}


#endif //CETUSCOMPILER_DEFAULTOPERATORS_H
