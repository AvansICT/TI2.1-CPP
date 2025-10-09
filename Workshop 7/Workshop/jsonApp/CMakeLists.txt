cmake_minimum_required(VERSION 3.10)
project(jsonApp)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# nlohmann/json kan via package manager of via single header
find_package(nlohmann_json 3.12.0 REQUIRED)

# Add the executable
add_executable(main.cpp
    ../Lib/log.cpp
)

# Add include directory for headers
target_include_directories(jsonApp PRIVATE ../Lib)

# Explicitly link stdc++ and nlohmann_json
target_link_libraries(jsonApp PRIVATE stdc++ nlohmann_json::nlohmann_json)
