cmake_minimum_required(VERSION 3.10)
project(jsonApp LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable
add_executable(gunittest
    main.cpp
    ../myApp/myApp.cpp
    ../../../Lib/log.cpp
    ../../googletest-1.17.0/gtest.cc
    ../../googletest-1.17.0/gtest_main.cc
    ../../googletest-1.17.0/gtest-assertion-result.cc
    ../../googletest-1.17.0/gtest-death-test.cc
    ../../googletest-1.17.0/gtest-filepath.cc
    ../../googletest-1.17.0/gtest-matchers.cc
    ../../googletest-1.17.0/gtest-port.cc
    ../../googletest-1.17.0/gtest-printers.cc
    ../../googletest-1.17.0/gtest-test-part.cc
    ../../googletest-1.17.0/gtest-typed-test.cc
)

# Add include directory for headers
target_include_directories(gunittest PRIVATE ../../../Lib ../myApp ../../googletest-1.17.0/googletest ../../googletest-1.17.0/googletest/include)

# Explicitly link stdc++
target_link_libraries(gunittest PRIVATE stdc++)
