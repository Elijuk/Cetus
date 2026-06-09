#ifndef PRIVATE_PROJECTS_LEXER_H
#define PRIVATE_PROJECTS_LEXER_H

#include "Token.h"
#include "Keywords.h"

#include <string_view>

/// EOF value '\0'
inline constexpr char EOF_v = '\0';

/// creates tokens out of the input file
class Lexer {
public:
    /// Constructors the Lexer class
    /// @param file_data: The data that would be read from
    Lexer(std::string_view file_data);

    /// Creates from the file data a vector of tokens
    /// @return a vector of tokens
    [[nodiscard]] const tokens_vector& tokenize();

protected:
    /// reads and creates an identifier token
    void readIdentifier();

    /// reads all the operators symbols
    void readOperator();

    /// reads an integer until it can't any more
    /// and adds a Int token to the tokens vector
    void readInt();             // TODO: change readInt to readNumber for both float/double and int

    /// Gets the character from the file
    /// @return a character in the string view or EOF if we reached the end
    char getChar();
    /// Peeks at the character without getting it
    /// @return a character in the string view or EOF if we reached the end
    char peekChar() const;

    /// Skips the single line comment
    /// that start with "//" untill it finds a new line.
    void skipSingleComment();
    /// Skips the multi line comment
    /// that starts with "/*" and ends with "*/"
    void skipMultiComment();

    /// skips all the whitespaces untill it finds a symbol or EOF
    void skipWhitespace();

private:
    tokens_vector m_tokens_vector;      ///< all the tokens that got generated
    std::string_view m_file_data;       ///< the data from a file loaded in memory
    size_t m_current_index = 0;         ///< the current index we're at in the file
    unsigned int m_current_line = 1;    ///< the current line in the file (for error management)
    unsigned int m_current_col = 1;     ///< the current column in the file (for error management)
};

#endif //PRIVATE_PROJECTS_LEXER_H