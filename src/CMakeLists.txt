cmake_minimum_required( VERSION 3.28 )
project( banksystem-src LANGUAGES CXX )

include_directories( ../headers )

set( CMAKE_CXX_STANDARD_REQUIRED 23 )
set( CMAKE_CXX_STANDARD 23 )
set( CXX_STANDARD_REQUIRED 23 )

file( GLOB_RECURSE srcs ./**.cpp )