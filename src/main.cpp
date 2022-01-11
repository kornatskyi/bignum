#include <bitset>
#include <iostream>
#include <math.h>

#include <fstream>

#include "BigInt.h"
#include "test/TestBigInt.h"

int main(int, char **) {
  // std::ifstream i("../src/text.txt");
  // std::cout << i.rdbuf() << std::endl;

  // TestBigInt::stringValidationTest();
  // TestBigInt::additionTest();

  try {

    BigInt bigInt1("13");
    BigInt bigInt2("93");
    bigInt1.print();
    bigInt2.print();
    BigInt sum = bigInt1.substruct(bigInt2);
    sum.print();

  } catch (char const *e) {
    std::cout << e << std::endl;
  }

  return 0;
}
