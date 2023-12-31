cmake_minimum_required(VERSION 3.27)
project(RawSocketsChat)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCE_FILES src/*.cpp src/*.h)
file(GLOB_RECURSE SOURCE_SERVER src/server/*.cpp src/server/*.h ${SOURCE_FILES})
file(GLOB_RECURSE SOURCE_CLIENT src/client/*.cpp src/client/*.h ${SOURCE_FILES})

add_executable(ChatServer ${SOURCE_SERVER})
add_executable(ChatClient ${SOURCE_CLIENT})
