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

  try {

    //   BigInt bigInt1("1678");
    //   BigInt bigInt2("-1123");
    //   bigInt1.print();
    //   bigInt2.print();
    //   BigInt sum = bigInt1.add(bigInt2);
    //   sum.print();
    TestBigInt::additionTest();

  } catch (char const *e) {
    std::cout << e << std::endl;
  }

  return 0;
}
