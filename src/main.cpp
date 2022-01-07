#include <iostream>
#include <math.h>

#include "BigInt.h"
#include "test/TestBigInt.h"

int main(int, char **) {
  int z = 5;
  int x = 0b01111111111111111111111111111111;
  int y = 0b10000000000000000000000000000001;

  while (z > 0) {
    z--;
  }

  int nums[2];
  nums[0] = 2147483647;
  nums[1] = 2;

  std::cout << (int)pow(2, 31) - 1 << std::endl;

  try {
    BigInt bigInt1("678");
    BigInt bigInt2("123");
    bigInt1.print();
    bigInt2.print();
    BigInt sum = bigInt1.add(bigInt2);

  } catch (char const *e) {
    std::cout << e << std::endl;
  }

  return 0;
}
