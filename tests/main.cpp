#include "../include/BigInt.hpp"
#include "TestBigInt.hpp"
#include <cstdio>
#include <iostream>
#include <iterator>
#include <string>

int main(int argc, const char **argv) {

  try {
    TestBigInt testing;

    // testing.additionTest();
    // testing.substructTest();
    // testing.multiplyTest();
    // testing.devideTest();
    // testing.modulusTest();

    // testing.intAssignmentTest();
    // testing.stringAssignmentTest();

    // testing.isEqualToTest();
    // testing.notEqualToTest();
    // testing.isLessOrEqualTo();
    // testing.isMoreOrEqualTo();
    // testing.isMoreThenTest();
    // testing.isLessThenTest();

    BigInt n1;

    std::cin >> n1;

    std::cout << n1 << std::endl;

  } catch (const char *e) {
    std::cout << e << std::endl;
  }

  return 0;
}