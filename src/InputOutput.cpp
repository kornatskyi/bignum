#include "../include/BigInt.hpp"

/* Input/Output operators */

std::istream &operator>>(std::istream &in, BigInt &bigInt) {
  std::string input;
  in >> input;
  bigInt = BigInt(input); // remove sign from value and set sign, if exists
  return in;
}

std::ostream &operator<<(std::ostream &out, const BigInt &bigInt) {
  out << bigInt.toString();
  return out;
}
