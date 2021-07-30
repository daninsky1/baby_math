#pragma once

#include <utility>		// std::pair
#include <iostream>		
#include <cmath>
#include <vector>		// std::vector
#include <map>			// std::map
#include <string>		// std::string
#include <climits>
#include <exception>
#include <bit>
#include <algorithm>
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
    
    uint64_t absolute(int64_t n);
    uint64_t distance(int64_t n1, int64_t n2);
    
    uint64_t square(int64_t base);
    int64_t cube(int32_t base);
    int64_t naive_power(int32_t base, uint32_t exponent);
    int64_t power(int32_t base, uint32_t exponent);
    int64_t iter_power(int32_t base, uint32_t exponent);
    
    
    
    
    double squared(double n);
    double cubed(double n);
    double powerd(double base, double number);
    double log(double base, double value);
    double sqrt(int radicand);
    double rsqrt(int radicand);
    double cbrt(double radicand);
    double radix(int index, int radicand);
    uint64_t factorial(unsigned int n);
    bool is_factor(int n, int of_n);
    std::vector<int> find_factors(int n);
    std::vector<int> common_factors(int n1, int n2);
    bool is_multiple(int n, int of_n);
    std::vector<int> common_multiples(int num1, int num2);
    int eucl_gcf(int n1, int n2);
    int gcf(int n1, int n2);
    int lcm(int num1, int num2);
    std::map<int, bool> sieve_of_eratosthenes_table(int n);
    std::map<int, bool> find_primes(int n);
    bool is_prime(int n);
    bool is_composite(int n);
    bool is_coprime(int n1, int n2);
    template<class ... Ts>
    double average(Ts ... args);

}   // namespace bmath

// TODO: use template parameter pack for
// that can possibly have variable number of inputs such average


// AVERAGE
inline double average_impl(int& count, double& sum) { return sum / count; }

template<class Head, class ... Tail>
double average_impl(int& count, double& sum, const Head& head, const Tail& ...tail)
{
    sum += head;
    count++;
    average_impl(count, sum, tail...);
}

template<class ... Ts>
double bmath::average(Ts ... args)
{
    // TODO: add test to average
    double sum = 0;
    int count = 0;
    return average_impl(count, sum, args...);
}

// 