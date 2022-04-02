cmake_minimum_required(VERSION 3.21)

GET_FILENAME_COMPONENT(dir ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project(${dir})

add_executable(${dir} main.cpp)
