#include "../include/BigInt.hpp"
#include <iterator>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
/*

*** Arithmetical operations ***

*/

BigInt &BigInt::operator+=(const BigInt &rhnumber) {
  *this = add(rhnumber);
  return *this;
}
BigInt &BigInt::operator-=(const BigInt &rhnumber) {
  *this = substruct(rhnumber);
  return *this;
}
BigInt &BigInt::operator*=(const BigInt &rhnumber) {
  *this = multiply(rhnumber);
  return *this;
}
BigInt &BigInt::operator/=(const BigInt &rhnumber) {
  *this = divide(rhnumber);
  return *this;
}
BigInt &BigInt::operator%=(const BigInt &rhnumber) {
  *this = modulus(rhnumber);
  return *this;
}

BigInt &BigInt::operator++() {
  *this = add(BigInt(1));
  return *this;
} // pre-increment
BigInt &BigInt::operator--() {
  *this = substruct(BigInt(1));
  return *this;
} // pre-decrement
BigInt BigInt::operator++(int) {
  BigInt res = *this;
  *this = add(BigInt(1));
  return res;
} // post-increment
BigInt BigInt::operator--(int) {
  BigInt res = *this;
  *this = substruct(BigInt(1));
  return res;
} // post-decrement

BigInt BigInt::operator+(const BigInt rhnumber) const { return add(rhnumber); };
BigInt BigInt::operator-(const BigInt rhnumber) const {
  return substruct(rhnumber);
}
BigInt BigInt::operator*(const BigInt rhnumber) const {
  return multiply(rhnumber);
}

BigInt BigInt::operator/(const BigInt rhnumber) const {
  return divide(rhnumber);
}

BigInt BigInt::operator%(const BigInt rhnumber) const {
  return modulus(rhnumber);
}

BigInt BigInt::add(const BigInt rhnumber) const {

  BigInt n1 = *this;
  BigInt n2 = rhnumber;
  BigInt result;
  // tests.isEqualToBrootTest();

  // Initialising sings multipliers to -1 if '-' or 1 if '+'
  int n1sm = n1.getSignMult();
  int n2sm = n2.getSignMult();

  if (n1sm > 0 && n2sm < 0) {
    BigInt local = n2;
    local.setSign('+');
    return n1.substruct(local);
  }

  if (n1sm < 0 && n2sm > 0) {
    BigInt local = n1;
    local.setSign('+');
    return n2.substruct(local);
  }

  int carry = 0;

  int resLength = std::max(n1.getNumberOfDigits(), n2.getNumberOfDigits()) + 1;
  // Allocating enough space for the result
  result.allocateVector(resLength);

  for (int i = 0; i < resLength; i++) {
    int res = carry;

    if (i < n1.getNumberOfDigits()) {
      res = res + n1.getDigit(i);
    }
    if (i < n2.getNumberOfDigits()) {
      res = res + n2.getDigit(i);
    }
    if (res >= 10) {
      res = res - 10;
      carry = 1;
    } else {
      carry = 0;
    }
    result.setDigit(i, res);
  }
  // If both numbers is negative the sum will be negative as well
  //  -n1 + -n2 = -(n1 + n2)
  if (n1.getSignMult() < 0 && n2.getSignMult() < 0) {
    result.setSign('-');
  }

  return result;
}

BigInt BigInt::substruct(const BigInt rhnumber) const {

  BigInt n1;
  BigInt n2;
  // Switch numbers is left number less then right
  // to be able to use subtraction algorithm
  BigInt abs1 = (*this);
  abs1.setSign('+');
  BigInt abs2 = rhnumber;
  abs2.setSign('+');
  BigInt result;
  if (abs1.isLessThen(abs2)) {
    n1 = rhnumber;
    n2 = *this;
  } else {
    n1 = *this;
    n2 = rhnumber;
  }

  if ((*this).isLessThen(rhnumber)) {
    result.setSign('-');
  } else {
    result.setSign('+');
  }

  // Initialising sings multipliers to -1 if '-' or 1 if '+'
  int n1sm = (*this).getSignMult();
  int n2sm = rhnumber.getSignMult();

  if (n2sm < 0 && n1sm > 0) {
    BigInt local = rhnumber;
    local.setSign('+');
    return (*this).add(local);
  }
  if (n1sm < 0 && n2sm > 0) {
    BigInt local = rhnumber;
    local.setSign('-');
    return (*this).add(local);
  }

  int carry = 0;

  int resLength = std::max(n1.getNumberOfDigits(), n2.getNumberOfDigits());
  // Allocating enough space for the result
  result.allocateVector(resLength);

  for (int i = 0; i < resLength; i++) {
    int res = 10 + n1.getDigit(i);

    if (n1.getNumberOfDigits() > i) {
      res = res - carry - n2.getDigit(i);

      if (res < 10) {
        // res = res * (-1);

        carry = 1;
      } else {
        carry = 0;
      }

      res = res % 10;
      // std::cout << res << std::endl;

      result.setDigit(i, res);
    }
  }
  result.removeLeadingZeros();
  return result;
}

/*
 *
 * O(n^2) multiplication algorithm
 * TODO: Change to Karatsuba's algorithm in the future
 *
 */

BigInt BigInt::multiply(const BigInt rhnumber) const {

  BigInt result;
  int carryOver = 0;

  for (int i = 0; i <= getNumberOfDigits(); i++) {
    BigInt temp;
    for (int j = 0; j <= rhnumber.getNumberOfDigits(); j++) {
      int mult = (getDigit(i) * rhnumber.getDigit(j)) + carryOver;

      carryOver = mult / 10;
      temp.setDigit(j + i, mult % 10);
    }
    result = result.add(temp);
  }

  if ((getSignMult() * rhnumber.getSignMult()) == -1) {
    result.setSign('-');
  }

  return result;
}

/**
 * @brief

 * Lets use next example: *this = 173; rhnumber = -13;
 */

BigInt BigInt::divide(const BigInt rhnumber) const {

  if (rhnumber == BigInt(0)) {
    throw std::runtime_error("Math error: Attempted to divide by Zero\n");
  }
  /* Creating copies of initial values */
  BigInt dividend = *this;   //< 173
  BigInt divisor = rhnumber; //< -13

  /* Setting absolute values */
  dividend.setSign(true); //< 173
  divisor.setSign(true);  //< 13

  /* Check if dividend less the divisor */
  if (dividend < divisor) {
    return 0;
  }

  /* Check if absolute values are equal */
  if (dividend == divisor) {
    /* Setting a sign */
    if ((*this).getSign() != rhnumber.getSign()) {
      return -1;
    }
    return 1;
  }

  /**
   * Creating temDividend variable which will work kind of like a sliding
   * window. Two nested while loops firs one slides the window,
   * second one counts tempQuotient on current step.
   * On each upper loop adding tempQuotient to the vector
   * and in the end conver the vector to the result object
   */
  BigInt tempDividend = getNDigitsFromHighest(divisor.getNumberOfDigits());

  /* Will iterate difference between dividend and divisor lendth. n ==
    dividend.size() -  divisor.size() Example: 173.size() - 13.size() == 1 */
  int i = divisor.getNumberOfDigits(); //< 2   // because (13).size() == 2

  // This vector will contain every quotient digit
  std::vector<int> res;

  while (i <= dividend.getNumberOfDigits()) {

    /* After each nested loop will represend how many times divisor fits into
     tempDivident */
    int tempQuotient = 0;

    /* every time, except the firs one, reassigning tempDividend to
     tempDivident plus one digit (sliding window) */
    if (i > divisor.getNumberOfDigits()) {
      /* convert previos tempDivident to the string */
      std::string prevTempDividentStr =
          tempDividend == 0 ? "" : tempDividend.toString();
      /* Getting next digit in devident as a string */
      std::string nextDigit = std::to_string(
          getHighestDigit(i - 1)); //< Getting next digit from the divident

      /* Reassigning tempDevident to previos value that left after division and
        next digit */
      /* Example: on the second iteration (because on firs loop this if
         statement will always be skiped )
         prevTempDividentSrt = 5 (because we did 17 - 13 on firs iteration.)
         nextDigit = 3 (because dividend.getNextDigit() == 3)
         so tempDivident = "5" + "3" => 53
         will repeat loop
       */
      tempDividend = prevTempDividentStr + nextDigit;
    }
    /* Performing subtraction-assignment operation until tempDivident >= divisor
      Example: for firs loop when tempDivident == 17 and divisor == 13
      loop will iterate only once ( (17 - 13) <= 13 )
     */
    while (tempDividend >= divisor) {
      tempDividend -= divisor;
      tempQuotient++;
    }
    i++;
    /* Storing quotient value to vector */
    res.push_back(tempQuotient);
  }

  /* Vector to BigInt */
  BigInt result = res;

  /* Checking a sign */
  if ((*this).getSign() != rhnumber.getSign()) {
    result.setSign(false);
  }

  return result;
}

// TODO
BigInt BigInt::modulus(const BigInt rhnumber) const { return rhnumber; }

/*























*/

/* Constructors */
BigInt::BigInt() {
  // Initialize _digits to the null values
  // for (int i = 0; i < LENGTH; i++) {
  //   _digits[i] = '0';
  // }
  // _digits.push_back('0);
}
/*

  int -> BigInt
  ¯¯¯¯¯¯¯¯¯¯¯¯¯
*/
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

/*

  std::string -> BigInt
  ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
*/
BigInt::BigInt(std::string digits) : BigInt() {
  if (!isValidString(digits)) {
    std::cout << "Cannot create number of this string: " + digits << std::endl;
    return;
  }

  // Sign correction. If sign exists start do iteration to the sign index
  // (0)
  int sC = 0;
  if (digits[0] == '-' || digits[0] == '+') {
    setSign((digits[0] == '-' ? false : true));
    sC++;
  }

  int j = digits.size() - 1;
  for (int i = 0; i < digits.size() - sC; i++) {
    setDigit(i, digits[j]);
    j--;
  }
}

/*

  char* -> BigInt
  ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
*/
BigInt::BigInt(const char *digits) {

  if (!isValidString(digits)) {
    std::cout << "Cannot create number of this string: " + std::string(digits)
              << std::endl;
    return;
  }
  int i = 0;
  // Sign correction. If sign exists start do iteration to the sign index
  // (0)
  int sC = 0;

  if (digits[0] == '-' || digits[0] == '+') {
    setSign((digits[0] == '-' ? false : true));
    sC++;
  }

  // Counting char array length
  while (digits[i] != '\0') {
    i++;
  }

  while (i > sC) {
    i--;
    push(digits[i]);
  }
}

BigInt::BigInt(std::vector<int> initialReversed) : BigInt() {

  for (int var = initialReversed.size() - 1; var >= 0; var--) {
    _digits.push_back(initialReversed[var] + '0');
  }
  removeLeadingZeros();
}

/*

*** Assignment operators overloading ***

 */
const BigInt &BigInt::operator=(const int initial) {
  *this = BigInt(initial);
  return *this;
}
const BigInt &BigInt::operator=(const std::string initial) {
  *this = BigInt(initial);
  return *this;
}
const BigInt &BigInt::operator=(const char *initial) {
  *this = BigInt(initial);
  return *this;
}

const BigInt &BigInt::operator=(const std::vector<int> initialReversed) {
  *this = BigInt(initialReversed);
  return *this;
}

/*

*** Comparison operators overloading ***

*/
bool BigInt::operator==(const BigInt &rhnumber) const {
  return isEqualTo(rhnumber);
}

bool BigInt::operator>(const BigInt &rhnumber) const {
  return isMoreThen(rhnumber);
}

bool BigInt::operator<(const BigInt &rhnumber) const {
  return isLessThen(rhnumber);
}

bool BigInt::operator!=(const BigInt &rhnumber) const {
  return notEqualTo(rhnumber);
}

bool BigInt::operator<=(const BigInt &rhnumber) const {
  return isLessOrEqualTo(rhnumber);
}

bool BigInt::operator>=(const BigInt &rhnumber) const {
  return isMoreOrEqualTo(rhnumber);
}

/*

*** Comparison methods ***

*/
bool BigInt::isEqualTo(const BigInt rhnumber) const {

  if (getSign() != rhnumber.getSign() ||
      getNumberOfDigits() != rhnumber.getNumberOfDigits()) {
    return false;
  }

  for (int i = 0; i < getNumberOfDigits(); i++) {
    if (getDigit(i) != rhnumber.getDigit(i)) {
      return false;
    }
  }
  return true;
}
bool BigInt::isMoreThen(const BigInt rhnumber) const {

  if (getSign() && !rhnumber.getSign()) {
    return true;
  }
  if (!getSign() && rhnumber.getSign()) {
    return false;
  }

  if (getNumberOfDigits() > rhnumber.getNumberOfDigits()) {
    return getSign() ? true : false;
  }

  if (getNumberOfDigits() < rhnumber.getNumberOfDigits()) {
    return getSign() ? false : true;
  }

  for (int i = getNumberOfDigits() - 1; i >= 0; i--) {
    if (getDigit(i) < rhnumber.getDigit(i)) {
      return getSign() ? false : true;
    }
    if (getDigit(i) > rhnumber.getDigit(i)) {
      return getSign() ? true : false;
    }
  }
  return false;
}
bool BigInt::isLessThen(const BigInt rhnumber) const {

  if (getSign() && !rhnumber.getSign()) {
    return false;
  }
  if (!getSign() && rhnumber.getSign()) {
    return true;
  }

  if (getNumberOfDigits() > rhnumber.getNumberOfDigits()) {
    return getSign() ? false : true;
  }

  if (getNumberOfDigits() < rhnumber.getNumberOfDigits()) {
    return getSign() ? true : false;
  }

  for (int i = getNumberOfDigits() - 1; i >= 0; i--) {
    if (getDigit(i) < rhnumber.getDigit(i)) {
      return getSign() ? true : false;
    }
    if (getDigit(i) > rhnumber.getDigit(i)) {
      return getSign() ? false : true;
    }
  }
  return false;
}
bool BigInt::notEqualTo(const BigInt rhnumber) const {

  if (getSign() != rhnumber.getSign() ||
      getNumberOfDigits() != rhnumber.getNumberOfDigits()) {
    return true;
  }

  for (int i = 0; i < getNumberOfDigits(); i++) {
    if (getDigit(i) != rhnumber.getDigit(i)) {
      return true;
    }
  }
  return false;
}
bool BigInt::isLessOrEqualTo(const BigInt rhnumber) const {
  if (getSign() && !rhnumber.getSign()) {
    return false;
  }
  if (!getSign() && rhnumber.getSign()) {
    return true;
  }

  if (getNumberOfDigits() > rhnumber.getNumberOfDigits()) {
    return getSign() ? false : true;
  }

  if (getNumberOfDigits() < rhnumber.getNumberOfDigits()) {
    return getSign() ? true : false;
  }

  for (int i = getNumberOfDigits() - 1; i >= 0; i--) {
    if (getDigit(i) < rhnumber.getDigit(i)) {
      return getSign() ? true : false;
    }
    if (getDigit(i) > rhnumber.getDigit(i)) {
      return getSign() ? false : true;
    }
  }
  return true;
}
bool BigInt::isMoreOrEqualTo(const BigInt rhnumber) const {
  if (getSign() && !rhnumber.getSign()) {
    return true;
  }
  if (!getSign() && rhnumber.getSign()) {
    return false;
  }

  if (getNumberOfDigits() > rhnumber.getNumberOfDigits()) {
    return getSign() ? true : false;
  }

  if (getNumberOfDigits() < rhnumber.getNumberOfDigits()) {
    return getSign() ? false : true;
  }

  for (int i = getNumberOfDigits() - 1; i >= 0; i--) {
    if (getDigit(i) < rhnumber.getDigit(i)) {
      return getSign() ? false : true;
    }
    if (getDigit(i) > rhnumber.getDigit(i)) {
      return getSign() ? true : false;
    }
  }
  return true;
}

/*

*** Public utils methods ***

*/

int BigInt::getDigit(int index) const {

  // return 0 if index is out of vector scope
  if (_digits[index] == '\0' || _digits[index] == '\000' || !_digits[index] ||
      index > getNumberOfDigits() - 1) {
    return 0;
  }

  return this->_digits[index] - '0';
}

int BigInt::getNumberOfDigits() const { return _digits.size(); }

bool BigInt::getSign() const { return _sign; }

void BigInt::setSign(const bool sign) { _sign = sign; }

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
  if (getSign() == false) {
    str = '-' + str;
  }
  // If all values are 0 or \0 and firs digit is 0 return "0"
  if (str.length() == 0 && this->getCharAt(0) == '0') {
    return "0";
  }
  return str;
}

// Prints number to the console
void BigInt::print() { std::cout << toString() << std::endl; }

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

char BigInt::getCharAt(int index) { return _digits.at(index); }

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
