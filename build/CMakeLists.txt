cmake_minimum_required(VERSION 3.20.0)
project(kawaiiclip VERSION 1.0.0)

set (CMAKE_CXX_STANDARD_REQUIRED 20)
set (CMAKE_CXX_STANDARD 20)

set (FullOutputDir "${CMAKE_SOURCE_DIR}/output/${CMAKE_BUILD_TYPE}")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/static libs")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")

include_directories(./src)

add_executable(${PROJECT_NAME} ./src/main.cpp)
