cmake_minimum_required(VERSION 3.15)
project(Translator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Translator main.cpp Translate.h Translate.cpp Command.h Command.cpp)