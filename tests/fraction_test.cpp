#include "../src/fraction.h"
#include "../src/bmath.h"
#include <gtest/gtest.h>


TEST(FractionTests, fractionAdd)
{
    std::cout << "Fraction add():\n";
    bmath::Fraction frac1{ 3, 8 };
    bmath::Fraction frac2{ 2, 8 };
    bmath::Fraction result = frac1 + frac2;
    EXPECT_EQ(result.numerator(), 2); EXPECT_EQ(result.denominator(), 1);
    bmath::Fraction frac3{ 5, 12 };
    bmath::Fraction frac4{ 1, 3 };
    result = frac3 + frac4;
    EXPECT_EQ(result.numerator(), 9); EXPECT_EQ(result.denominator(), 12);
    bmath::Fraction frac5{ 2, 5 };
    bmath::Fraction frac6{ 1, 7 };
    result = frac5 + frac6;
    EXPECT_EQ(result.numerator(), 19); EXPECT_EQ(result.denominator(), 35);
    bmath::Fraction frac7{ 3, 4 };
    bmath::Fraction frac8{ 1, 6 };
    result = frac7 + frac8;
    EXPECT_EQ(result.numerator(), 11); EXPECT_EQ(result.denominator(), 12);
    bmath::Fraction frac9{ 4, 7 };
    bmath::Fraction frac10{ 1, 7 };
    result = frac9 + frac10;
    EXPECT_EQ(result.numerator(), 2); EXPECT_EQ(result.denominator(), 1);
    bmath::Fraction frac11{ 3, 9 };
    bmath::Fraction frac12{ 4, 9 };
    result = frac11 + frac12;
    EXPECT_EQ(result.numerator(), 2); EXPECT_EQ(result.denominator(), 1);
    bmath::Fraction frac13{ 2, 3 };
    bmath::Fraction frac14{ 4, 1 };
    result = frac13 + frac14;
    EXPECT_EQ(result.numerator(), 14); EXPECT_EQ(result.denominator(), 3);
}

TEST(FractionTests, fractionSub)
{
    std::cout << "Fraction sub():\n";
    bmath::Fraction frac1{ 5, 7 };
    bmath::Fraction frac2{ 1, 7 };
    bmath::Fraction result = frac1 - frac2;
    EXPECT_EQ(result.numerator(), 2); EXPECT_EQ(result.denominator(), 1);
    bmath::Fraction frac3{ 5, 2 };
    bmath::Fraction frac4{ 1, 4 };
    result = frac3 - frac4;
    EXPECT_EQ(result.numerator(), 11); EXPECT_EQ(result.denominator(), 4);
    bmath::Fraction frac5{ 2, 3 };
    bmath::Fraction frac6{ 1, 6 };
    result = frac5 - frac6;
    EXPECT_EQ(result.numerator(), 5); EXPECT_EQ(result.denominator(), 6);
    bmath::Fraction frac7{ 1, 3 };
    bmath::Fraction frac8{ 4, 7 };
    result = frac7 - frac8;
    EXPECT_EQ(result.numerator(), 19); EXPECT_EQ(result.denominator(), 21);
    bmath::Fraction frac9{ 5, 1 };
    bmath::Fraction frac10{ 3, 4 };
    result = frac9 - frac10;
    EXPECT_EQ(result.numerator(), 23); EXPECT_EQ(result.denominator(), 4);
}

TEST(FractionTests, fractionMult)
{
    std::cout << "Fraction mult():\n";
    bmath::Fraction frac1{ 3, 4 };
    bmath::Fraction frac2{ 5, 7 };
    bmath::Fraction result = frac1 * frac2;
    EXPECT_EQ(result.numerator(), 15); EXPECT_EQ(result.denominator(), 28);
    bmath::Fraction frac3{ 6, 11 };
    bmath::Fraction frac4{ 2, 5 };
    result = frac3 * frac4;
    EXPECT_EQ(result.numerator(), 12); EXPECT_EQ(result.denominator(), 55);
    bmath::Fraction frac5{ 14, 1 };
    bmath::Fraction frac6{ 2, 7 };
    result = frac5 * frac6;
    EXPECT_EQ(result.numerator(), 28); EXPECT_EQ(result.denominator(), 7);
    bmath::Fraction frac7{ 10, 1 };
    bmath::Fraction frac8{ 2, 7 };
    result = frac7 * frac8;
    EXPECT_EQ(result.numerator(), 20); EXPECT_EQ(result.denominator(), 7);
    bmath::Fraction frac9{ 3, 7 };
    bmath::Fraction frac10{ 2, 5 };
    result = frac9 * frac10;
    EXPECT_EQ(result.numerator(), 6); EXPECT_EQ(result.denominator(), 35);
}

TEST(FractionTests, fractionDiv)
{
    std::cout << "Fraction div():\n";
    bmath::Fraction frac1{ 3, 5 };
    bmath::Fraction frac2{ 3, 4 };
    bmath::Fraction result = frac1 / frac2;
    EXPECT_EQ(result.numerator(), 12); EXPECT_EQ(result.denominator(), 15);
    bmath::Fraction frac3{ 3, 5 };
    bmath::Fraction frac4{ 3, 5 };
    result = frac3 / frac4;
    EXPECT_EQ(result.numerator(), 15); EXPECT_EQ(result.denominator(), 15);
    bmath::Fraction frac5{ 5, 8 };
    bmath::Fraction frac6{ 2, 3 };
    result = frac5 / frac6;
    EXPECT_EQ(result.numerator(), 15); EXPECT_EQ(result.denominator(), 16);
    bmath::Fraction frac7{ 2, 9 };
    bmath::Fraction frac8{ 1, 3 };
    result = frac7 / frac8;
    EXPECT_EQ(result.numerator(), 6); EXPECT_EQ(result.denominator(), 9);
    bmath::Fraction frac9{ 1, 7 };
    bmath::Fraction frac10{ 4, 3 };
    result = frac9 / frac10;
    EXPECT_EQ(result.numerator(), 3); EXPECT_EQ(result.denominator(), 28);
    bmath::Fraction frac11{ 4, 1 };
    bmath::Fraction frac12{ 1, 3 };
    result = frac11 / frac12;
    EXPECT_EQ(result.numerator(), 12); EXPECT_EQ(result.denominator(), 1);
    bmath::Fraction frac13{ 5, 9 };
    bmath::Fraction frac14{ 5, 1 };
    result = frac13 / frac14;
    EXPECT_EQ(result.numerator(), 5); EXPECT_EQ(result.denominator(), 45);
    bmath::Fraction frac15{ 7, 8 };
    bmath::Fraction frac16{ 3, 1 };
    result = frac15 / frac16;
    EXPECT_EQ(result.numerator(), 7); EXPECT_EQ(result.denominator(), 24);
    bmath::Fraction frac17{ 10, 1 };
    bmath::Fraction frac18{ 2, 7 };
    result = frac17 / frac18;
    EXPECT_EQ(result.numerator(), 70); EXPECT_EQ(result.denominator(), 2);
    bmath::Fraction frac19{ 1, 1 };
    bmath::Fraction frac20{ 3, 5 };
    result = frac19 / frac20;
    EXPECT_EQ(result.numerator(), 5); EXPECT_EQ(result.denominator(), 3);
}

TEST(FractionOStream, fractionStream)
{
    std::cout << "Fraction strfy():\n";
    bmath::Fraction frac{ 3, 8 };
    EXPECT_STREQ(frac.strfy().c_str(), "3/8");
    frac.numerator(2); frac.denominator(8);
    EXPECT_STREQ(frac.strfy().c_str(), "2/8");
    frac.numerator(5); frac.denominator(12);
    EXPECT_STREQ(frac.strfy().c_str(), "5/12");
    frac.numerator(1); frac.denominator(3);
    EXPECT_STREQ(frac.strfy().c_str(), "1/3");
    frac.numerator(2); frac.denominator(5);
    EXPECT_STREQ(frac.strfy().c_str(), "2/5");
    frac.numerator(1); frac.denominator(7);
    EXPECT_STREQ(frac.strfy().c_str(), "1/7");
    frac.numerator(3); frac.denominator(4);
    EXPECT_STREQ(frac.strfy().c_str(), "3/4");
    frac.numerator(1); frac.denominator(6);
    EXPECT_STREQ(frac.strfy().c_str(), "1/6");
    frac.numerator(10); frac.denominator(60);
    EXPECT_STREQ(frac.strfy().c_str(), "10/60");
    frac.numerator(50); frac.denominator(888);
    EXPECT_STREQ(frac.strfy().c_str(), "50/888");
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}