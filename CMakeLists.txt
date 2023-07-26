cmake_minimum_required(VERSION 2.8.9)
project(acm)

include_directories(include)

#set(SOURCES src/mainapp.cpp src/Student.cpp)

file(GLOB SOURCES "src/*.cpp")
  include(CheckIncludeFiles)
  check_include_files(xcb/xcb.h HAVE_XCB_XLIB_H)



set(CLIP_SOURCES lib/clip.cpp)

if(HAVE_XCB_XLIB_H)
    add_definitions(-DHAVE_XCB_XLIB_H)

    list(APPEND CLIP_SOURCES lib/clip_x11.cpp)

endif()

add_library(clip ${CLIP_SOURCES})

if(HAVE_XCB_XLIB_H)
    target_link_libraries(clip xcb pthread)
endif()

add_executable(acm ${SOURCES})
target_link_libraries(acm clip)
target_include_directories(acm PUBLIC lib)