#include <cstdio>
#include <iostream>
#include <iterator>
#include <string>

#include "ArithmeticsTest.hpp"
#include "AssignmentTest.hpp"
#include "BigInt.hpp"
#include "ComparisonTest.hpp"
#include "ConstructorsTest.hpp"
#include "DataSet.hpp"
#include "PerformanceTest.hpp"
#include "PublicUtilsTest.hpp"

int main(int argc, const char **argv) {
  PerformanceTest ptest;
  DataSet dataset;

  // Seed pseudo-random number generator
  // Should be seeded only once before the program execution
  srand(time(NULL));

  ptest.addition();
  ptest.substruction();
  ptest.multiplication();
  ptest.division();
  ptest.modulus();

  try {
    // ArithmeticsTest().runAll();
    // ComparisonTest().runAll();
    // AssignmentTest().runAll();
    // AssignmentTest().addAssignTest();
    // PublicUtilsTest().toStringTest();
    // ConstructorsTest().intConstructorTest();
    // ConstructorsTest().stringConstructorTest();

  } catch (const char *e) {
    // std::cout << e << std::endl;
  }

  return 0;
}