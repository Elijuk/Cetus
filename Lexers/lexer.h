#ifndef PRIVATE_PROJECTS_LEXER_H
#define PRIVATE_PROJECTS_LEXER_H

#include <string>
#include <vector>

class Lexer {
public:
    Lexer(const char* file_data);
private:
    const char* m_file_data;
    unsigned int m_current_line = 1;
    unsigned int m_current_col = 1;
};

#endif //PRIVATE_PROJECTS_LEXER_H