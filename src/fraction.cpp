#include "fraction.h"
#include "bmath.h"
using namespace bmath;

bmath::Fraction::Fraction(int numerator, int denominator, int mixed_num)
    :m_numerator{ numerator }, m_denominator{ denominator }, 
    m_mixed_num{ mixed_num }, m_decimal{static_cast<double>(numerator / denominator)}
{
}

// TODO: add a overload to make_equiv to accept more than 2 Fractions
std::pair<Fraction, Fraction> bmath::Fraction::make_equiv(Fraction other) const
{
    // make a pair of fractions equivalent e.g 5/2, 6/4 = 10/4, 6/4 or
    // 6/4, 5/2 = 6/4, 10/4
    int denom1 = m_denominator;
    int denom2 = other.m_denominator;
    int numer1 = m_numerator;
    int numer2 = other.m_numerator;
    int denoms_lcm = lcm(denom1, denom2);
    int denom1_quotient = denoms_lcm / denom1;
    int denom2_quotient = denoms_lcm / denom2;
    denom1 = denoms_lcm;					// put the lcm on the minor denominator
    denom2 = denoms_lcm;
    numer1 = denom1_quotient * numer1;
    numer2 = denom2_quotient * numer2;
    return std::pair<Fraction, Fraction>(Fraction(numer1, denom1), Fraction(numer2, denom2));
}

void bmath::Fraction::update()
{
    m_decimal = m_numerator / m_denominator;
}

// TODO: make add, sub, mult, div overload to accept integer number with fractions
bmath::Fraction bmath::Fraction::add(Fraction other) const
{
    Fraction this_equiv(1, 1);
    Fraction other_equiv(1, 1);
    if (m_denominator != other.m_denominator) {
        std::pair<Fraction, Fraction> frac_pair = make_equiv(other);
        this_equiv = frac_pair.first;
        other_equiv = frac_pair.second;
    }
    return bmath::Fraction(this_equiv.m_numerator + other_equiv.m_numerator, this_equiv.m_denominator);
}

bmath::Fraction bmath::Fraction::sub(Fraction other) const
{
    // TODO: add and sub share this piece of code
    // make a separeted function to this code
    Fraction this_equiv(1, 1);
    Fraction other_equiv(1, 1);
    if (m_denominator != other.m_denominator) {
        std::pair<Fraction, Fraction> frac_pair = make_equiv(other);
        this_equiv = frac_pair.first;
        other_equiv = frac_pair.second;
    }
    return Fraction(this_equiv.m_numerator + other_equiv.m_numerator, this_equiv.m_denominator);
}

bmath::Fraction bmath::Fraction::mult(Fraction other) const
{

    return Fraction(
        m_numerator * other.m_numerator,
        m_denominator * other.m_denominator);
}

bmath::Fraction bmath::Fraction::cross_mult(Fraction other) const
{
    return Fraction(
        m_numerator * other.m_denominator,
        m_denominator * other.m_numerator);
}

bmath::Fraction bmath::Fraction::div(Fraction other) const
{
    return cross_mult(other);
}

bmath::Fraction bmath::Fraction::operator+(Fraction other) const
{
    return add(other);
}

bmath::Fraction bmath::Fraction::operator-(Fraction other) const
{
    return sub(other);
}

bmath::Fraction bmath::Fraction::operator*(Fraction other) const
{
    return mult(other);
}

bmath::Fraction bmath::Fraction::operator/(Fraction other) const
{
    return div(other);
}

void bmath::Fraction::simplify()
{
    int gcf_ = gcf(m_numerator, m_denominator);
    m_numerator /= gcf_;
    m_denominator /= gcf_;
}

bool bmath::Fraction::is_gtr(Fraction other) const
{
    Fraction result = cross_mult(other);
    if (result.m_numerator > result.m_denominator)
        return true;
    else return false;
}

bool bmath::Fraction::is_less(Fraction other) const
{
    Fraction result = cross_mult(other);
    if (result.m_numerator < result.m_denominator)
        return true;
    else return false;
}

bool bmath::Fraction::is_eq(Fraction other) const
{
    Fraction result = cross_mult(other);
    if (result.m_numerator == result.m_denominator)
        return true;
    else return false;
}

bool bmath::Fraction::is_gtr_or_eq(Fraction other) const
{
    if (is_gtr(other) || is_eq(other)) return true;
    else return false;
}

bool bmath::Fraction::is_less_or_eq(Fraction other) const
{
    if (is_less(other) || is_eq(other)) return true;
    else return false;
}

// TODO: is_gtr and is_less needs a handiling negative number
// now if negative number is passed gives an undefined behavior
bool bmath::Fraction::operator>(Fraction other) const
{
    return is_gtr(other);
}

bool bmath::Fraction::operator>=(Fraction other) const
{
    return is_gtr_or_eq(other);
}

bool bmath::Fraction::operator<(Fraction other) const
{
    return is_less(other);
}

bool bmath::Fraction::operator<=(Fraction other) const
{
    return is_less_or_eq(other);
}

bool bmath::Fraction::is_improper()
{
    // an improper fraction is a fraction that the numberator
    // is greater than the denominator
    if (m_numerator > m_denominator) return true;
    else return false;
}

bool bmath::Fraction::operator==(Fraction other) const
{
    return is_eq(other);
}

double bmath::Fraction::decimal()
{
    return m_numerator / m_denominator;
}

bmath::Fraction bmath::Fraction::reciprocal()
{
    return Fraction(m_denominator, m_numerator);
}

double bmath::reciprocalf(double frac) { return 1 / frac; }

std::ostream& operator<<(std::ostream& os, bmath::Fraction frac)
{
    return os << frac.numerator() << '/' << frac.denominator();
}

std::string bmath::Fraction::strfy()
{
    std::stringstream ss;
    ss << static_cast<Fraction>(*this) << std::endl;
    return ss.str();
}