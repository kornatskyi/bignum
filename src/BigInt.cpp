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
  if (!isValidString(digits)) {
    throw "Error: Invalid string of digits";
  }

  // Sign correction. If sign exists start do iteration to the sign index
  // (0)
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

// }
// void setNumber(char *number) {}
// void setNumber(std::string number) {}

BigInt BigInt::add(BigInt rhnumber) {
  BigInt lnum = *this;
  BigInt rnum = rhnumber;
  std::string result = "";
  int leftOver = 0;

  for (int i = LENGTH - 1; i > 0; i--) {
    int sum = (int)((lnum._digits[i] == '\0' ? '0' : lnum._digits[i]) - '0') +
              (int)((rnum._digits[i] == '\0' ? '0' : rnum._digits[i]) - '0') +
              leftOver;
    if (sum > 9) {
      leftOver = 1;
      result = std::to_string((sum % 10)) + result;
    } else {
      leftOver = 0;
      result = std::to_string(sum) + result;
    }
  }
  std::cout << result << std::endl;
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

/* Validation */

bool BigInt::isValidString(std::string str) {

  bool isValid = false;
  int hasSign = 0;
  const char SIGNS[] = {
      '-',
      '+',
  };
  const char DIGITS[] = {
      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
  };
  // Check if the firs char is a sign
  if (str[0] == SIGNS[0] || str[0] == SIGNS[1]) {
    hasSign++;
  }
  // Check if firs digit isn't 0
  if (str[hasSign] == '0' && str.length() > 1 + hasSign) {
    isValid = false;
  } else {
    // Validate rest of the characters in the string
    for (int i = hasSign; i < str.length(); i++) {
      isValid = false;
      for (char c : DIGITS) {
        if (str[i] == c) {
          isValid = true;
          break;
        }
      }
      if (!isValid) {
        return isValid;
      }
    }
  }

  return isValid;
}
/*

Bottom space








*/