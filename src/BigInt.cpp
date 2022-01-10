#include "BigInt.h"
#include <string>

/* Constructors */

BigInt::BigInt() {
  // Initialize _digits to the null values
  for (int i = 0; i < LENGTH; i++) {
    _digits[i] = '\0';
  }
}

BigInt::BigInt(int initial) : BigInt() {

  // Special case when initial == 0
  if (initial == 0) {
    _digits[0] = '0';
    return;
  }

  // Cheking sign of the given number
  if (initial < 0) {
    _sign = '-';
    initial *= -1;
  }

  // Transform integer to the _digits array
  int digit;
  int i = 0;
  while (initial != 0) {
    digit = initial % 10;
    initial = (initial - digit) / 10;
    char c = '0' + digit;
    _digits[i] = c;
    i++;
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

  int j = digits.size() - 1;
  for (int i = 0; i < digits.size() - sC; i++) {
    setDigit(i, digits[j]);
    j--;
  }
}

/* Private Utils */
char BigInt::getCharAt(int index) { return _digits[index]; }

int BigInt::getDigit(int index) {

  if (this->_digits[index] == '\0') {
    return 0;
  }

  return this->_digits[index] - '0';
}
void BigInt::setDigit(int index, char value) { this->_digits[index] = value; }

void BigInt::setDigit(int index, int value) {

  if (value > 9 || value < 0) {
    throw "Value must be > 0 and < 9";
  }

  this->_digits[index] = value + '0';
}
void BigInt::setSign(char sign) {
  if (!(sign != '-' || sign != '+')) {
    throw "Wrong sign character in setSign() method";
  }

  _sign = sign;
}
int BigInt::parseInt(char c) { return c - '0'; }
int BigInt::getSignMult() { return (_sign == '+' ? 1 : -1); }

/* Operations (operators in future) */

std::string BigInt::toString() {
  bool isPadding = true;
  std::string str;
  for (int i = LENGTH - 1; i >= 0; i--) {
    if (!this->getCharAt(i) || (this->getCharAt(i) == '0' && isPadding)) {
      continue;
    }

    if (this->getCharAt(i)) {
      isPadding = false;
    }

    str = str + this->getCharAt(i);
    // std::cout << c;
  }
  // Printing a minus sign
  if (_sign == '-') {
    str = '-' + str;
  }
  return str;
}
void BigInt::print() { std::cout << toString() << std::endl; }

BigInt BigInt::add(BigInt rhnumber) {

  BigInt ln = *this;
  BigInt rn = rhnumber;

  int ls = ln.getSignMult();
  int rs = rn.getSignMult();

  int temp;
  int leftOver = 0;

  BigInt result;
  for (int i = 0; i < LENGTH; i++) {

    temp = (ls * ln.getDigit(i)) + (rs * rn.getDigit(i)) + leftOver;
    if (temp > 9) {
      result.setDigit(i, temp % 10);
      leftOver = 1;
    } else if (temp < 0) {
      result.setDigit(i, -(temp % 10));
      leftOver = -1;
    } else {
      result.setDigit(i, temp);
      leftOver = 0;
    }
  }
  if (leftOver == -1) {
    result.setSign('-');
  }

  return result;
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