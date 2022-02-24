#include "bmath.h"

// TODO: is_positive, is_negative, is_even, is_odd
// TODO: substitute vector parameter to any iterable container
// and add function overload to accept variable args
using namespace bmath;

uint64_t bmath::absolute(int64_t n)
{
    if (n == INT64_MIN)
        return static_cast<uint64_t>(n);
    int64_t sign_mak = n >> (sizeof(int64_t)*CHAR_BIT - 1);
    int64_t result = (sign_mak + n)^sign_mak;
    return result;
}

int64_t bmath::inverse(int64_t n)
{
    // Two's complement inverse function
    // The inversion of a number can be achieved mathematically by multiplying
    // a integer number by -1;
    if (n == INT64_MIN || n == 0)
        return 0;
    return (~n)+1;
}

int sign(int64_t n)
{
    if (n > 0) return 1;
    else if (n < 0) return -1;
    else return 0;
}

uint64_t bmath::distance(int64_t n1, int64_t n2)
{
    uint64_t result = 0;
    if (sign(n1) != 0 && sign(n1) != sign(n2)) {
        uint64_t lln1 = 0;
        uint64_t lln2 = 0;
        lln1 = absolute(n1);
        lln2 = absolute(n2);
        result = lln1 + lln2;
        return result;
    }
    else {
        result = absolute(n1 - n2);
        return result;
    }
}
/*
* POTENTIATION AND DIVISIBILITY
*/
uint64_t bmath::square(int64_t base)
{
    constexpr int64_t NUINT32_RANGE = static_cast<int64_t>(UINT32_MAX)*-1; // "negative" 32 uint range size
    if (base > UINT32_MAX || base < NUINT32_RANGE)
        throw std::range_error("Cannot compute more than 4294967295 negative or positive.");
    uint64_t result = static_cast<uint64_t>(base);
    result*=result;
    return result;
}

int64_t bmath::cube(int32_t base)
{
    static constexpr int CB_PMAX_INDEX = 2'097'151;     // positive max
    static constexpr int CB_NMAX_INDEX = -2'097'152;     // negative max
    if (base > CB_PMAX_INDEX || base < CB_NMAX_INDEX) throw std::range_error("Overflow.");
    int64_t result = static_cast<int64_t>(base);
    result = result*result*result;
    return result;
}

int64_t bmath::naive_power(int32_t base, uint32_t exponent)
{
    // brute-force power
    if (!exponent) return 1;    // exponent == 0
    if (exponent == 1) return base;
    int64_t result = base;
    for (uint32_t i = 1; i < exponent; ++i) result *= base;
    return result;
}

int64_t bmath::power(int32_t base, uint32_t exponent)
{
    // binary power
    // only positive exponent are suported
    if (!exponent) return 1;    // exponent == 0
    if (exponent == 1) return base;
    int64_t temp = power(base, exponent / 2);
    int64_t result = temp * temp;
    if (exponent % 2) result *= base;
    return result;
}
int64_t bmath::iter_power(int32_t base, uint32_t exponent)
{
    // iteration power
    int64_t result = 1;
    while (exponent) {
        if (exponent%2 ) result *= base;
        base *= base;
        exponent /= 2;
    }
    return result;
}

// TODO: add error checking in double implementations of square, cube and po
double bmath::squared(double n)
{
    return n*n;
}

double bmath::cubed(double n)
{
    return n*n*n;
}

double bmath::powerd(double base, double exponent)
{
    double temp = base;
    if (exponent < 1)
        for (double i = exponent; i > 1; i+=i) temp *= base;
    else 
        for (unsigned int i = 1; i < exponent; ++i) temp *= base;
    return temp;
}

double bmath::log(double base, double value)
{
    // TODO: Implement this logarithm
    if (base == 0.0) return 0;
    else if (base < 0) throw std::invalid_argument("");
}

double bmath::sqrt(int radicand)
{
    // Heron's method square root 
    if (radicand < 1) throw std::range_error("Must be a non-zero positive number >= 1.");
    // first number, second squared number
    std::pair<int, int> min_guess{0, 0};
    std::pair<int, int> max_guess{0, 0};
    int i = 1;
    int sq;
    while (true) {
        sq = square(i);
        if (sq < radicand) {
            min_guess.first = i;
            min_guess.second = sq;
        }
        else if (sq > radicand) {
            max_guess.first = i;
            max_guess.second = sq;
            break;
        }
        else return i;
        ++i;
    }
    
    std::pair<int, int> closest_guess{0, 0};
    if (distance(min_guess.second, radicand) < distance(max_guess.second, radicand)) 
        closest_guess = min_guess;
    else
        closest_guess = max_guess;
        
    double a = static_cast<double>(closest_guess.first);

    constexpr int iter = 4;
    constexpr double half = 0.5;
    double result = 0;
    
    for (int i = 0; i < iter; ++i) {
        result = half*(a+radicand/a);
        a = result;
    }
    
    return result;
}

// TODO: implement reciprocal square root
double bmath::rsqrt(int radicand) { return 0.0; }

// TODO: implement cubic root
double bmath::cbrt(double radicand)
{
    return 0.0;
}
// TODO: implement root of nth number
double bmath::radix(int index, int radicand) { return 0.0; }

// TODO: implement factorial
uint64_t bmath::factorial(unsigned int n)
{
    if (n == 0) return 1;
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
        if (is_factor(i, n)) factors.push_back(i);
    return factors;
}

// TODO: implement a common_factors with multiple arguments entry or vector
std::vector<int> bmath::common_factors(int n1, int n2)
{
    std::vector<int> n1_fac = find_factors(n1);
    std::vector<int> n2_fac = find_factors(n2);
    std::vector<int> common_factors;
    for (int x : n1_fac)
        for (int y : n2_fac)
            if (x == y) common_factors.push_back(x);
    return common_factors;
}

// TODO: implement a gcf with multiple arguments entry or vector
int bmath::gcf(int n1, int n2)
{
    std::vector<int> common_factor = common_factors(n1, n2);
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

bool bmath::is_composite(int n) { return !is_prime(n); }
bool bmath::is_coprime(int n1, int n2) { return gcf(n1, n2); }

