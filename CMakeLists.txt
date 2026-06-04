# minimum cmake version 3.22 (good for c++17)
cmake_minimum_required(VERSION 3.20.0)

# Cetus compiler uses c++
project(CetusCompiler CXX)

# minimum standard c++ version 17 is required!!!!
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# LLVM is required to be on the pc so it can compile properly


# Cetus executable
add_executable(Cetus "main.cpp"
        Lexers/lexer.cpp
)