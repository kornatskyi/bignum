#include <algorithm>
#include <bitset>
#include <iostream>
#include <math.h>

#include <fstream>
#include <string>

#include "../tests/TestBigInt.h"
#include "BigInt.h"

#include <stdio.h>

int main(int, char **) {

  try {

    // BigInt bigInt1("16");
    // BigInt bigInt2("2");
    // bigInt1.print();
    // bigInt2.print();
    // BigInt sum = bigInt1.divide(bigInt2);
    // sum.print();
    TestBigInt tests;
    // auto f = ;

    // tests.stringValidationTest();
    // tests.additionTest();
    // tests.substructTest();
    // tests.isLessThenTest();
    // tests.isEqualToTest();
    // tests.multiplyTest();
    // tests.devideTest();

    // tests.isMoreThenBrootTest();
    // tests.isLessThenBrootTest();
    // tests.isEqualToBrootTest();

    tests.printLogs();

    // BigInt bigInt1("11");
    // BigInt bigInt2("-2");
    // BigInt sum = bigInt1.add(bigInt2);
    // sum.print();

    // int n1 = 435;
    // int n2 = 53;

    // BigInt bn1(n1);
    // BigInt bn2(n2);
    // BigInt res = bn1.divide(bn2);
    // res.print();
    BigInt bn1 = "12334";
    BigInt bn2 = "-123";
    BigInt res = bn1.add(bn2);
    res.print();

  } catch (char const *e) {
    std::cout << e << std::endl;
  }

  return 0;
}
