cmake_minimum_required(VERSION 3.4)
project(NumericalAnalysis)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories("${PROJECT_SOURCE_DIR}")
set(SOURCE_FILES question_three.cpp)
add_executable(NumAnalysis ${SOURCE_FILES})