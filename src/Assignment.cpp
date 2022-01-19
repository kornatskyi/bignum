#include "../include/BigInt.hpp"

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
BigInt &BigInt::operator+=(const BigInt &rhnumber) {
  *this = (*this) + rhnumber;
  return *this;
}

/**
 * BigInt -= BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt &BigInt::operator-=(const BigInt &rhnumber) {
  *this = (*this) - rhnumber;
  return *this;
}

/**
 * BigInt *= BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt &BigInt::operator*=(const BigInt &rhnumber) {
  *this = (*this) * rhnumber;
  return *this;
}

/**
 * BigInt /= BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt &BigInt::operator/=(const BigInt &rhnumber) {
  *this = (*this) / rhnumber;
  return *this;
}

/**
 * BigInt %= BigInt
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */
BigInt &BigInt::operator%=(const BigInt &rhnumber) {
  *this = (*this) % rhnumber;
  return *this;
}