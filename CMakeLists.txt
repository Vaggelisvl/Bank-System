cmake_minimum_required(VERSION 3.22)
project(Banking_System)

set(CMAKE_CXX_STANDARD 23)

add_executable(Banking_System main.cpp Person_Details.cpp Person_Details.h Structs.cpp Structs.h Bank_System.cpp Bank_System.h)
