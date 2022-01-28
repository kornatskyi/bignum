#include "BigInt.hpp"

/*** Private Utils ***/
/* Get absolute value */
BigInt BigInt::abs() const {
  BigInt result;
  result._digits = _digits;
  return result;
}

BigInt BigInt::multiplyByTenth(int n) const {
  if ((*this) == 0) {
    return 0;
  }
  std::string result = (*this).toString();
  for (int i = 0; i < n; i++) {
    result += "0";
  }
  return result;
}

/**
 * Returns n-th most significant digit(MSD)
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * @param n-index of a digit starting from highest grade and down.
 * Example: num = 1234567890, num.getNthMSD(2) -> 3,
 * num.getNthMSD(0) -> 1;
 * @return int digit under the index(n) from the end or 0 if index(n) is out of
 * bounds
 */
int BigInt::getNthMSD(int n) const {

  if (n < 0 || n >= length()) {
    return 0;
  }
  return _digits[length() - n - 1] - '0';
}

/**
 * Returns n most significant digits(MSD)
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * @param n-represents how many digits will be returned
 * @return std::string with n most significant digits
 */
std::string BigInt::getNMSD(int n) const {
  if (length() == 0) {
    return "";
  }

  if (n < 0) {
    return "0";
  }

  std::vector<char> slice = std::vector<char>(_digits.end() - n, _digits.end());

  std::string result = "";

  for (int i = 0; i < slice.size(); i++) {
    result = slice[i] + result;
  }
  BigInt res = result;
  res.removeLeadingZeros();
  return res.toString();
}
/**
 * Returns n least significant digits(LSD)
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * @param n-represents how many digits will be returned
 * @return std::string with n least significant digits
 */
std::string BigInt::getNLSD(int n) const {
  if (n > length()) {
    return toString();
  }

  std::vector<char> slice =
      std::vector<char>(_digits.begin(), _digits.end() - (length() - n));

  std::string result;

  for (int i = 0; i < slice.size(); i++) {
    result = slice[i] + result;
  }
  BigInt res = result;
  res.removeLeadingZeros();
  return res.toString();
}

/**
 * Sets number's sign
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * @param sign-bool value, true -> '+' false -> '-'
 */
void BigInt::setSign(const bool sign) { _sign = sign; }

/**
 * Returns 1 or -1 depending on a digit sign
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * @return int - '+' -> 1, '-' -> -1
 */
int BigInt::getSignMult() const { return (_sign ? 1 : -1); }

/**
 * Sets number's sign
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * @param sign-char value, '+' -> '+'  '-' -> '-'
 */
void BigInt::setSign(char sign) {
  if (sign != '-' && sign != '+') {
    throw "Wrong sign character in setSign() method";
  }

  _sign = (sign == '-' ? false : true);
}

/**
 * Pushes digit to the _digits vector
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * @param value - int value, should be a digit
 */
void BigInt::push(int value) { _digits.push_back(value + '0'); }

/**
 * Pushes digit to the _digits vector
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * @param value - char value, should be a digit
 */
void BigInt::push(char value) { _digits.push_back(value); }

/**
 * Get char at index
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * @param index - index of a digit if _digits vector
 */
char BigInt::getCharAt(int index) const { return _digits.at(index); }

/**
 * Set a digit on index
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * @param index - int index on which value will be setted in _digits vector
 * @param value - char value, must be a digit
 */
void BigInt::setDigit(int index, char value) {
  if ((value - '0') > 9 || (value - '0') < 0) {
    throw "[setDigit()]: Value must be >= 0 and <= 9";
  }
  // Allocating more space if needed
  if (index >= _digits.size()) {
    _digits.resize(index + 1, '0');
  }
  this->_digits.at(index) = value;
}

/**
 * Set a digit on index
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * @param index - int index on which value will be setted in _digits vector
 * @param value - int value, must be a digit
 */
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

/**
 * Allocating more space in _digits vector
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * @param size - int value which represents allocation size
 */
void BigInt::allocateVector(int size) { _digits.resize(size, 0); }

/**
 * Removes zeros from the leading positions
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
void BigInt::removeLeadingZeros() {
  if (length() == 0) {
    return;
  }
  while (_digits.size() != 1 &&
         (_digits.back() == '0' || _digits.back() == '\0' ||
          _digits.back() == '\000')) {
    _digits.pop_back();
  }
}

/* Validation */

/**
 * Validates is string is a valid number
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
bool BigInt::isValidString(std::string str) {

  bool isValid = false;
  int hasSign = 0;
  if (str.length() == 0) {
    return true;
  }
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