cmake_minimum_required( VERSION 3.28 )

project( banksystem LANGUAGES CXX )

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_STANDARD_REQUIRED 23)

include_directories(headers)

add_subdirectory(src)
add_subdirectory(test)

file(GLOB_RECURSE SOURCE_FILES src/**.cpp)

add_executable(banksystem banksystem.cpp ${SOURCE_FILES})