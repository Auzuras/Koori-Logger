cmake_minimum_required(VERSION 3.20)

project(KOORI_LOGGER LANGUAGES CXX)

option(KOORI_LOGGER_TEST_OPT "Build Koori Logger tests" ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(KooriLogger INTERFACE
        Include/Logger.h
        Include/Utils/LoggerTime.h
        Include/Exceptions/Exception.h
        Include/Exceptions/OutOfRangeException.h
        Include/Logging/LogChannels.h
        Include/Logging/Log.h
        Include/Macros/Assert.h
        Include/Logging/LogSeverity.h
        Include/Output/LogOutput.h
        Include/Output/FileOutput.h
        Include/Output/ConsoleOutput.h)

target_include_directories(KooriLogger INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include> $<INSTALL_INTERFACE:Include>)

if(KOORI_LOGGER_TEST_OPT)

    enable_testing()

    add_subdirectory(Tests)

endif()