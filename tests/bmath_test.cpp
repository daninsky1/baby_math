#include <iostream>
#include <vector>
#include <bitset>
#include <map>
#include <climits>
#include "../src/printv.h"
#include "../src/bmath.h"

#include <gtest/gtest.h>

// bmath::absolute
TEST(SanityCheck, absoluteTest)
{
    EXPECT_EQ(bmath::absolute(-214748364), 214748364);
    EXPECT_EQ(bmath::absolute(-2147483647), 2147483647);
    // test max capacity
    EXPECT_EQ(bmath::absolute(INT64_MIN), static_cast<uint64_t>(INT64_MAX+1));
    EXPECT_EQ(bmath::absolute(INT64_MAX), INT64_MAX);
}

// bmath::distance
TEST(SanityCheck, distanceTest)
{
    EXPECT_EQ(bmath::distance(20, 20), 0);
    
    EXPECT_EQ(bmath::distance(2, 4), 2);    // positives
    EXPECT_EQ(bmath::distance(4, 2), 2);
    
    EXPECT_EQ(bmath::distance(-2, -4), 2);  // negatives
    EXPECT_EQ(bmath::distance(-4, -2), 2);
    
    EXPECT_EQ(bmath::distance(-2, 4), 6);   // negatives and positives
    EXPECT_EQ(bmath::distance(2, -4), 6);
    
    // test large numbers
    EXPECT_EQ(bmath::distance(INT64_MAX, 0), INT64_MAX);
    EXPECT_EQ(bmath::distance(INT64_MAX, 0), INT64_MAX);
    
    EXPECT_EQ(bmath::distance(INT64_MIN, 0), static_cast<uint64_t>(INT64_MIN)*-1);
    EXPECT_EQ(bmath::distance(0, INT64_MIN), static_cast<uint64_t>(INT64_MIN)*-1);
    
    EXPECT_EQ(bmath::distance(INT64_MIN, INT64_MAX), UINT64_MAX);    // test capacity
    EXPECT_EQ(bmath::distance(INT64_MAX,INT64_MIN), UINT64_MAX); 
}

// bmath::square bmath::cube
TEST(handlesSquareIntMax, squareTest) {
    EXPECT_ANY_THROW(bmath::square(static_cast<int64_t>(UINT32_MAX)+1));
    constexpr int64_t NUINT32_RANGE = static_cast<int64_t>(UINT32_MAX)*-1;     // "negative" uint 32 range size
    EXPECT_ANY_THROW(bmath::square(NUINT32_RANGE-1));
}
TEST(cubeTest, handlesCubeIntMax) {
    // TODO: update test
    static constexpr int CB_PMAX_INDEX = 2'097'151;     // positive max
    static constexpr int CB_NMAX_INDEX = -2'097'152;     //
    EXPECT_ANY_THROW(bmath::cube(CB_PMAX_INDEX+1));
    EXPECT_ANY_THROW(bmath::cube(CB_NMAX_INDEX-1));
    
}

TEST(benchmark, benchmarkNaivePower)
{
    
}

void avr_nums()
{
    std::cout << bmath::average(76, 70, 66, 75, 81) << '\n';
    std::cout << bmath::average(3, 2, 7, 8 ) << '\n';
    std::cout << bmath::average(-7, 5, -9, 4) << '\n';
    std::cout << bmath::average(0, 1, 3, 7, 19) << '\n';
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
