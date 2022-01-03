#pragma once
#include <iostream>

class BigInt
{
// Using char array datastructure with fixed length to store big int
    char _number[10] = {'+', 0, 0, 0, 0, 0, 0, 0, 0, 0};

public:
    BigInt(int initial);
    BigInt(std::string initial);

    char* getNumber();

    void setNumber(int number);
    void setNumber(char* number);
    void setNumber(std::string  number);

    void print();
};
