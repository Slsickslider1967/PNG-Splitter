cmake_minimum_required(VERSION 3.10)

project(PNG_Splitter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(PNG_Splitter
	src/main.cpp
)

target_include_directories(PNG_Splitter PRIVATE
	src/include
)
