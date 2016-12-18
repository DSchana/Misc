cmake_minimum_required(VERSION 2.8)

project(Carm)

file(GLOB_RECURSE Carm_SOURCES "source/*.cpp")
file(GLOB_RECURSE Carm_HEADERS "source/*.h")

set(Carm_INCLUDE_DIRS "")
foreach(_headerFile ${Carm_HEADERS})
	get_filename_component(_dir ${_headerFile} PATH)
	list(APPEND Carm_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Carm_INCLUDE_DIRS)

include_directories(${Carm_INCLUDE_DIRS})
add_executable(Carm ${Carm_SOURCES})
