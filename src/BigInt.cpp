#include "BigInt.h"
#include <string>

BigInt::BigInt() {
  // Initialize _digits to the null values
  for (int i = 0; i < LENGTH; i++) {
    _digits[i] = '\0';
  }
}

BigInt::BigInt(int initial) : BigInt() {

  // Special case when initial == 0
  if (initial == 0) {
    _digits[LENGTH - 1] = '0';
    return;
  }

  // Cheking sign of the given number
  if (initial < 0) {
    _sign = '-';
    initial *= -1;
  }

  // Transform integer to the _digits array
  int digit;
  int i = sizeof(_digits) / sizeof(_digits[0]);
  while (initial != 0) {
    digit = initial % 10;
    initial = (initial - digit) / 10;
    char c = '0' + digit;
    _digits[i - 1] = c;
    i--;
  }
}
BigInt::BigInt(std::string digits) : BigInt() {
  // Sign correction. If sign exists start do iteration to the sign index (0)
  int sC = 0;
  if (digits[0] == '-' || digits[0] == '+') {
    _sign = digits[0];
    sC++;
  }

  int j = LENGTH - 1;
  for (int i = digits.size() - 1; i >= sC; i--) {

    _digits[j] = digits[i];
    j--;
  }
}

void BigInt::print() {
  std::string str;
  for (char c : _digits) {
    if (!c)
      continue;

    str += c;
    // std::cout << c;
  }
  // Printing a minus sign
  if (_sign == '-') {
    str = '-' + str;
  }
  std::cout << str << std::endl;
}

// void setNumber(int number) {

// }
// void setNumber(char *number) {}
// void setNumber(std::string number) {}

BigInt BigInt::add(BigInt rhnumber) {

  BigInt sum;
  return sum;
}
BigInt BigInt::substruct(BigInt rhnumber) {
  BigInt difference;
  return difference;
}
BigInt BigInt::multiply(BigInt rhnumber) {
  BigInt product;
  return product;
}
BigInt BigInt::divide(BigInt rhnumber) {
  BigInt quotient;
  return quotient;
}
