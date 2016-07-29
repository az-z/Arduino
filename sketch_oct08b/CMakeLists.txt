cmake_minimum_required(VERSION 3.3)
project(sketch_oct08b)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    CMakeLists.txt
    sketch_oct08b.ino)

add_executable(sketch_oct08b ${SOURCE_FILES})