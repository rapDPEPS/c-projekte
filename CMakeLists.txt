cmake_minimum_required(VERSION 3.10)
project(MinimalCMake)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

add_executable(MinimalCMake helloWorld.c)
add_executable(RockPaperScissor RockPaperScissor.c)
#add_executable(Snake Snake.c)

#add_executable(MultipleFiles a.c b.c)

add_executable(StructTest structTest.c)
add_executable(DynamicMemory dynamicMemory.c)