#include <bitset>
#include <iostream>
#include <math.h>

#include <fstream>
#include <string>

#include "BigInt.h"
#include "test/TestBigInt.h"

int main(int, char **) {
  // std::ifstream i("../src/text.txt");
  // std::cout << i.rdbuf() << std::endl;

  try {

    // BigInt bigInt1("16");
    // BigInt bigInt2("2");
    // bigInt1.print();
    // bigInt2.print();
    // BigInt sum = bigInt1.divide(bigInt2);
    // sum.print();

    // TestBigInt::stringValidationTest();
    // TestBigInt::additionTest();
    // TestBigInt::substructTest();
    // TestBigInt::isLessThenTest();
    // TestBigInt::isEqualToTest();
    // TestBigInt::multiplyTest();
    // TestBigInt::devideTest();

    TestBigInt::isMoreThenBrootTest();
    TestBigInt::isLessThenBrootTest();

    // BigInt bigInt1("11");
    // BigInt bigInt2("-2");
    // BigInt sum = bigInt1.add(bigInt2);
    // sum.print();

  } catch (char const *e) {
    std::cout << e << std::endl;
  }
  int n1 = 98;
  int n2 = 89;

  BigInt bn1(n1);
  BigInt bn2(n2);

  std::vector<std::string> vals = {std::to_string(n1), std::to_string(n2)};

  TestBigInt::assertionEquals(n1 < n2, bn1.isLessThen(bn2), vals);
  return 0;
}
