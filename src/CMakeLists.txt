cmake_minimum_required( VERSION 3.28 )
project( banksystem-src LANGUAGES CXX )

include_directories( ../headers )

file( GLOB_RECURSE srcs ./**.cpp )
add_executable( main ${srcs} )