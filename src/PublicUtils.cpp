#include "BigInt.hpp"
#include <string>

/*** Public utils methods ***/

/**
 * Returns n-th least significant digit(LSD)
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * @param n-index of a digit starting from lowest grade and up.
 * Example: num = 1234567890, num.getNthLSD(2) -> 8, num.getNthLSD(0) -> 0;
 * @return int digit under the index(n) or 0 if index(n) is out of bounds
 */
int BigInt::getNthLSD(int n) const {

  if (n < 0 || n > length() - 1) {
    return 0;
  }
  // return 0 if index is out of vector scope
  if (_digits[n] == '\0' || _digits[n] == '\000' || !_digits[n]) {
    return 0;
  }

  return _digits[n] - '0';
}

/**
 * Returns number of digits in the number without counting a sign
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * Example: num1 = 1234, num1.length() -> 4; num2 = 0; num.length(0) -> 1;
 * num3 num3.length() -> 0;
 * @return int
 */
int BigInt::length() const { return _digits.size(); }

/**
 * Returns bool value depending on the number sign
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * @return bool where false is '-' and true is '+'
 */
bool BigInt::getSign() const { return _sign; }

/**
 * Returns string representation of a number including a sign
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * @return std::string
 */
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

/**
 * Converts BigInt to integer
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * std::stoi thoughts an error if string number is more then int size
 * @return int
 */
int BigInt::toInteger() const { return std::stoi(toString()); }
