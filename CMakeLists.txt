cmake_minimum_required( VERSION 3.28 )

project( banksystem LANGUAGES CXX )

set( CXX_STANDARD_REQUIRED 23 )
set( CMAKE_CXX_STANDARD 23 )
set( CMAKE_CXX_STANDARD_REQUIRED 23 )

add_subdirectory(src)
add_subdirectory(test)