cmake_minimum_required(VERSION 3.10)
project(openmpfibonacci LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable
add_executable(openmpfibonacci
    main.cpp
    ../Lib/log.cpp
    ../Lib/openmptimer.cpp
    ../Lib/linuxtimer.cpp
)

# Add include directory for headers
target_include_directories(openmpfibonacci PRIVATE ../Lib)

# Explicitly link stdc++
target_link_libraries(openmpfibonacci PRIVATE stdc++)
