#include <bitset>
#include <vector>
#include <climits>
#include <cmath>
#include <ctime>
#include <string>
#include <type_traits>

#include "printv.h"
#include "bmath.h"
#include "fraction.h"
// #include "../BabyMathConfig.h"

void sq_max_test();

int main(void)
{
    using namespace dsk;
    using namespace std;
    int n = 36;
    std::cout << n << " = " << bmath::sqrt(n) << '\n';
    
}
//
// MANUAL TESTS
//
int dig_len(uint64_t n)
{
    std::string s = std::to_string(n);
    return s.size();
}

void average_test()
{
    char i = 'a';
    double d = 20.00;
    
    
    std::cout << std::is_convertible<char, int>::value << '\n';
    
    std::cout << bmath::average(
        'a', 10, 12, 13, 13, 13, 15, 15, 16, 16, 18, 22, 23, 24, 24, 25
    ) << '\n';
    
    std::cout << sqrt('a') << '\n';
}

void sq_max_test()
{
    // the error check is really simple
    // the max uint32_t arg prevents uint64_t overflow
    
    unsigned int i = 4294967295; // 4'200'000'000 < max < 4'300'000'000
    uint64_t sq = 0;

    int number = 10;
    sq = bmath::square(i);
    std::cout << sizeof(uint64_t) << '\n';
    std::cout << sq << '\n';
    std::cout << dig_len(sq) << '\n';
}

void power_benchmark()
{
    clock_t begin_time = clock();
    for (uint32_t i = 0; i < 100000; ++i) {
        bmath::naive_power(2, 20);
    }
    double naive_power_time = static_cast<double>(clock() - begin_time) / CLOCKS_PER_SEC;
    std::cout << "naive_power time: " << naive_power_time << '\n';
    begin_time = clock();
    for (uint32_t i = 0; i < 100000; ++i) {
        bmath::power(2, 20);
    }
    naive_power_time = static_cast<double>(clock() - begin_time) / CLOCKS_PER_SEC;
    std::cout << "power time: " << naive_power_time << '\n';
    begin_time = clock();
    for (uint32_t i = 0; i < 100000; ++i) {
        bmath::iter_power(2, 20);
    }
    naive_power_time = static_cast<double>(clock() - begin_time) / CLOCKS_PER_SEC;
    std::cout << "iter_power time: " << naive_power_time << '\n';
}

void absolute_test()
{
    using namespace std;
    int number = -100;
    bitset<32> bnumber = number;
    int mask = number >> 31;
    bitset<32> bmask = mask;
    cout << number << '\n' 
         << bnumber << '\n';
    cout << (mask) << '\n'
         << bmask << '\n';
    int absolute = (mask + number)^mask;
    bitset<32> babsolute = absolute;
    cout << absolute << '\n'
         << babsolute << '\n';
}