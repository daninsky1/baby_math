# requirements
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(BabyMath VERSION 0.1.0)

add_library(${PROJECT_NAME}
    src/bmath.cpp
    src/bmath.h
)

add_executable(BMathTest src/main.cpp)
configure_file(BabyMathConfig.h.in BabyMathConfig.h)
target_include_directories(BMathTest PUBLIC "${PROJECT_BINARY}")


target_link_libraries(BMathTest PUBLIC ${PROJECT_NAME})