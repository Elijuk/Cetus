# minimum cmake version 3.20 (good for c++17)
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

set(CETUS_CORE_SOURCES
        src/Lexers/lexer.cpp
        src/Lexers/Token.cpp
        src/Lexers/DefaultOperators.cpp
        src/Lexers/Keywords.h
        src/Lexers/Token.h
        src/Lexers/DefaultOperators.h
)

add_executable(Cetus "main.cpp" ${CETUS_CORE_SOURCES})

llvm_map_components_to_libnames(llvm_libs core support irreader target)
target_link_libraries(Cetus PRIVATE ${llvm_libs})

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(LexerTest Tests/Lexers/LexerTest.cpp ${CETUS_CORE_SOURCES})

target_link_libraries(LexerTest PRIVATE gtest_main)

add_test(NAME lexer_test COMMAND LexerTest)