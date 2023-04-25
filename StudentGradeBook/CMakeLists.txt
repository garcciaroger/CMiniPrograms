cmake_minimum_required(VERSION 3.25)
project(StudentGradeBook)

set(CMAKE_CXX_STANDARD 17)

add_executable(StudentGradeBook main.cpp StudentClass.cpp StudentClass.h)
