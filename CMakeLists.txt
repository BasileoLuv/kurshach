cmake_minimum_required(VERSION 3.16)
project(bas)

set(CMAKE_CXX_STANDARD 14)

add_executable(bas main.cpp List.cpp MyString.cpp Node.cpp Reader.cpp)