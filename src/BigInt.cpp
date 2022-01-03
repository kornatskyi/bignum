#include "BigInt.h"

BigInt::BigInt(int initial)
{
    if (initial < 0)
    {
        _number[0] = '-';
        initial *= -1;
    }

    int digit;
    int i = sizeof(_number) / sizeof(_number[0]);
    while (initial != 0)
    {
        digit = initial % 10;
        initial = (initial - digit) / 10;
        char c = '0' + digit;
        _number[i - 1] = c;

        i--;
    }
}

void BigInt::print()
{
    std::string str;
    for (char c : _number)
    {
        if(!c) continue;
        // str += std::to_string(c);
        std::cout << c;
    }
    std::cout << std::endl;

}
