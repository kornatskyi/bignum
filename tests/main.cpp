#include "../include/BigInt.hpp"
#include "TestBigInt.hpp"
#include <cstdio>
#include <iostream>
#include <iterator>
#include <string>

int main(int argc, const char **argv) {

  try {
    TestBigInt testing;

    testing.additionTest();
    testing.subtractTest();
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
    // BigInt b;
    // std::cout << b.length() << std::endl;
    // b *= 10;
    // std::cout << b << std::endl;

  } catch (const char *e) {
    std::cout << e << std::endl;
  }

  // TODO
  /*
      CASE{

        BigInt n;
        n %= 10;
        cout << n;

      }

      CASE{

        BigInt n;
        n *= 10;
        cout << n;

      }

      CASE {
        incrementation
        decrementattion
        do test cases
      }
  */

  return 0;
}