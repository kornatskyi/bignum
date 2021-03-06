#include "BigInt.hpp"
#include <algorithm>
#include <stdexcept>
#include <string>

/*** Constructors ***/

/**
 * Default
 * ¯¯¯¯¯¯¯
 */
BigInt::BigInt() {}

/**
 * int -> BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt::BigInt(int initial) : BigInt() {

  // Special case when initial == 0
  if (initial == 0) {
    _digits = {'0'};

    return;
  }

  // Cheking sign of the given number
  if (initial < 0) {
    _sign = false;
    initial *= -1;
  }

  // Push each digit to the _digits vector, starting with lowest digit
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

/**
 * std::string -> BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt::BigInt(std::string digits) : BigInt() {

  // If the string is empty the digits vector will remain empty as well
  if (digits.length() == 0) {
    return;
  }
  // Is string consist of one zero char, set digits to the {'0'} vector
  if(digits.length() == 1 && digits[0] == '0') {
    _digits = {'0'};
    return;
  } 

  // Removing leading zeroes on the string
  int k = 0;
  while (digits[k] == '0') {
    digits = digits.substr(1, digits.length() - 1);
    k++;
  }
  // Check the firs char of the string
  // if it is a sign char set this sign to the BigInt and
  // set value of signCorrection to 1
  int signCorrection = 0;
  if (digits[0] == '-' || digits[0] == '+') {
    setSign((digits[0] == '-' ? false : true));
    signCorrection = 1;
  }

  int i = digits.size();
  // Pushing each char to the _digits vector
  while (i > signCorrection) {
    i--;
    push(digits[i]);
  }
}

/**
 * char* -> BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt::BigInt(const char *digits) {

  int i = 0;
  // Check the firs char of the array
  // if it is a sign char set this sign to the BigInt and
  // set value of signCorrection to 1
  int signCorrection = 0;
  if (digits[0] == '-' || digits[0] == '+') {
    setSign((digits[0] == '-' ? false : true));
    signCorrection++;
  }

  // Counting char array length
  while (digits[i] != '\0') {
    i++;
  }
    // Is string consist of one zero char, set digits to the {'0'} vector
  if(i == 1 && digits[0] == '0') {
    _digits = {'0'};
    return;
  } 
  std::string sdigits = "";
  bool firsZeroes = true;
  for (int j = 0; j < i; j++) {
    if (digits[j] == 0 && firsZeroes) {
      continue;
    }
    sdigits = sdigits + digits[j];
    firsZeroes = false;
  }

  *this = sdigits;
}

/**
 * float -> BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt::BigInt(float initial) { (*this) = std::to_string((int)initial); }
/**
 * double -> BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt::BigInt(double initial) { (*this) = std::to_string((long)initial); }
/**
 * long -> BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt::BigInt(long initial) { (*this) = std::to_string(initial); }
/**
 * long long -> BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt::BigInt(long long initial) { (*this) = std::to_string(initial); }

/**
 * vector -> BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * Will reverse vector.
 * Example: vector == [3, 7, 2] -> _digits == [2, 7 ,3]
 */
BigInt::BigInt(std::vector<int> initialReversed) : BigInt() {

  for (int var = initialReversed.size() - 1; var >= 0; var--) {
    _digits.push_back(initialReversed[var] + '0');
  }
  removeLeadingZeros();
}
