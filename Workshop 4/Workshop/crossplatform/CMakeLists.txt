cmake_minimum_required(VERSION 3.10)
project(MyProject LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable
add_executable(MyProject src/main.cpp)