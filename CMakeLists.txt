cmake_minimum_required(VERSION 3.17)
project(demineur)

set(CMAKE_CXX_STANDARD 14)

add_executable(demineur main.cpp header/fonction.h source/fonction.cpp source/test.cpp header/test.h header/helper.h source/helper.cpp header/structure.h)