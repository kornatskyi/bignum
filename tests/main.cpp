#include <cstdio>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "ArithmeticsTest.hpp"
#include "AssignmentTest.hpp"
#include "BigInt.hpp"
#include "ComparisonTest.hpp"
#include "ConstructorsTest.hpp"
#include "DataGenerator.hpp"
#include "DataSet.hpp"
#include "PerformanceTest.hpp"
#include "PublicUtilsTest.hpp"

int main(int argc, const char **argv) {

  PerformanceTest ptest;

  // Generates NubmerSets and writes input to the file
  // See more description in DataGeneration.hpp
  // DataGenerator::generateNumberSets();
  try {
    ArithmeticsTest().runAll();
    // ComparisonTest().runAll();
    // AssignmentTest().runAll();
    // ConstructorsTest().intConstructorTest();
    // ConstructorsTest().stringConstructorTest();
    // ptest.addition();
    // ptest.substruction();
    // ptest.karatsubaMultiplication();
    // ptest.longMultiplication();
    // ptest.division();
    // ptest.modulus();

  } catch (const char *e) {
    std::cout << e << std::endl;
  }

  return 0;
}
