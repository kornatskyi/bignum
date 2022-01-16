#pragma once
#include <iostream>
#include <string>
#include <vector>

class BigInt {
  // TODO: Public for now, change later
public:
  static const int LENGTH = 10;
  // Using char array datastructure with fixed length to store big int

  // int LENGTH;
  int NUMBER_OF_DIGITS;
  std::vector<char> _digits;
  bool _sign = true;

public:
  BigInt();
  BigInt(int initial);
  BigInt(std::string digits);
  BigInt(const char *digits);

  //   void setNumber(int number);
  //   void setNumber(char *number);
  //   void setNumber(std::string number);

  /* Operator overloading */
  // Assignment
  const BigInt &operator=(int initial);
  const BigInt &operator=(std::string initial);
  const BigInt &operator=(const char *initial);

  /* Operations */

  BigInt add(BigInt rhnumber);
  BigInt substruct(BigInt rhnumber);
  BigInt multiply(BigInt rhnumber);
  BigInt divide(BigInt rhnumber);

  /* Comparison operators */
  bool isLessThen(BigInt rhnumber);
  bool isMoreThen(BigInt rhnumber);
  bool isEqualTo(BigInt rhnumber);

  /* Validation */

  bool isValidString(std::string str);

  /* Utils */
  static int parseInt(char c);

  std::string toString();

  void print();

  // TODO: Change to private later
public:
  void changeDigit(int index, int value);
  void setDigit(int index, int value);
  void setDigit(int index, char value);

  void push(int value);
  void push(char value);

  char getCharAt(int index);

  void setSign(char sign);
  int getDigit(int index);
  int getHighestDigit(int index);
  std::string getNDigitsFromHighest(int n);
  std::string getNDigitsFromLowest(int n);
  int getLength();
  int getSignMult();
  int getNumberOfDigits();
  bool isDigit(char c);
};
