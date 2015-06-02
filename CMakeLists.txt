cmake_minimum_required(VERSION 3.2)
project(Coursework)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Coursework ${SOURCE_FILES} main.h Models/Controller.cpp Models/Controller.h Helpers.h Helpers.cpp Models/Item.cpp Models/Item.h Models/Items.cpp Models/Items.h)