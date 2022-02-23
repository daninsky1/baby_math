# TESTS
cmake_minimum_required(VERSION 3.10)

# bmath lib test
add_executable(bmath_tests bmath_test.cpp)
target_link_libraries(bmath_tests
                      PUBLIC baby_math
                      gtest_main)
add_executable(bmath_fraction_tests fraction_test.cpp)
target_link_libraries(bmath_fraction_tests
                      PUBLIC baby_math
                      gtest_main)
                      
# add_test(BMathTests bmath_tests)

include(GoogleTest)

gtest_add_tests(TARGET bmath_tests)
gtest_add_tests(TARGET bmath_frction_tests)
