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

    BigInt n1 = "99";

    BigInt n2 = "11";

    // std::cout << 149 * 149 << std::endl;
    // 22201
    BigInt res = n1 / n2;
    res.print();

  } catch (const char *e) {
    std::cout << e << std::endl;
  }

  return 0;
}