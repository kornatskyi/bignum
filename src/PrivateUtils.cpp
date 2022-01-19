#include "../include/BigInt.hpp"

/*

*** Private Utils ***

*/
int BigInt::getHighestDigit(int index) const {

  if (index < 0 || index >= getNumberOfDigits()) {
    return 0;
  }

  return _digits[getNumberOfDigits() - index - 1] - '0';
}

std::string BigInt::getNDigitsFromHighest(int index) const {

  std::vector<char> slice =
      std::vector<char>(_digits.end() - index, _digits.end());

  std::string result;

  for (int i = 0; i < slice.size(); i++) {
    result = slice[i] + result;
  }

  return result;
}

int BigInt::getSignMult() const { return (_sign ? 1 : -1); }

void BigInt::setSign(char sign) {
  if (sign != '-' && sign != '+') {
    throw "Wrong sign character in setSign() method";
  }

  _sign = (sign == '-' ? false : true);
}

void BigInt::push(int value) { _digits.push_back(value + '0'); }

void BigInt::push(char value) { _digits.push_back(value); }

char BigInt::getCharAt(int index) const { return _digits.at(index); }

void BigInt::setDigit(int index, char value) {
  if ((value - '0') > 9 || (value - '0') < 0) {
    std::cout << value << std::endl;
    // throw "[setDigit()]: Value must be >= 0 and <= 9";
  }
  // Allocating more space if needed
  if (index >= _digits.size()) {
    _digits.resize(index + 1, '0');
  }
  this->_digits.at(index) = value;
}

void BigInt::setDigit(int index, int value) {

  if (value > 9 || value < 0) {
    throw "[setDigit()]: Value must be >= 0 and <= 9";
  }
  // Allocating more space if needed
  if (index >= _digits.size()) {
    _digits.resize(index + 1, '0');
  }
  this->_digits[index] = value + '0';
}

void BigInt::allocateVector(int size) { _digits.resize(size, 0); }

void BigInt::removeLeadingZeros() {
  while (_digits.size() != 1 &&
         (_digits.back() == '0' || _digits.back() == '\0' ||
          _digits.back() == '\000')) {
    _digits.pop_back();
  }
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