cmake_minimum_required(VERSION 2.8.9)
project(acm)

include_directories(include)

#set(SOURCES src/mainapp.cpp src/Student.cpp)

file(GLOB SOURCES "src/*.cpp")

add_executable(acm ${SOURCES})
