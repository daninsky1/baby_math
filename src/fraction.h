#pragma once

#include <map>
#include <ostream>
#include <sstream>

namespace bmath
{
    class Fraction {
    private:
        std::pair<Fraction, Fraction> make_equiv(Fraction other) const;
        void update();		// update m_decimal whenever the class get a change
        int m_numerator;
        int m_denominator;
        int m_mixed_num;
        double m_decimal;
    public:
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
        // print
        std::string strfy();
        int numerator() { return m_numerator; };
        void  numerator(int n) { m_numerator = n; update(); };
        int denominator() { return m_denominator; };
        void denominator(int d) { m_denominator = d; update(); };
    };
    double reciprocalf(double frac);	// reciprocal float
}    
std::ostream& operator<<(std::ostream& os, bmath::Fraction frac);