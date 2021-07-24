#include <iostream>
#include <vector>
#include <bitset>
#include <map>
#include <climits>
#include "../src/printv.h"
#include "../src/bmath.h"

#include <gtest/gtest.h>

// bmath::absolute
TEST(absoluteTest, HandlesIntMin)
{
    EXPECT_ANY_THROW(bmath::absolute(INT_MIN));
}
TEST(absoluteTest, SanityCheck)
{
    EXPECT_EQ(bmath::absolute(-1), 1);
    EXPECT_EQ(bmath::absolute(-12), 12);
    EXPECT_EQ(bmath::absolute(-123), 123);
    EXPECT_EQ(bmath::absolute(-1234), 1234);
    EXPECT_EQ(bmath::absolute(-12345), 12345);
    EXPECT_EQ(bmath::absolute(-214748), 214748);
    EXPECT_EQ(bmath::absolute(-2147483), 2147483);
    EXPECT_EQ(bmath::absolute(-21474836), 21474836);
    EXPECT_EQ(bmath::absolute(-214748364), 214748364);
    EXPECT_EQ(bmath::absolute(-2147483647), 2147483647);
}

// bmath::distance
TEST(distanceTest, SanityCheck)
{
    EXPECT_EQ(bmath::distance(-2, 2), 4);
    EXPECT_EQ(bmath::distance(-21, 21), 21*2);
    EXPECT_EQ(bmath::distance(-214, 214), 214*2);
    EXPECT_EQ(bmath::distance(-2147, 2147), 2147*2);
    EXPECT_EQ(bmath::distance(-21474, 21474), 21474*2);
    EXPECT_EQ(bmath::distance(-214748, 214748), 214748*2);
    EXPECT_EQ(bmath::distance(-2147483, 2147483), 2147483*2);
    EXPECT_EQ(bmath::distance(-21474836, 21474836), 21474836*2);
    EXPECT_EQ(bmath::distance(-214748364, 214748364), 214748364*2);
    EXPECT_EQ(bmath::distance(INT_MIN, INT_MAX), UINT_MAX);
}

// bmath::square bmath::cube
TEST(squareTest, handlesSquareIntMax) { EXPECT_ANY_THROW(bmath::square(46342)); }
TEST(cubeTest, handlesCubeIntMax) { EXPECT_ANY_THROW(bmath::cube(1291)); }






void avr_nums()
{
    std::vector<int> numbers = { 76, 70, 66, 75, 81 };
    std::cout << bmath::average(numbers) << '\n';
    std::vector<int> numbers2 = { 3, 2, 7, 8 };
    std::cout << bmath::average(numbers2) << '\n';
    std::vector<int> numbers3 = { -7, 5, -9, 4 };
    std::cout << bmath::average(numbers3) << std::endl;
    std::vector<int> numbers4 = { 0, 1, 3, 7, 19 };
}

void find_factors()
{
    dsk::printv(bmath::find_factors(8));
    dsk::printv(bmath::find_factors(20));
    dsk::printv(bmath::find_factors(32));
}

void common_factors()
{
    dsk::printv(bmath::common_factors(27, 18));
    dsk::printv(bmath::common_factors(24, 42));
    dsk::printv(bmath::common_factors(14, 16));
    dsk::printv(bmath::common_factors(7, 56));
    dsk::printv(bmath::common_factors(60, 80));
}

void gcf()
{
    std::cout << bmath::gcf(14, 16) << '\n';
    std::cout << bmath::gcf(7, 56) << '\n';
    std::cout << bmath::gcf(60, 80) << '\n';
}


void test_soe_table()
{
    std::map<int, bool> table = bmath::sieve_of_eratosthenes_table(11);
    std::vector<bool> bool_table;
    std::cout << table.size() << '\n';
    for (int i = 0; i < table.size(); ++i)
        bool_table.push_back(table[i + 2]);
    std::cout << bool_table.size() << '\n';
    //dsk::printv(bool_table);
    for (int i = 0; i < bool_table.size(); ++i) {
        std::cout << i + 2 << ": " << bool_table[i];
        std::cin.ignore();
    }
}

void is_coprime()
{
    std::cout << bmath::is_coprime(26, 27);
    std::cout << bmath::is_coprime(6, 38);
    std::cout << bmath::is_coprime(13, 39);
    std::cout << bmath::is_coprime(17, 100);
}

void squares()
{
    std::cout << bmath::square(8) << '\n';
    std::cout << bmath::square(9) << '\n';
    std::cout << bmath::square(10) << '\n';
    std::cout << bmath::square(-4) << '\n';
    std::cout << bmath::square(1.7) << '\n';
    std::cout << bmath::square(-8) << '\n';
    std::cout << bmath::square(3) << '\n';
    std::cout << bmath::square(-5) << '\n';


}

void powers()
{
    std::cout << bmath::power(4, 2) << '\n';
    std::cout << bmath::power(4, 3) << '\n';
    std::cout << bmath::cube(4) << '\n';
    std::cout << bmath::power(5, 3) << '\n';
    std::cout << bmath::power(3, 4) << '\n';
    std::cout << bmath::power(2, 7) << '\n';
    std::cout << bmath::power(-7, 2) << '\n';
    std::cout << bmath::power(-5, 3) << '\n';
    std::cout << bmath::power(-3, 4) << '\n';
    std::cout << bmath::power(-2, 5) << '\n';
    std::cout << bmath::power(0, 2) << '\n';
    std::cout << bmath::power(0, 9) << '\n';
    std::cout << bmath::power(1, 3) << '\n';
    std::cout << bmath::power(1, 7) << '\n';
    std::cout << bmath::power(2.7, 4) << '\n';
    std::cout << bmath::power(1.3, 5) << '\n';
}

// Google test test
TEST(HelloTest, BasicAssertions) {
    EXPECT_STRNE("daniel", "marina");
    EXPECT_EQ(7*6, 42);
}

// CODE SNIPPETS
void t_compl_signed()
{
    char number = 10;
    char number2 = ~10 + 1;
    std::bitset<8> bnumber = number;
    std::bitset<8> bnumber2 = number2;
    std::cout << bnumber << '\t' << +(char)bnumber.to_ulong() << '\n';
    std::cout << bnumber2 << '\t' << +(char)bnumber2.to_ulong() << '\n';
}

void count_byte(char n)
{
    while (true)
    {
        std::bitset<8> b_n = n;
        std::cout << b_n << '\t' << +(char)b_n.to_ulong() << std::endl;
        std::system("cls");
    }
}