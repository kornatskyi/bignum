#include "BigInt.h"
#include <cmath>
#include <string>

/* Constructors */

BigInt::BigInt() {
  // Initialize _digits to the null values
  for (int i = 0; i < LENGTH; i++) {
    _digits[i] = '0';
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

/* Operations (operators in future) */

void BigInt::print() { std::cout << toString() << std::endl; }

BigInt BigInt::add(BigInt rhnumber) {

  BigInt ln = *this;
  BigInt rn = rhnumber;

  int ls = ln.getSignMult();
  int rs = rn.getSignMult();

  int temp;
  int leftOver = 0;

  ln.setSign('+');
  rn.setSign('+');

  int sign = 0;

  BigInt result;

  if (ls == rs) {

    for (int i = 0; i < getLength(); i++) {
      temp = ln.getDigit(i) + rn.getDigit(i) + leftOver;

      if (temp > 9) {
        leftOver = 1;
      } else {
        leftOver = 0;
      }
      result.setDigit(i, temp % 10);
    }
    result.setSign(ls == (-1) ? '-' : '+');
  } else if (ls == -1) {

    if (ln.isLessThen(rn)) {
      for (int i = 0; i < ln.getNumberOfDigits(); i++) {
        ln.setDigit(i, (10 - ln.getDigit(i)) % 10);
      }
    } else {
      for (int i = 0; i < rn.getNumberOfDigits(); i++) {
        rn.setDigit(i, (10 - rn.getDigit(i)) % 10);
      }
    }

    for (int i = 0; i < getLength(); i++) {
      temp = ln.getDigit(i) + rn.getDigit(i) + leftOver;

      if (temp < 10 && temp > 0) {
        leftOver = -1;
      } else {
        leftOver = 0;
      }
      result.setDigit(i, std::abs(temp % 10));
    }
    if (leftOver == 0) {
      result.setSign('-');
    }
  } else if (rs == -1) {

    if (ln.isLessThen(rn)) {
      for (int i = 0; i < ln.getNumberOfDigits(); i++) {
        ln.setDigit(i, (10 - ln.getDigit(i)) % 10);
      }
    } else {
      for (int i = 0; i < rn.getNumberOfDigits(); i++) {
        rn.setDigit(i, (10 - rn.getDigit(i)) % 10);
      }
    }
    for (int i = 0; i < getLength(); i++) {
      temp = ln.getDigit(i) + rn.getDigit(i) + leftOver;

      if (temp < 10 && temp > 0) {
        leftOver = -1;
      } else {
        leftOver = 0;
      }
      result.setDigit(i, std::abs(temp % 10));
    }
    if (leftOver == 0) {
      result.setSign('-');
    }
  }

  // // If both numbers are negative will do just regular addition and then set
  // // sign to '-'

  // for (int i = 0; i < LENGTH; i++) {
  //   temp = (ls * ln.getDigit(i)) + (rs * rn.getDigit(i)) + leftOver;
  //   if (ln.getDigit(i))
  //     std::cout << temp << std::endl;
  //   // Skip setting sign when temp == 0
  //   if (temp == 0) {
  //     result.setDigit(i, 0);
  //     continue;
  //   }
  //   if (temp > 9) {
  //     result.setDigit(i, temp % 10);
  //     leftOver = 1;
  //     sign = 1;
  //   } else if (temp < (-9)) {
  //     result.setDigit(i, -(temp % 10));
  //     leftOver = -1;
  //     sign = -1;

  //   } else {
  //     if (temp < 0) {
  //       result.setDigit(i, -(temp));
  //       leftOver = 0;
  //       sign = -1;
  //     } else {
  //       result.setDigit(i, temp);
  //       leftOver = 0;
  //       sign = 1;
  //     }
  //   }
  // }
  // if (sign == (-1)) {
  //   result.setSign('-');
  // }

  return result;
}

BigInt BigInt::substruct(BigInt rhnumber) {
  // Creating new number with minus sign, and then perform addition operation
  BigInt minusNumber("-" + rhnumber.toString());
  return add(minusNumber);
}

BigInt BigInt::multiply(BigInt rhnumber) {

  BigInt result;
  int leftOver = 0;
  for (int i = 0; i < getLength(); i++) {
    BigInt temp;
    for (int j = 0; j < getLength(); j++) {
      int mult = (getDigit(j) * rhnumber.getDigit(i)) + leftOver;
      leftOver = mult / 10;
      if ((i + j) < 9) {
        temp.setDigit(i + j, mult % 10);
      }
    }

    result = result.add(temp);
  }
  if ((this->getSignMult() * rhnumber.getSignMult()) == -1) {
    result.setSign('-');
  }

  return result;
}
BigInt BigInt::divide(BigInt rhnumber) {
  // BigInt result;
  int result[10];
  int i = 0;
  BigInt n1 = *this;
  BigInt n2 = rhnumber;
  auto recursion = [&n1, &n2, &result](auto &&self, int i) {
    int counter = 0;

    BigInt temp(n1.getNDigitsFromHighest(n2.getNumberOfDigits()));
    if (temp.isLessThen(n2)) {
      temp = BigInt(n1.getNDigitsFromHighest(n2.getNumberOfDigits() + 1));
    }
    while (n2.isLessThen(temp)) {
      counter++;
      n2.print();
      temp.print();
      temp = temp.substruct(n2);
      // temp.print();
    }
    // std::cout << i << std::endl;
    result[i] = counter;
    // std::cout << counter << std::endl;
    i++;
    n1 = BigInt(temp.toString() +
                n1.getNDigitsFromLowest(n1.getNumberOfDigits() -
                                        n2.getNumberOfDigits()));
    if (i > 9)
      return 0;

    // self(self, i);
    return 0;
  };
  recursion(recursion, i);

  BigInt r;
  return r;
}

/* Comparison operators */

bool BigInt::isLessThen(BigInt rhnumber) {

  for (int i = getLength() - 1; i >= 0; i--) {
    int x = this->getSignMult() * this->getDigit(i);
    int y = rhnumber.getSignMult() * rhnumber.getDigit(i);
    if (x < y) {
      return true;
    } else if (x > y) {
      return false;
    }
  }

  return false;
}
bool BigInt::isMoreThen(BigInt rhnumber) {
  for (int i = getLength() - 1; i >= 0; i--) {
    int x = this->getSignMult() * this->getDigit(i);
    int y = rhnumber.getSignMult() * rhnumber.getDigit(i);
    if (x > y) {
      return true;
    }
    if (x < y) {
      return false;
    }
  }

  return false;
}
bool BigInt::isEqualTo(BigInt rhnumber) {
  for (int i = getLength() - 1; i >= 0; i--) {
    int x = this->getSignMult() * this->getDigit(i);
    int y = rhnumber.getSignMult() * rhnumber.getDigit(i);
    if (x != y) {
      return false;
    }
  }
  return true;
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

/* Public utils methods*/

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
  if (str == "") {
    return "0";
  }
  // Printing a minus sign
  if (_sign == '-') {
    str = '-' + str;
  }
  // If all values are 0 or \0 and firs digit is 0 return "0"
  if (str.length() == 0 && this->getCharAt(0) == '0') {
    return "0";
  }
  return str;
}

/* Private Utils */
int BigInt::getNumberOfDigits() { return this->toString().length(); }
char BigInt::getCharAt(int index) { return _digits[index]; }

int BigInt::getDigit(int index) {

  if (this->_digits[index] == '\0') {
    return 0;
  }

  return this->_digits[index] - '0';
}

// Getting digit from the bigest grade to the lowest.
// Example: num=452, num.getHighestDigit(0) => 4
int BigInt::getHighestDigit(int index) {
  bool isStarted = false;
  for (int i = getLength() - 1; i >= 0; i--) {
    if (!(this->_digits[i] == '0' || this->_digits[i] == '\0')) {
      isStarted = true;
    }
    if (isStarted) {
      return this->_digits[i + index] - '0';
    }
  }

  return 0;
}

bool BigInt::isDigit(char c) {
  if (c < 58 && c > 47) {
    return true;
  }
  return false;
}

std::string BigInt::getNDigitsFromHighest(int n) {
  if (n > getLength()) {
    n = 10;
  }
  std::string digits = "";
  bool isPading = true;
  int i = 0;

  while (isPading) {
    if (getCharAt(i) != '0' && getCharAt(i) != '\0') {
      isPading = false;
      break;
    }

    i++;
  }

  for (int j = 0; j < n; j++) {

    if (isDigit(getCharAt(i - j + 1))) {

      digits = digits + getCharAt(i - j + 1);
    }
  }
  // std::cout << digits << std::endl;
  return digits;
}

std::string BigInt::getNDigitsFromLowest(int n) {
  std::string digits = "";
  for (int i = 0; i < n; i++) {
    digits = getCharAt(i) + digits;
  }
  return digits;
}

int BigInt::getLength() { return LENGTH; }
void BigInt::setDigit(int index, char value) { this->_digits[index] = value; }

void BigInt::setDigit(int index, int value) {

  if (value > 9 || value < 0) {
    throw "[setDigit()]: Value must be >= 0 and <= 9";
  }

  this->_digits[index] = value + '0';
}

void BigInt::setSign(char sign) {
  if (sign != '-' && sign != '+') {
    throw "Wrong sign character in setSign() method";
  }

  _sign = sign;
}
int BigInt::parseInt(char c) { return c - '0'; }

int BigInt::getSignMult() { return (_sign == '+' ? 1 : -1); }

/*

Bottom space








*/