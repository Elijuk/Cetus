#include "token.h"

Token Token::CreateToken(
    const TokenType type,
    const std::string_view value,
    const unsigned int line, const unsigned int col
    ) {
    return {type, value, line, col};
}