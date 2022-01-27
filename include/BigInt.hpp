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
  BigInt(float initial);
  BigInt(double initial);
  BigInt(long initial);
  BigInt(long long initial);
  BigInt(std::string digits);
  BigInt(const char *digits);
  BigInt(const std::vector<int> initial);

  /* Operator overloading */

  // Assignment
  const BigInt &operator=(int initial);
  const BigInt &operator=(float initial);
  const BigInt &operator=(double initial);
  const BigInt &operator=(long initial);
  const BigInt &operator=(long long initial);
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
  BigInt operator+(const BigInt &rhn) const;
  BigInt operator-(const BigInt &rhn) const;
  BigInt operator*(const BigInt &rhn) const;
  BigInt operator/(const BigInt &rhn) const;
  BigInt operator%(const BigInt &rhn) const;

  /* Multiplication algorithms */
  BigInt longMultiplication(const BigInt &rhn) const;
  BigInt karatsubaMultiplication(const BigInt &rhn) const;

  // Arithmetic assignments
  BigInt &operator+=(const BigInt &rhn);
  BigInt &operator-=(const BigInt &rhn);
  BigInt &operator*=(const BigInt &rhn);
  BigInt &operator/=(const BigInt &rhn);
  BigInt &operator%=(const BigInt &rhn);

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
  int toInteger() const;

private:
  /* Getters */
  BigInt multiplyByTenth(int n) const;

  BigInt abs() const;

  char getCharAt(int index) const;

  int getNthLSD(int index) const;
  int getNthMSD(int index) const;

  std::string getNMSD(int n) const;
  std::string getNLSD(int n) const;

  int getSignMult() const;

  /* Setters */
  void setDigit(int index, int value);
  void setDigit(int index, char value);

  void setSign(const bool sign);
  void setSign(const char sign);

  /* Private Utils  */
  void push(int value);
  void push(char value);

  bool isDigit(char c);

  void removeLeadingZeros();

  void allocateVector(int size);

  /* Validation */
  bool isValidString(std::string str);
};
// Math
BigInt power(const BigInt base, const int power);