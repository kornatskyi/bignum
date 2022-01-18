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
  // Comparison operators
  bool operator==(const BigInt &rhs) const;
  bool operator!=(const BigInt &rhs) const;
  bool operator<(const BigInt &rhs) const;
  bool operator<=(const BigInt &rhs) const;
  bool operator>(const BigInt &rhs) const;
  bool operator>=(const BigInt &rhs) const;

  /* Operations */
  BigInt operator+(const BigInt rhnumber) const;
  BigInt operator-(const BigInt rhnumber) const;
  BigInt operator*(BigInt rhnumber) const;
  BigInt operator/(BigInt rhnumber) const;

  BigInt add(const BigInt rhnumber) const;
  BigInt substruct(const BigInt rhnumber) const;
  BigInt multiply(const BigInt rhnumber) const;
  BigInt divide(const BigInt rhnumber) const;

  /* Comparison operators */
  bool isLessThen(const BigInt rhnumber) const;
  bool isMoreThen(const BigInt rhnumber) const;
  bool isEqualTo(const BigInt rhnumber) const;
  bool notEqualTo(const BigInt rhnumber) const;
  bool isLessOrEqualTo(const BigInt rhnumber) const;
  bool isMoreOrEqualTo(const BigInt rhnumber) const;

  /* Validation */

  bool isValidString(std::string str);

  /* Utils */
  static int parseInt(char c);

  std::string toString();

  void print();

  // TODO: Change to private later
private:
  void changeDigit(int index, int value);
  void setDigit(int index, int value);
  void setDigit(int index, char value);

  void push(int value);
  void push(char value);

  char getCharAt(int index);

  /* Getters and setters */
  bool getSign() const;
  void setSign(const bool sign);
  void setSign(const char sign);

  int getDigit(int index) const;

  int getHighestDigit(int index);
  std::string getNDigitsFromHighest(int n);
  std::string getNDigitsFromLowest(int n);
  int getLength();
  int getSignMult() const;
  int getNumberOfDigits() const;
  bool isDigit(char c);

  void allocateVector(int size);
};
