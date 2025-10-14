cmake_minimum_required(VERSION 3.10)
project(udpclient LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable
add_executable(udpclient
    main.cpp
    ../../../Lib/log.cpp
)

# Add include directory for headers
target_include_directories(udpclient PRIVATE ../../../Lib)

# Explicitly link stdc++
target_link_libraries(udpclient PRIVATE stdc++)
