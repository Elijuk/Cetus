//
// Created by Elias on 04/06/2026.
//

#ifndef PRIVATE_PROJECTS_TOKEN_H
#define PRIVATE_PROJECTS_TOKEN_H

/// All the tokenTypes and acceptable syntax
enum class TokenType {
    // Data
    Identifier,
    IntLiteral,

    // Types
    Int,

    // Operators
    Assign, Plus, Minus, Star, Slash,

    // groeping
    LParen, RPAren,  ///< ( and )

    SemiColon,
    Colon,
    Comma,

    // System
    NewLine,
    EndOfLine,
    Error,
};

/// The tokens that are read from a file
struct Token {
    TokenType type;             ///< The type of token it is
    const char* value;          ///< The value that was read
    unsigned int line;          ///< at what line did we find the token
    unsigned int col;           ///< at what column of the line did we find the token
};


#endif //PRIVATE_PROJECTS_TOKEN_H