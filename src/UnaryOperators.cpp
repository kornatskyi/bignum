/* Unary operators */

#include "BigInt.hpp"

/**
 * Unary minus
 * ¯¯¯¯¯¯¯¯¯¯¯
 * Changes sign to the opposite
 */
BigInt BigInt::operator-() {
  _sign = _sign ? false : true;
  return *this;
}
/**
 * Unary plus
 * ¯¯¯¯¯¯¯¯¯¯
 * Doesn't change anything
 */
BigInt BigInt::operator+() { return *this; }