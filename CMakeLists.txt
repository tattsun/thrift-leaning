cmake_minimum_required(VERSION 3.4)
project(thrift_learning)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        models/gen-cpp/Greeter.cpp
        models/gen-cpp/hello_constants.cpp
        models/gen-cpp/hello_types.cpp)
add_executable(thrift_learning ${SOURCE_FILES})
target_link_libraries(thrift_learning thrift)