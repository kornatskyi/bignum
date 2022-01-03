#include <iostream>

#include "BigInt.h"
#include "test/TestBigInt.h"

int main(int, char **) {
  BigInt bigInt("012312");
  bigInt.print();

  return 0;
}
