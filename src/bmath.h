#pragma once
#include <utility>		// std::pair
#include <iostream>		
#include <cmath>
#include <vector>		// std::vector
#include <map>			// std::map
#include <string>		// std::string
#include <limits>		// std::numeric_limits
//
// BASIC EVALUATIONS
//
namespace bmath
{
    // my basic math library
    // TODO: overload functions to take:
    // int
    // long long int
    // unsigned int
    // unsigned long long int
    
    int absolute(int n);
    unsigned int distance(int n1, int n2);
    
    uint64_t square(unsigned int n);
    int cube(int n);
    int64_t naive_power(int32_t base, uint32_t exponent);
    int64_t power(int32_t base, uint32_t exponent);
    int64_t iter_power(int32_t base, uint32_t exponent);
    double squared(double n);
    double cubed(double n);
    double powerd(double base, double number);
    double log(double base, double value);
    double sqrt(int n);
    double rsqrt(int n);
    double cbrt(double n);
    
    int factorial(int n);
    
    double average(std::vector<int> numbers);
    double average(std::vector<double> numbers);
    bool is_factor(int n, int of_n);
    std::vector<int> find_factors(int n);
    std::vector<int> common_factors(int n1, int n2);
    int gcf(int n1, int n2);
    int eucl_gcf(int n1, int n2);
    bool is_multiple(int n, int of_n);
    std::vector<int> common_multiples(int num1, int num2);
    int lcm(int num1, int num2);
    std::map<int, bool> sieve_of_eratosthenes_table(int n);
    std::map<int, bool> find_primes(int n);
    bool is_prime(int n);
    bool is_composite(int n);
    bool is_coprime(int n1, int n2);

}
