# CMakeList.txt : CMake project for geom-modeling-test, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set (CMAKE_CXX_STANDARD 17)

project ("occt-tests")

if(WIN32)
	add_definitions(-DWIN32)
# APPLE is also one type of UNIX
elseif(APPLE)
	add_definitions(-DAPPLE)
elseif(UNIX)
	add_definitions(-DUNIX)
endif()

add_subdirectory ("geom")
