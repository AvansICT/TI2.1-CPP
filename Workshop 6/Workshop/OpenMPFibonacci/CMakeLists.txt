cmake_minimum_required(VERSION 3.10)
project(openmpfibonacci LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenMP
find_package(OpenMP REQUIRED)

# Add the executable
add_executable(openmpfibonacci
    main.cpp
    ../../../Lib/log.cpp
    ../../../Lib/omptimer.cpp
    ../../../Lib/linuxtimer.cpp
)

# Add include directory for headers
target_include_directories(openmpfibonacci PRIVATE ../../../Lib)

# Explicitly link stdc++ and OpenMP
target_link_libraries(openmpfibonacci PRIVATE stdc++ OpenMP::OpenMP_CXX)
