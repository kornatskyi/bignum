#include <algorithm>
#include <bitset>
#include <iostream>
#include <math.h>

#include <fstream>
#include <string>

#include "BigInt.h"
#include "test/TestBigInt.h"

void someFunc() { std::cout << "Hello func" << std::endl; }

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
    TestBigInt tests;
    // auto f = ;

    tests.stringValidationTest();
    tests.additionTest();
    tests.substructTest();
    tests.isLessThenTest();
    tests.isEqualToTest();
    tests.multiplyTest();
    // tests.devideTest();

    // tests.isMoreThenBrootTest();
    // tests.isLessThenBrootTest();
    // tests.isEqualToBrootTest();

    tests.printLogs();

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

  // TestBigInt::assertionEquals(n1 < n2, bn1.isLessThen(bn2), vals);

  std::for_each(vals.begin(), vals.end(),
                [](std::string s) { std::cout << s << std::endl; });
  return 0;
}
