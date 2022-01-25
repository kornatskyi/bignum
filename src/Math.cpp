#include "BigInt.hpp"

BigInt power(BigInt base, int power) {

  if (power == 0) {
    return 1;
  }
  if (base == 1) {
    return 1;
  }
  if (power < 0) {
    return 0;
  }
  BigInt result = base;
  for (int i = 1; i < power; i++) {
    result = result * base;
  }
  return result;
}