# minimum cmake version 3.22 (good for c++17)
cmake_minimum_required(VERSION 3.22)

# Cetus compiler uses c++
project(CetusCompiler CXX)

# minimum standard c++ version 17 is required!!!!
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# LLVM is required to be on the pc so it can compile properly
find_package(LLVM CONFIG QUIET)

# case if we don't find the package -> send message how to install it
if (NOT LLVM_FOUND)
    message(FATAL_ERROR
            "\n"
            "ERROR: LLVM developer library was not found, please run/do the following depending on your operating system: "
            "\n"
            "+ mac: brew install llvm                   \n"
            "+ unix: sudo apt install llvm-dev          \n"
            "+ win: download installer from github      \n"
    )
endif ()

# case if we found it -> send message -> include + link it
message(STATUS "SUCCESS: Found LLVM version ${LLVM_PACKAGE_VERSION}")
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_INCLUDE_DIRS})

# Cetus executable
add_executable(Cetus "main.cpp"

)

# links LLVMCore to Cetus
target_link_libraries(Cetus PRIVATE LLVMCore)