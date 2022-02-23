# TESTS
cmake_minimum_required(VERSION 3.10)

# bmath lib test

add_executable(bmath_tests bmath_test.cpp)
target_link_directories(bmath_tests PUBLIC "../googletest/build/lib/")
target_include_directories(bmath_tests PUBLIC "../googletest/googletest/include/")
target_link_libraries(bmath_tests
                      PUBLIC baby_math
                      PUBLIC gtest_main
                      PUBLIC gtest)
                      
add_executable(bmath_fraction_tests fraction_test.cpp)
target_link_directories(bmath_fraction_tests PUBLIC "../googletest/build/lib/")
target_include_directories(bmath_fraction_tests PUBLIC "../googletest/googletest/include/")
target_link_libraries(bmath_fraction_tests
                      PUBLIC baby_math
                      PUBLIC gtest_main
                      PUBLIC gtest)
                      