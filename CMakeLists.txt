cmake_minimum_required(VERSION 3.21)
project(stadium_tracker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SQLite3 REQUIRED)

add_executable(stadium_tracker src/main.cpp src/Database.cpp)
target_include_directories(stadium_tracker PRIVATE include)
target_link_libraries(stadium_tracker PRIVATE SQLite3::SQLite3)
