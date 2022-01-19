#pragma once
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class BigInt {
private:
  std::vector<char> _digits;
  bool _sign = true;

public:
  /* Constructors */
  BigInt();
  BigInt(int initial);
  BigInt(std::string digits);
  BigInt(const char *digits);
  BigInt(const std::vector<int> initial);

  /* Operator overloading */

  // Assignment
  const BigInt &operator=(int initial);
  const BigInt &operator=(std::string initial);
  const BigInt &operator=(const char *initial);
  const BigInt &operator=(const std::vector<int> initial);

  // Comparison
  bool operator==(const BigInt &rhs) const;
  bool operator!=(const BigInt &rhs) const;
  bool operator<(const BigInt &rhs) const;
  bool operator<=(const BigInt &rhs) const;
  bool operator>(const BigInt &rhs) const;
  bool operator>=(const BigInt &rhs) const;

  // Arithmetics
  BigInt operator+(const BigInt rhnumber) const;
  BigInt operator-(const BigInt rhnumber) const;
  BigInt operator*(BigInt rhnumber) const;
  BigInt operator/(BigInt rhnumber) const;
  BigInt operator%(BigInt rhnumber) const;

  // Arithmetic assignments
  BigInt &operator+=(const BigInt &);
  BigInt &operator-=(const BigInt &);
  BigInt &operator*=(const BigInt &);
  BigInt &operator/=(const BigInt &);
  BigInt &operator%=(const BigInt &);

  // Incrementing/Decrementing
  BigInt &operator++();   // pre-increment
  BigInt &operator--();   // pre-decrement
  BigInt operator++(int); // post-increment
  BigInt operator--(int); // post-decrement

  // Unary operators
  BigInt operator+();
  BigInt operator-();

  /* Input/Output operators */
  friend std::istream &operator>>(std::istream &, BigInt &bigInt);
  friend std::ostream &operator<<(std::ostream &out, const BigInt &bigInt);

  /* Utils */
  bool getSign() const;
  std::string toString() const;
  int length() const;

private:
  /* Validation */
  bool isValidString(std::string str);

  void setDigit(int index, int value);
  void setDigit(int index, char value);

  void push(int value);
  void push(char value);

  char getCharAt(int index) const;

  /* Setters */
  void setSign(const bool sign);
  void setSign(const char sign);

  int getNthLSD(int index) const;

  int getNthMSD(int index) const;
  std::string getNMSD(int n) const;

  int getSignMult() const;

  bool isDigit(char c);

  void removeLeadingZeros();

  void allocateVector(int size);
};
