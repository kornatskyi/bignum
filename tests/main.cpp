#include "../include/BigInt.hpp"
#include "TestBigInt.hpp"
#include <cstdio>
#include <iterator>
#include <string>

int main(int argc, const char **argv) {

  try {
    TestBigInt testing;

    testing.additionTest();
    testing.substructTest();
    testing.multiplyTest();
    testing.devideTest();
    testing.modulusTest();

    testing.intAssignmentTest();
    testing.stringAssignmentTest();

    testing.isEqualToTest();
    testing.notEqualToTest();
    testing.isLessOrEqualTo();
    testing.isMoreOrEqualTo();
    testing.isMoreThenTest();
    testing.isLessThenTest();

  } catch (const char *e) {
    std::cout << e << std::endl;
  }

  return 0;
}