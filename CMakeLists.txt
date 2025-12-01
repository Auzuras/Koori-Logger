cmake_minimum_required(VERSION 3.20)

project(KOORI_LOGGER LANGUAGES CXX)

option(KOORI_LOGGER_TEST_OPT "Build Koori Logger tests" ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE KOORI_LOGGER_SOURCES "Source/*.cpp")

add_library(KooriLogger STATIC ${KOORI_LOGGER_SOURCES}
        Source/Logger.cpp
        Source/Output/ConsoleOutput.cpp
        Source/Output/FileOutput.cpp)

target_include_directories(KooriLogger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include)

if(KOORI_LOGGER_TEST_OPT)

    enable_testing()

    add_subdirectory(Tests)

endif()