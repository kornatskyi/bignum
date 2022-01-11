#include <bitset>
#include <iostream>
#include <math.h>

#include <fstream>

#include "BigInt.h"
#include "test/TestBigInt.h"

int main(int, char **) {
  // std::ifstream i("../src/text.txt");
  // std::cout << i.rdbuf() << std::endl;

  try {

    // BigInt bigInt1("0");
    // BigInt bigInt2("-1");
    // bigInt1.print();
    // bigInt2.print();
    // BigInt sum = bigInt1.multiply(bigInt2);
    // sum.print();

    // TestBigInt::stringValidationTest();
    // TestBigInt::additionTest();
    // TestBigInt::isLessThenTest();
    // TestBigInt::isEqualToTest();
    // TestBigInt::multiplyTest();

  } catch (char const *e) {
    std::cout << e << std::endl;
  }

  return 0;
}
