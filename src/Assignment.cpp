#include "BigInt.hpp"

/*** Assignment operators  ***/

/**
 * BigInt = int
 * ¯¯¯¯¯¯¯¯¯¯¯¯
 */
const BigInt &BigInt::operator=(const int initial) {
  *this = BigInt(initial);
  return *this;
}
/**
 * BigInt = float
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
const BigInt &BigInt::operator=(const float initial) {
  *this = BigInt(initial);
  return *this;
}
/**
 * BigInt = double
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
const BigInt &BigInt::operator=(const double initial) {
  *this = BigInt(initial);
  return *this;
}
/**
 * BigInt = long
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
const BigInt &BigInt::operator=(const long initial) {
  *this = BigInt(initial);
  return *this;
}
/**
 * BigInt = long long
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
const BigInt &BigInt::operator=(const long long initial) {
  *this = BigInt(initial);
  return *this;
}

/**
 * BigInt = std::string
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
const BigInt &BigInt::operator=(const std::string initial) {

  *this = BigInt(initial);
  return *this;
}

/**
 * BigInt = char*
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
const BigInt &BigInt::operator=(const char *initial) {
  *this = BigInt(initial);
  return *this;
}

/**
 * BigInt = vector
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 * Will reverse vector.
 * Example: vector == [3, 7, 2] -> _digits == [2, 7 ,3]
 */
const BigInt &BigInt::operator=(const std::vector<int> initialReversed) {
  *this = BigInt(initialReversed);
  return *this;
}

/*** Assignment arithmetics operators ***/

/**
 * BigInt += BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt &BigInt::operator+=(const BigInt &rhn) {
  *this = (*this) + rhn;
  return *this;
}

/**
 * BigInt -= BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt &BigInt::operator-=(const BigInt &rhn) {
  *this = (*this) - rhn;
  return *this;
}

/**
 * BigInt *= BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt &BigInt::operator*=(const BigInt &rhn) {
  *this = (*this) * rhn;
  return *this;
}

/**
 * BigInt /= BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt &BigInt::operator/=(const BigInt &rhn) {
  *this = (*this) / rhn;
  return *this;
}

/**
 * BigInt %= BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt &BigInt::operator%=(const BigInt &rhn) {
  *this = (*this) % rhn;
  return *this;
}