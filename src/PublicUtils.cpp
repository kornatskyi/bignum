#include "../include/BigInt.hpp"

/*** Public utils methods ***/

/**
 * Addition (BigInt + BigInt)
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * @param index-index of a digit starting from lowest grade and up.
 * Example: num = 1234567890, num.getDigit(2) -> 8, num.getDigit(0) -> 0;
 * @return int digit under the index or 0 if index is out of bounds
 */
int BigInt::getDigit(int index) const {

  // return 0 if index is out of vector scope
  if (_digits[index] == '\0' || _digits[index] == '\000' || !_digits[index] ||
      index > getNumberOfDigits() - 1) {
    return 0;
  }

  return _digits[index] - '0';
}

/**
 * Addition (BigInt + BigInt)
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * Example: num = 1234, num.getDigit(2) -> 8, num.getDigit(0) -> 0;
 * @return int digit under the index or 0 if index is out of bounds
 */
int BigInt::getNumberOfDigits() const { return _digits.size(); }

bool BigInt::getSign() const { return _sign; }

void BigInt::setSign(const bool sign) { _sign = sign; }

std::string BigInt::toString() const {
  bool isPadding = true;
  std::string str;

  for (int i = _digits.size() - 1; i >= 0; i--) {
    if (!getCharAt(i) || (getCharAt(i) == '0' && isPadding)) {
      continue;
    }

    if (getCharAt(i)) {
      isPadding = false;
    }

    str = str + getCharAt(i);
    // std::cout << c;
  }
  if (str == "") {
    return "0";
  }
  // Printing a minus sign
  if (getSign() == false) {
    str = '-' + str;
  }
  // If all values are 0 or \0 and firs digit is 0 return "0"
  if (str.length() == 0 && getCharAt(0) == '0') {
    return "0";
  }
  return str;
}

// Prints number to the console
void BigInt::print() const { std::cout << toString() << std::endl; }