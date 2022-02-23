#include "../src/fraction.h"
#include "../src/bmath.h"
#include <gtest/gtest.h>


TEST(fractionAdd, FractionTests)
{
    std::cout << "Fraction add():\n";
    bmath::Fraction frac1{ 3, 8 };
    bmath::Fraction frac2{ 2, 8 };
    bmath::Fraction result = frac1 + frac2;
    bmath::Fraction frac3{ 5, 12 };
    bmath::Fraction frac4{ 1, 3 };
    result = frac3 + frac4;
    bmath::Fraction frac5{ 2, 5 };
    bmath::Fraction frac6{ 1, 7 };
    result = frac5 + frac6;
    bmath::Fraction frac7{ 3, 4 };
    bmath::Fraction frac8{ 1, 6 };
    result = frac7 + frac8;
    bmath::Fraction frac9{ 4, 7 };
    bmath::Fraction frac10{ 1, 7 };
    result = frac9 + frac10;
    bmath::Fraction frac11{ 3, 9 };
    bmath::Fraction frac12{ 4, 9 };
    result = frac11 + frac12;
    bmath::Fraction frac13{ 2, 3 };
    bmath::Fraction frac14{ 4, 1 };
    result = frac13 + frac14;
}

TEST(fractionSub, FractionTests)
{
    std::cout << "Fraction sub():\n";
    bmath::Fraction frac1{ 5, 7 };
    bmath::Fraction frac2{ 1, 7 };
    bmath::Fraction result1 = frac1 - frac2;
    std::cout << result1 << '\n';
    bmath::Fraction frac3{ 5, 2 };
    bmath::Fraction frac4{ 1, 4 };
    bmath::Fraction result2 = frac3 - frac4;
    std::cout << result2 << '\n';
    bmath::Fraction frac5{ 2, 3 };
    bmath::Fraction frac6{ 1, 6 };
    bmath::Fraction result3 = frac5 - frac6;
    std::cout << result3 << '\n';
    bmath::Fraction frac7{ 1, 3 };
    bmath::Fraction frac8{ 4, 7 };
    bmath::Fraction result4 = frac7 - frac8;
    std::cout << result4 << '\n';
    bmath::Fraction frac9{ 5, 1 };
    bmath::Fraction frac10{ 3, 4 };
    bmath::Fraction result5 = frac9 - frac10;
    std::cout << result5 << '\n';
}

TEST(fractionMult, FractionTests)
{
    std::cout << "Fraction mult():\n";
    bmath::Fraction frac1{ 3, 4 };
    bmath::Fraction frac2{ 5, 7 };
    bmath::Fraction result1 = frac1 * frac2;
    std::cout << result1 << '\n';
    bmath::Fraction frac3{ 6, 11 };
    bmath::Fraction frac4{ 2, 5 };
    bmath::Fraction result2 = frac3 * frac4;
    std::cout << result2 << '\n';
    bmath::Fraction frac5{ 14, 1 };
    bmath::Fraction frac6{ 2, 7 };
    bmath::Fraction result3 = frac5 * frac6;
    std::cout << result3 << '\n';
    bmath::Fraction frac7{ 10, 1 };
    bmath::Fraction frac8{ 2, 7 };
    bmath::Fraction result4 = frac7 * frac8;
    std::cout << result4 << '\n';
    bmath::Fraction frac9{ 3, 7 };
    bmath::Fraction frac10{ 2, 5 };
    bmath::Fraction result5 = frac9 * frac10;
    std::cout << result5 << '\n';
}

TEST(fractionDiv, FractionTests)
{
    std::cout << "Fraction div():\n";
    bmath::Fraction frac1{ 3, 5 };
    bmath::Fraction frac2{ 3, 4 };
    bmath::Fraction result1 = frac1 / frac2;
    std::cout << result1 << '\n';
    bmath::Fraction frac3{ 3, 5 };
    bmath::Fraction frac4{ 3, 5 };
    bmath::Fraction result2 = frac3 / frac4;
    std::cout << result2 << '\n';
    bmath::Fraction frac5{ 5, 8 };
    bmath::Fraction frac6{ 2, 3 };
    bmath::Fraction result3 = frac5 / frac6;
    std::cout << result3 << '\n';
    bmath::Fraction frac7{ 2, 9 };
    bmath::Fraction frac8{ 1, 3 };
    bmath::Fraction result4 = frac7 / frac8;
    std::cout << result4 << '\n';
    bmath::Fraction frac9{ 1, 7 };
    bmath::Fraction frac10{ 4, 3 };
    bmath::Fraction result5 = frac9 / frac10;
    std::cout << result5 << '\n';
    bmath::Fraction frac11{ 4, 1 };
    bmath::Fraction frac12{ 1, 3 };
    bmath::Fraction result6 = frac11 / frac12;
    std::cout << result6 << '\n';
    bmath::Fraction frac13{ 5, 9 };
    bmath::Fraction frac14{ 5, 1 };
    bmath::Fraction result7 = frac13 / frac14;
    std::cout << result7 << '\n';
    bmath::Fraction frac15{ 7, 8 };
    bmath::Fraction frac16{ 3, 1 };
    bmath::Fraction result8 = frac15 / frac16;
    std::cout << result8 << '\n';
    bmath::Fraction frac17{ 10, 1 };
    bmath::Fraction frac18{ 2, 7 };
    bmath::Fraction result9 = frac17 / frac18;
    std::cout << result9 << '\n';
    bmath::Fraction frac19{ 1, 1 };
    bmath::Fraction frac20{ 3, 5 };
    bmath::Fraction result10 = frac19 / frac20;
    std::cout << result10 << '\n';
}

TEST(fractionStream, FractionOStream)
{
    std::cout << "Fraction add():\n";
    bmath::Fraction frac1{ 3, 8 };
    bmath::Fraction frac2{ 2, 8 };
    bmath::Fraction result1 = frac1 + frac2;
    std::cout << result1 << '\n';
    bmath::Fraction frac3{ 5, 12 };
    bmath::Fraction frac4{ 1, 3 };
    bmath::Fraction result2 = frac3 + frac4;
    std::cout << result2 << '\n';
    bmath::Fraction frac5{ 2, 5 };
    bmath::Fraction frac6{ 1, 7 };
    bmath::Fraction result3 = frac5 + frac6;
    std::cout << result3 << '\n';
    bmath::Fraction frac7{ 3, 4 };
    bmath::Fraction frac8{ 1, 6 };
    bmath::Fraction result4 = frac7 + frac8;
    result4.simplify();
    std::cout << result4 << '\n';
    bmath::Fraction frac9{ 4, 7 };
    bmath::Fraction frac10{ 1, 7 };
    bmath::Fraction result5 = frac9 + frac10;
    std::cout << result5 << '\n';
    bmath::Fraction frac11{ 3, 9 };
    bmath::Fraction frac12{ 4, 9 };
    bmath::Fraction result6 = frac11 + frac12;
    std::cout << result6 << '\n';
    bmath::Fraction frac13{ 2, 3 };
    bmath::Fraction frac14{ 4, 1 };
    bmath::Fraction result7 = frac13 + frac14;
    std::cout << result7 << '\n';
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}