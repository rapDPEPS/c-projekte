cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_COMPILER "C:/mingw64/bin/gcc.exe" CACHE FILEPATH "C compiler")
set(CMAKE_CXX_COMPILER "C:/mingw64/bin/g++.exe" CACHE FILEPATH "C++ compiler")
project(CProjects C)

set(CMAKE_C_STANDARD 17)

#add_executable(helloWorld helloWorld.c)
#add_executable(RockPaperScissor RockPaperScissor.c)
add_executable(DynamicMemory dynamicMemory.c readFunctions.c)
#add_executable(StructTest structTest.c readFunctions.c)
