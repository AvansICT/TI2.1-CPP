cmake_minimum_required(VERSION 3.10)
project(MyApp LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable
add_executable(MyApp src/main.cpp)

# Explicitly link stdc++
target_link_libraries(MyApp PRIVATE stdc++)