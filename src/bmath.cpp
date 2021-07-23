#include "bmath.h"
// TODO: is_positive, is_negative, is_even, is_odd
//
// BASIC EVALUATIONS
//

//
// 
//
long long bmath::distance(long long n1, long long n2)
{
    // calculate the distance between two numbers
    return std::abs(n1 - n2);
}

long long bmath::absolute(long long n, bool bitmask = false)
{
    // return the absolute value of a number
    if (bitmask) {
        // TODO: bitmask equivalent
        if (n < 0)
            return (-1) * n;
        else
            return n;
    }
    else {
        if (n < 0)
            return (-1) * n;
        else
            return n;
    }
}
//
// AVERAGE NUMBERS
//
double bmath::average(std::vector<int> numbers)
{
    std::vector<double> d_vector;
    for (int i = 0; i < numbers.size(); ++i)
        d_vector.push_back((double)numbers[i]);
    return bmath::average(d_vector);
}

double bmath::average(std::vector<double> numbers)
{
    double sum = 0;
    size_t n_size = numbers.size();
    for (int i = 0; i < n_size; ++i) {
        sum += numbers[i];
    }
    return sum / n_size;
}
//
// FACTORING
//
bool bmath::is_factor(int n, int of_n)
{
    // n is a factor of of_n
    if (of_n % n == 0) return true;
    else return false;
}

std::vector<int> bmath::find_factors(int n)
{
    // find all positive factor of a number
    std::vector<int> factors;
    for (int i = 1; i <= n; ++i)
        if (bmath::is_factor(i, n)) factors.push_back(i);
    return factors;
}

// TODO: implement a common_factors with multiple arguments entry or vector
std::vector<int> bmath::common_factors(int n1, int n2)
{
    std::vector<int> n1_fac = bmath::find_factors(n1);
    std::vector<int> n2_fac = bmath::find_factors(n2);
    std::vector<int> common_factors;
    for (int x : n1_fac)
        for (int y : n2_fac)
            if (x == y) common_factors.push_back(x);
    return common_factors;
}

// TODO: implement a gcf with multiple arguments entry or vector
int bmath::gcf(int n1, int n2)
{
    std::vector<int> common_factor = bmath::common_factors(n1, n2);
    return common_factor[common_factor.size() - 1];
}
int bmath::eucl_gcf(int n1, int n2)
{
    // euclid's algorithm implementation to find the greatest common factor
    if (n1 == n2) return n1;
    while (true) {
        if (n1 > n2) n1 -= n2;
        else if (n1 < n2) n2 -= n1;
        else return n1;
    }
}
//
// MULTIPLES
//
bool bmath::is_multiple(int n, int of_n)
{
    // n is a multiple of of_n
    // a multiple number1 of number2 == a factor number2 of number1
    if (of_n > n) return false;
    if (n % of_n == 0) return true;
    else return false;
}

// TODO: implement a common_multiples with multiple arguments entry or vector
std::vector<int> bmath::common_multiples(int num1, int num2)
{
    return std::vector<int>();
}

// TODO: implement a lcm with multiple arguments entry or vector
int bmath::lcm(int num1, int num2)
{
    // least common multiple of a pair of number
    int mult1 = num1;
    int mult2 = num2;
    while (true) {
        if (mult1 < mult2) mult1 += num1;
        else mult2 += num2;
        if (mult1 == mult2) return mult1;
    }
}
//
// PRIME NUMBERS
//
std::map<int, bool> bmath::sieve_of_eratosthenes_table(int n)
{
    // makes a map of prime numbers until n
    std::map<int, bool> table;
    // init table with 2 to n all set to true
    for (int i = 2; i <= n; ++i) table[i] = true;
    double sqrt_n = sqrtf(static_cast<float>(n));		// not exceeding sqrt(n)
    for (int i = 2; i <= sqrt_n; ++i) {
        if (table[i]) {
            for (int j = 0; i < n; ++j) {
                int i_square = static_cast<int>(pow(i, 2));		// double cannot exceed int
                int nonp_index = i_square + j * i;		// non-prime index
                if (nonp_index > n) break;				// if exceed n numbers break
                table[nonp_index] = false;
            }
        }
    }
    return table;
}

std::map<int, bool> bmath::find_primes(int n)
{
    // makes a map of prime numbers until n
    return sieve_of_eratosthenes_table(n);
}

bool bmath::is_prime(int n)
{
    switch (n) {
    case 1:
        return false;
        break;
    case 2:
        return true;
        break;
    default: {
        std::map<int, bool> table = sieve_of_eratosthenes_table(n);
        return table[n];
    }
    }
}

bool bmath::is_composite(int n)
{
    // composite is a non-prime number
    return !bmath::is_prime(n);
}

bool bmath::is_coprime(int n1, int n2)
{
    // coprime is a relatively prime
    if (bmath::gcf(n1, n2) == 1) return true;
    else return false;
}
double bmath::square(double n)
{
    return n * n;
}
double bmath::cube(double n)
{
    return n * n * n;
}
double bmath::power(double base, double expo)
{
    double temp = base;
    for (int i = 1; i < expo; ++i) temp *= base;
    return temp;
}
