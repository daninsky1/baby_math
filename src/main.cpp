#include <iostream>
#include <bitset>
#include <vector>
#include "printv.h"
#include "bmath.h"
#include "../BabyMathConfig.h"

void bitmask_test()
{

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

void t_compl_signed()
{
    char number = 10;
    char number2 = ~10 + 1;
    std::bitset<8> bnumber = number;
    std::bitset<8> bnumber2 = number2;
    std::cout << bnumber << '\t' << +(char)bnumber.to_ulong() << '\n';
    std::cout << bnumber2 << '\t' << +(char)bnumber2.to_ulong() << '\n';
}

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

void fractions_add()
{
    std::cout << "Fraction add():\n";
    bmath::Fraction frac1{ 3, 8 };
    bmath::Fraction frac2{ 2, 8 };
    bmath::Fraction result1 = frac1 + frac2;
    std::cout << result1.strfy() << '\n';
    bmath::Fraction frac3{ 5, 12 };
    bmath::Fraction frac4{ 1, 3 };
    bmath::Fraction result2 = frac3 + frac4;
    std::cout << result2.strfy() << '\n';
    bmath::Fraction frac5{ 2, 5 };
    bmath::Fraction frac6{ 1, 7 };
    bmath::Fraction result3 = frac5 + frac6;
    std::cout << result3.strfy() << '\n';
    bmath::Fraction frac7{ 3, 4 };
    bmath::Fraction frac8{ 1, 6 };
    bmath::Fraction result4 = frac7 + frac8;
    result4.simplify();
    std::cout << result4.strfy() << '\n';
    bmath::Fraction frac9{ 4, 7 };
    bmath::Fraction frac10{ 1, 7 };
    bmath::Fraction result5 = frac9 + frac10;
    std::cout << result5.strfy() << '\n';
    bmath::Fraction frac11{ 3, 9 };
    bmath::Fraction frac12{ 4, 9 };
    bmath::Fraction result6 = frac11 + frac12;
    std::cout << result6.strfy() << '\n';
    bmath::Fraction frac13{ 2, 3 };
    bmath::Fraction frac14{ 4, 1 };
    bmath::Fraction result7 = frac13 + frac14;
    std::cout << result7.strfy() << '\n';
}

void fractions_sub()
{
    std::cout << "Fraction sub():\n";
    bmath::Fraction frac1{ 5, 7 };
    bmath::Fraction frac2{ 1, 7 };
    bmath::Fraction result1 = frac1 - frac2;
    std::cout << result1.strfy() << '\n';
    bmath::Fraction frac3{ 5, 2 };
    bmath::Fraction frac4{ 1, 4 };
    bmath::Fraction result2 = frac3 - frac4;
    std::cout << result2.strfy() << '\n';
    bmath::Fraction frac5{ 2, 3 };
    bmath::Fraction frac6{ 1, 6 };
    bmath::Fraction result3 = frac5 - frac6;
    std::cout << result3.strfy() << '\n';
    bmath::Fraction frac7{ 1, 3 };
    bmath::Fraction frac8{ 4, 7 };
    bmath::Fraction result4 = frac7 - frac8;
    std::cout << result4.strfy() << '\n';
    bmath::Fraction frac9{ 5, 1 };
    bmath::Fraction frac10{ 3, 4 };
    bmath::Fraction result5 = frac9 - frac10;
    std::cout << result5.strfy() << '\n';
}

void fractions_mult()
{
    std::cout << "Fraction mult():\n";
    bmath::Fraction frac1{ 3, 4 };
    bmath::Fraction frac2{ 5, 7 };
    bmath::Fraction result1 = frac1 * frac2;
    std::cout << result1.strfy() << '\n';
    bmath::Fraction frac3{ 6, 11 };
    bmath::Fraction frac4{ 2, 5 };
    bmath::Fraction result2 = frac3 * frac4;
    std::cout << result2.strfy() << '\n';
    bmath::Fraction frac5{ 14, 1 };
    bmath::Fraction frac6{ 2, 7 };
    bmath::Fraction result3 = frac5 * frac6;
    std::cout << result3.strfy() << '\n';
    bmath::Fraction frac7{ 10, 1 };
    bmath::Fraction frac8{ 2, 7 };
    bmath::Fraction result4 = frac7 * frac8;
    std::cout << result4.strfy() << '\n';
    bmath::Fraction frac9{ 3, 7 };
    bmath::Fraction frac10{ 2, 5 };
    bmath::Fraction result5 = frac9 * frac10;
    std::cout << result5.strfy() << '\n';
}

void fractions_div()
{
    std::cout << "Fraction div():\n";
    bmath::Fraction frac1{ 3, 5 };
    bmath::Fraction frac2{ 3, 4 };
    bmath::Fraction result1 = frac1 / frac2;
    std::cout << result1.strfy() << '\n';
    bmath::Fraction frac3{ 3, 5 };
    bmath::Fraction frac4{ 3, 5 };
    bmath::Fraction result2 = frac3 / frac4;
    std::cout << result2.strfy() << '\n';
    bmath::Fraction frac5{ 5, 8 };
    bmath::Fraction frac6{ 2, 3 };
    bmath::Fraction result3 = frac5 / frac6;
    std::cout << result3.strfy() << '\n';
    bmath::Fraction frac7{ 2, 9 };
    bmath::Fraction frac8{ 1, 3 };
    bmath::Fraction result4 = frac7 / frac8;
    std::cout << result4.strfy() << '\n';
    bmath::Fraction frac9{ 1, 7 };
    bmath::Fraction frac10{ 4, 3 };
    bmath::Fraction result5 = frac9 / frac10;
    std::cout << result5.strfy() << '\n';
    bmath::Fraction frac11{ 4, 1 };
    bmath::Fraction frac12{ 1, 3 };
    bmath::Fraction result6 = frac11 / frac12;
    std::cout << result6.strfy() << '\n';
    bmath::Fraction frac13{ 5, 9 };
    bmath::Fraction frac14{ 5, 1 };
    bmath::Fraction result7 = frac13 / frac14;
    std::cout << result7.strfy() << '\n';
    bmath::Fraction frac15{ 7, 8 };
    bmath::Fraction frac16{ 3, 1 };
    bmath::Fraction result8 = frac15 / frac16;
    std::cout << result8.strfy() << '\n';
    bmath::Fraction frac17{ 10, 1 };
    bmath::Fraction frac18{ 2, 7 };
    bmath::Fraction result9 = frac17 / frac18;
    std::cout << result9.strfy() << '\n';
    bmath::Fraction frac19{ 1, 1 };
    bmath::Fraction frac20{ 3, 5 };
    bmath::Fraction result10 = frac19 / frac20;
    std::cout << result10.strfy() << '\n';


}

void reciprocal()
{
    std::cout << bmath::reciprocalf(2.5) << '\n';
    std::cout << bmath::reciprocalf(9) << '\n';
    std::cout << bmath::reciprocalf(0.37) << '\n';
    std::cout << bmath::reciprocalf(-1.6) << '\n';
}

void frac_is_eq()
{
    std::cout << "Fraction is_eq():\n";
    bmath::Fraction frac1{ 1, 1 };
    bmath::Fraction frac2{ 3, 5 };
    bool result1 = frac1 == frac2;
    std::cout << result1 << '\n';
    bmath::Fraction frac3{ 6, 8 };
    bmath::Fraction frac4{ 3, 4 };
    bool result2 = frac3 == frac4;
    std::cout << result2 << '\n';
}

void fractions()
{
    std::vector<void(*)()> funcs = {
        &fractions_add,
        &fractions_sub,
        &fractions_mult,
        &fractions_div };

    for (int i = 0; i < funcs.size(); ++i) {
        std::cin.ignore();
        funcs[i]();
    }
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
int main()
{
    
    using namespace dsk;
    squares();
}