#include "DefaultOperators.h"

namespace CetusOperator {

    bool isOperatorChar(const char c) {
        return operator_string.find(c) != std::string_view::npos;
    }

}