# TESTS
cmake_minimum_required(VERSION 3.10)

# bmath lib test
add_executable(bmath_tests bmath_test.cpp)
target_link_libraries(bmath_tests
                      PUBLIC baby_math
                      gtest_main)
# add_test(BMathTests bmath_tests)

# fraction lib test
add_executable(fraction_tests fraction_test.cpp)
target_link_libraries(fraction_tests
                      PUBLIC fraction
                      PUBLIC baby_math
                      gtest_main)
# add_test(FractionTests fraction_tests)


include(GoogleTest)
gtest_discover_tests(bmath_tests)
gtest_discover_tests(fraction_tests)