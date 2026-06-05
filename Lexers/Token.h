#ifndef PRIVATE_PROJECTS_TOKEN_H
#define PRIVATE_PROJECTS_TOKEN_H

/// All the tokenTypes and acceptable syntax
enum class TokenType {
    // Data
    Identifier,
    IntLiteral,

    // Types
    Int,
    Double,
    Float,
    String,
    Char,
    Bool,
        True, False,
    Var,

    // function types
    Void,
    Return,

    // Operators
    Assign, Plus, Minus, Star, Slash,

    // selection
    If,
    ElseIf,
    Else,

    // iteration
    While,
    For,

    // groeping
    LParen, RPAren,  ///< ( and )

    // special characters
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