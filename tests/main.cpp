#include <cstdio>
#include <iostream>
#include <iterator>
#include <string>

#include "ArithmeticsTest.hpp"
#include "AssignmentTest.hpp"
#include "BigInt.hpp"
#include "ComparisonTest.hpp"
#include "ConstructorsTest.hpp"
#include "PublicUtilsTest.hpp"

int main(int argc, const char **argv) {

  try {
    // ArithmeticsTest().runAll();
    // ComparisonTest().runAll();
    // AssignmentTest().runAll();
    // AssignmentTest().addAssignTest();
    PublicUtilsTest().toStringTest();
    ConstructorsTest().intConstructorTest();
    ConstructorsTest().stringConstructorTest();

  } catch (const char *e) {
    // std::cout << e << std::endl;
  }

  return 0;
}