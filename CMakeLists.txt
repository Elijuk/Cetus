# minimum cmake version 3.22 (good for c++17)
cmake_minimum_required(VERSION 3.20.0)

# Cetus compiler uses c++
project(CetusCompiler CXX)

# minimum standard c++ version 17 is required!!!!
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# LLVM is required to be on the pc so it can compile properly
set(LLVM_DIR "llvm-project/build/lib/cmake/llvm")

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Cetus executable
add_executable(Cetus "main.cpp"
        Lexers/Keywords.h
        Lexers/Token.h
        Lexers/lexer.cpp
)

llvm_map_components_to_libnames(llvm_libs core support irreader target)
target_link_libraries(Cetus PRIVATE ${llvm_libs})