#pragma once
#include <iostream>

class BigInt {
  // TODO: Public for now, change later
private:
  static const int LENGTH = 10;
  // Using char array datastructure with fixed length to store big int
  char _digits[LENGTH];
  char _sign = '+';

public:
  BigInt();
  BigInt(int initial);
  BigInt(std::string digits);

  //   void setNumber(int number);
  //   void setNumber(char *number);
  //   void setNumber(std::string number);

  /* Operations */

  BigInt add(BigInt rhnumber);
  BigInt substruct(BigInt rhnumber);
  BigInt multiply(BigInt rhnumber);
  BigInt divide(BigInt rhnumber);

  /* Validation */

  bool isValidString(std::string str);

  /* Utils */
  static int parseInt(char c);

  void print();

  // TODO: Change to private later
public:
  void changeDigit(int index, int value);
  void setDigit(int index, int value);
  int getLength();
  int getDigit(int index);
  int getSignMult();
};
