# requirements
cmake_minimum_required(VERSION 3.10)

# project configuration
set(this BabyMath)
project(${this}
        VERSION 0.1.0
        LANGUAGES CXX)
configure_file(BabyMathConfig.h.in BabyMathConfig.h)
# cpp standard and compile flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# project generated libs
add_library(baby_math
            src/bmath.cpp
            src/bmath.h)
add_library(fraction
            src/fraction.cpp
            src/fraction.h)

# main to manual test and debugging
add_executable(main src/main.cpp)
target_link_libraries(main PUBLIC baby_math)
add_custom_target(run
                  COMMAND main
                  DEPENDS main
                  WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

# add gtest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/master.zip
)
if(MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()
FetchContent_MakeAvailable(googletest)

enable_testing()
# test targets
add_subdirectory(tests)
