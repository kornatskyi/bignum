#include <bitset>
#include <iostream>
#include <math.h>

#include "BigInt.h"
#include "test/TestBigInt.h"

int main(int, char **) {

  // TestBigInt::stringValidationTest();

  try {
    BigInt bi(543);
    bi.print();

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
