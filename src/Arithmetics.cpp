#include "../include/BigInt.hpp"

/*** Arithmetical operations ***/

/**
 * Addition (BigInt + BigInt)
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt BigInt::operator+(const BigInt rhnumber) const { return add(rhnumber); };

/**
 * Subtraction (BigInt - BigInt)
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt BigInt::operator-(const BigInt rhnumber) const {
  return subtract(rhnumber);
}

/**
 * Multiplication (BigInt * BigInt)
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt BigInt::operator*(const BigInt rhnumber) const {
  return multiply(rhnumber);
}

/**
 * Division (BigInt / BigInt)
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt BigInt::operator/(const BigInt rhnumber) const {
  return divide(rhnumber);
}

/**
 * Modulus division (BigInt % BigInt)
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt BigInt::operator%(const BigInt rhnumber) const {
  return modulus(rhnumber);
}

/**
 * Post Increment (BigInt++)
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */

BigInt &BigInt::operator++() {
  *this = (*this) + 1;
  return *this;
}
/**
 * Post Decrement (BigInt--)
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt &BigInt::operator--() {
  *this = (*this) - 1;
  return *this;
}
/**
 * Pre Increment (++BigInt)
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt BigInt::operator++(int) {
  BigInt res = *this;
  *this = (*this) + 1;
  return res;
}
/**
 * Pre Decrement (--BigInt)
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt BigInt::operator--(int) {
  BigInt res = *this;
  *this = (*this) - 1;
  return res;
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
    return n1.subtract(local);
  }

  if (n1sm < 0 && n2sm > 0) {
    BigInt local = n1;
    local.setSign('+');
    return n2.subtract(local);
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

BigInt BigInt::subtract(const BigInt rhnumber) const {

  BigInt n1;
  BigInt n2;
  // Switch numbers is left number less then right
  // to be able to use subtraction algorithm
  BigInt abs1 = (*this);
  abs1.setSign('+');
  BigInt abs2 = rhnumber;
  abs2.setSign('+');
  BigInt result;
  if (abs1 < abs2) {
    n1 = rhnumber;
    n2 = *this;
  } else {
    n1 = *this;
    n2 = rhnumber;
  }

  if ((*this) < rhnumber) {
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
  result.removeLeadingZeros();
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

BigInt BigInt::modulus(const BigInt rhnumber) const {

  BigInt result = *this / rhnumber;
  result = rhnumber * result;
  result = (*this) - result;
  return result;
}