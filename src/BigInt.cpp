#include <string>
#include "BigInt.h"


BigInt::BigInt(){
    for (int i = 0; i < LENGTH; i++)
    {
        _number[i] = 0;   
    }
}

BigInt::BigInt(int initial)
{
    if (initial < 0)
    {
        _sign = '-';
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
        str += c;
        // std::cout << c;
    }
    std::cout << str << std::endl;

}

    BigInt  BigInt::add(BigInt rhnumber) {
        BigInt sum;




        return sum;
    }
    BigInt BigInt::substruct(BigInt rhnumber){
        BigInt difference;
        return difference; 
    } 
    BigInt BigInt::multiply(BigInt rhnumber){
        BigInt product;
        return product;
    }
    BigInt BigInt::divide(BigInt rhnumber){
        BigInt quotient;
        return quotient;
    }

