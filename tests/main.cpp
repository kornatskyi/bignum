#include "../include/BigInt.hpp"
#include "TestBigInt.hpp"
#include <cstdio>
#include <iterator>
#include <string>

int main(int argc, const char **argv) {

  try {
    TestBigInt testing;

    // testing.additionTest();
    // testing.substructTest();
    // testing.multiplyTest();
    // testing.devideTest();

    // testing.intAssignmentTest();
    // testing.stringAssignmentTest();

    // testing.isEqualToTest();
    // testing.notEqualToTest();
    // testing.isLessOrEqualTo();
    // testing.isMoreOrEqualTo();
    // testing.isMoreThenTest();
    // testing.isLessThenTest();

    BigInt n1 = "123";

    BigInt n2 = "3";

    // std::cout << 149 * 149 << std::endl;
    // 22201
    BigInt res;
    res.print();

  } catch (const char *e) {
    std::cout << e << std::endl;
  }

  return 0;
}