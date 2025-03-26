cmake_minimum_required(VERSION 3.27)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++ -lpthread")


project(dn1)

set(CMAKE_CXX_STANDARD 17)

add_executable(dn1 main.cpp)
