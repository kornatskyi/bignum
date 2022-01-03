#pragma once
#include <iostream>

class BigInt
{
    static const int LENGTH = 10;
// Using char array datastructure with fixed length to store big int
    char _number[LENGTH];
    char _sign = '+';

public:
    BigInt();
    BigInt(int initial);
    BigInt(std::string initial);

    char* getNumber();

    void setNumber(int number);
    void setNumber(char* number);
    void setNumber(std::string  number);

    /* Operations */

    BigInt add(BigInt rhnumber); 
    BigInt substruct(BigInt rhnumber); 
    BigInt multiply(BigInt rhnumber);
    BigInt divide(BigInt rhnumber);



    void print();
};
