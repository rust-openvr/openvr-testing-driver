cmake_minimum_required(VERSION 3.3)
project(openvr_testing_driver C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(
        include/
        test_cases/)

set(SOURCE_FILES
    include/case.h
    include/factory.h
    include/registry.h
    include/service.h
    include/hooks.h
    include/driver.h
    include/autoloader.x.h
    test_cases/01_basic_tracking/basic_tracking.h
    src/lib.cpp)

add_executable(openvr_testing_driver ${SOURCE_FILES})