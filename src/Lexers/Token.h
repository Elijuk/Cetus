#ifndef PRIVATE_PROJECTS_TOKEN_H
#define PRIVATE_PROJECTS_TOKEN_H

#include <string_view>
#include <vector>

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
    CustomOperator,
    Assign, Plus, Minus, Star, Slash,

    // selection
    If,
    ElseIf,
    Else,

    // iteration
    While,
    For,

    // groeping
    LParen, RParen,  ///< ( and )

    // special characters
    DoubleQuote,    ///< "
    SingleQuote,    ///< '
    SemiColon,      ///< ;
    Colon,          ///< :
    Comma,          ///< ,
    dot,            ///< .

    // System
    NewLine,        ///< /n
    EndOfFile,      ///< EOF
    Error,          ///< when we found a weird character
};

/// The tokens that are read from a file
struct Token {
    TokenType type;             ///< The type of token it is
    std::string_view value;     ///< The slice of text that was read
    unsigned int line;          ///< at what line did we find the token
    unsigned int col;           ///< at what column of the line did we find the token


    /// Creates a token object with the specified arguments
    /// @param type: the type of the token
    /// @param value: the value of the token
    /// @param line: at what line is the token
    /// @param col: at what column is the token
    static Token CreateToken(
        TokenType type,
        std::string_view value,
        unsigned int line, unsigned int col
        );
};

typedef std::vector<Token> tokens_vector;

#endif //PRIVATE_PROJECTS_TOKEN_H