cmake_minimum_required(VERSION 2.8.9)
project(directory_test)

include_directories(include)

#set(SOURCES src/mainapp.cpp src/Student.cpp)

file(GLOB SOURCES "src/*.cpp")

add_executable(testStudent ${SOURCES})
