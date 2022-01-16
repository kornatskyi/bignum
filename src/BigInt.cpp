#include "BigInt.h"
#include <cmath>
#include <string>

/* Constructors */
BigInt::BigInt() {
  // Initialize _digits to the null values
  // for (int i = 0; i < LENGTH; i++) {
  //   _digits[i] = '0';
  // }
  // _digits.push_back('0);
}

BigInt::BigInt(int initial) : BigInt() {

  // Special case when initial == 0
  if (initial == 0) {
    _digits.push_back('0');
    return;
  }

  // Cheking sign of the given number
  if (initial < 0) {
    _sign = false;
    initial *= -1;
  }

  // Transform integer to the _digits array
  int digit;
  int i = 0;
  while (initial != 0) {
    digit = initial % 10;
    initial = (initial - digit) / 10;
    char c = '0' + digit;
    _digits.push_back(c);
    i++;
  }
}

BigInt::BigInt(std::string digits) : BigInt() {
  if (!isValidString(digits)) {
    std::cout << "Cannot create number of this string: " + digits << std::endl;
    return;
  }

  // Sign correction. If sign exists start do iteration to the sign index
  // (0)
  int sC = 0;
  if (digits[0] == '-' || digits[0] == '+') {
    _sign = (digits[0] == '-' ? false : true);
    sC++;
  }

  int j = digits.size() - 1;
  for (int i = 0; i < digits.size() - sC; i++) {
    setDigit(i, digits[j]);
    j--;
  }
}

BigInt::BigInt(const char *digits) {
  int i = 0;
  // Counting char array length
  while (digits[i] != '\0') {
    i++;
  }

  while (i > 0) {
    i--;
    push(digits[i]);
  }
}

/* Operator overloading */
// Assignment
const BigInt &BigInt::operator=(int initial) {
  *this = BigInt(initial);
  return *this;
}
const BigInt &BigInt::operator=(std::string initial) {
  *this = BigInt(initial);
  return *this;
}
const BigInt &BigInt::operator=(const char *initial) {
  *this = BigInt(initial);
  return *this;
}

void BigInt::print() { std::cout << toString() << std::endl; }

/* Public utils methods*/

std::string BigInt::toString() {
  bool isPadding = true;
  std::string str;

  for (int i = _digits.size() - 1; i >= 0; i--) {
    if (!this->getCharAt(i) || (this->getCharAt(i) == '0' && isPadding)) {
      continue;
    }

    if (this->getCharAt(i)) {
      isPadding = false;
    }

    str = str + this->getCharAt(i);
    // std::cout << c;
  }
  if (str == "") {
    return "0";
  }
  // Printing a minus sign
  if (_sign == false) {
    str = '-' + str;
  }
  // If all values are 0 or \0 and firs digit is 0 return "0"
  if (str.length() == 0 && this->getCharAt(0) == '0') {
    return "0";
  }
  return str;
}

char BigInt::getCharAt(int index) { return _digits.at(index); }

void BigInt::setDigit(int index, char value) {
  if (index >= _digits.size()) {
    _digits.resize(index + 1, 0);
  }
  this->_digits.at(index) = value;
}

/* Private Utils */

void BigInt::push(int value) { _digits.push_back(value + '0'); }
void BigInt::push(char value) { _digits.push_back(value); }

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
