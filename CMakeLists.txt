cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(hash_table ExtensibleHashTable.cpp Bucket.cpp Bucket.h ExtensibleHashTable.h main.cpp)
