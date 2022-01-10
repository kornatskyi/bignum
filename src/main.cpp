#include <bitset>
#include <iostream>
#include <math.h>

#include "BigInt.h"
#include "test/TestBigInt.h"

class MyClass {
public:
  void print() { std::cout << "Hello" << std::endl; }
};

void newFunc(void (MyClass::*func)()) {

  MyClass o;
  (o.*func)();
}

int main(int, char **) {

  // TestBigInt::stringValidationTest();
  TestBigInt::additionTest();

  // try {

  //   BigInt bigInt1("1678");
  //   BigInt bigInt2("-1123");
  //   bigInt1.print();
  //   bigInt2.print();
  //   BigInt sum = bigInt1.add(bigInt2);
  //   sum.print();

  // } catch (char const *e) {
  //   std::cout << e << std::endl;
  // }

  return 0;
}
