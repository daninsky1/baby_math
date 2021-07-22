#pragma once
#include <utility>		// std::pair
#include <iostream>		
#include <cmath>
#include <vector>		// std::vector
#include <map>			// std::map
#include <string>		// std::string
#include <limits>		// std::numeric_limits


namespace bmath
{
    // my basic math library
    // TODO: overload functions to take:
    // int
    // long long int
    // unsigned int
    // unsigned long long int
    
    long long distance(long long n1, long long n2);
    long long absolute(long long n, bool bitmask);
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
    double square(double n);
    double cube(double n);
    double power(double base, double expo);


    class Fraction {
    private:
        std::pair<Fraction, Fraction> make_equiv(Fraction other) const;
        void update();		// update m_decimal whenever the class get a change
    public:
        int m_numerator;
        int m_denominator;
        int m_mixed_num;
        double m_decimal;
        Fraction(int numerator, int denominator, int mixed_num = 0);
        // arithmetic
        Fraction add(Fraction other) const;
        Fraction sub(Fraction other) const;
        Fraction mult(Fraction other) const;
        Fraction cross_mult(Fraction other) const;
        Fraction div(Fraction other) const;
        Fraction operator+(Fraction other) const;
        Fraction operator-(Fraction other) const;
        Fraction operator*(Fraction other) const;
        Fraction operator/(Fraction other) const;
        // logical
        bool is_gtr(Fraction other) const;
        bool is_gtr_or_eq(Fraction other) const;
        bool is_less(Fraction other) const;
        bool is_less_or_eq(Fraction other) const;
        bool is_eq(Fraction other) const;
        bool operator>(Fraction other) const;
        bool operator<(Fraction other) const;
        bool operator==(Fraction other)const;
        bool operator>=(Fraction other) const;
        bool operator<=(Fraction other) const;
        bool is_improper();
        void simplify();
        Fraction reciprocal();
        double decimal();
        std::string strfy() const;
    };
    double reciprocalf(double frac);	// reciprocal float

    class Vector {

    };

}
