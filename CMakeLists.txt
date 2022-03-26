cmake_minimum_required(VERSION 3.21)
project(sha_collection)

set(CMAKE_CXX_STANDARD 14)

add_executable(sha_collection main.cpp sha1.h sha1.cpp hashtable.cpp sha256.h sha256.cpp md5.h md5.cpp)
