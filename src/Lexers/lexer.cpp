#include "lexer.h"

#include "DefaultOperators.h"

#include <cctype>
#include <stdexcept>


Lexer::Lexer(const std::string_view file_data)
    : m_file_data(file_data){
}

const tokens_vector& Lexer::tokenize() {
    while (peekChar() != EOF_v) {
        skipWhitespace();

        const char c = peekChar();
        if (c == EOF_v) break;

        if (std::isalpha(c) || c == '_') {
            readIdentifier();
        }
        else if (std::isdigit(c)) {
            readInt();
        }
        else if (c == '/') {
            getChar();
            if (peekChar() == '/') {
                skipSingleComment();
            }
            else if (peekChar() == '*') {
                skipMultiComment();
            }
            else {
                // it was a devide operator
                m_tokens_vector.push_back(Token::CreateToken(
                   CetusOperator::default_operator["/"],
                   "/",
                   m_current_line,
                   m_current_col - 1
                ));
            }
        }
        else if (CetusOperator::isOperatorChar(c)) {
            readOperator();
        }
        else {
            // TODO: impement error manager/class for the lexer
            // this case it should be something like UnkownSymbol or something else
            throw std::runtime_error("Unkown symbol was read");
        }
    }

    m_tokens_vector.push_back(Token::CreateToken(TokenType::EndOfFile, "", m_current_line, m_current_col));

    return m_tokens_vector;
}

void Lexer::readIdentifier() {
    const size_t start_index = m_current_index;
    const unsigned int start_col = m_current_col;

    while (isalnum(peekChar()) || peekChar() == '_') {
        getChar();
    }

    const size_t length = m_current_index - start_index;
    const std::string_view value = m_file_data.substr(start_index, length);

    if (const auto it = all_keywords.find(value); it != all_keywords.end()) {
        m_tokens_vector.push_back(Token::CreateToken(
            it->second,
            value,
            m_current_line,
            start_col
        ));
    }
    else {
        m_tokens_vector.push_back(Token::CreateToken(
            TokenType::Identifier,
            value,
            m_current_line,
            start_col
        ));
    }
}

void Lexer::readOperator() {
    const size_t start_index = m_current_index;
    const unsigned int start_col = m_current_col;

    while (CetusOperator::isOperatorChar(peekChar())) {
        getChar();
    }

    const size_t length = m_current_index - start_index;
    const std::string_view value = m_file_data.substr(start_index, length);

    if (const auto it = CetusOperator::default_operator.find(value); it != CetusOperator::default_operator.end()) {
        m_tokens_vector.push_back(Token::CreateToken(
            it->second,
            value,
            m_current_line,
            start_col
        ));
    }
    else {
        m_tokens_vector.push_back(Token::CreateToken(
            TokenType::CustomOperator,
            value,
            m_current_line,
            start_col
        ));
    }
}

void Lexer::readInt() {
    const size_t start_index = m_current_index;
    const unsigned int start_col = m_current_col;

    while (std::isdigit(peekChar())) {
        getChar();
    }

    const size_t length = m_current_index - start_index;
    const std::string_view value = m_file_data.substr(start_index, length);

    m_tokens_vector.push_back(Token::CreateToken(
        TokenType::IntLiteral,
        value,
        m_current_line,
        start_col
    ));
}

char Lexer::getChar() {
    const char c = peekChar();
    if (c != EOF_v) {
        ++m_current_index;
        ++m_current_col;

        if (c == '\n') {
            ++m_current_line;
            m_current_col = 1;
        }
    }
    return c;
}

char Lexer::peekChar() const {
    if (m_current_index >= m_file_data.size()) {
        return EOF_v;        // Reached end of line
    }
    return m_file_data[m_current_index];
}

void Lexer::skipSingleComment() {
    while (true) {
        char c = getChar();
        if (c == '\n' || c == EOF_v) {
            break;  // reached the end of the comment
        }
    }
}

void Lexer::skipMultiComment() {
    while (true) {
        char c = getChar();
        if (c == EOF_v) {
            break;      // reached the end of the comment
        }
        if (c == '*' && peekChar() == '/') {
            getChar();  // go to the '/' part
            break;      // reached the end of the comment
        }
    }
}

void Lexer::skipWhitespace() {
    while (true) {
        char c =  peekChar();
        if (c != EOF_v && std::isspace(c)) {
            getChar();
            continue;
        }
        break;
    }
}