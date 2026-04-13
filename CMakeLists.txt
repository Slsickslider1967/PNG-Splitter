cmake_minimum_required(VERSION 3.10)

project(PNG_Splitter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include(FetchContent)

FetchContent_Declare(
	stb
	GIT_REPOSITORY https://github.com/nothings/stb.git
	GIT_TAG master
)
FetchContent_MakeAvailable(stb)

add_executable(PNG_Splitter
	src/main.cpp
)

target_include_directories(PNG_Splitter PRIVATE
	src/include
	${stb_SOURCE_DIR}
)
