#include <cstdio>
#include <fstream>
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

void generateNumbersSet() {
  // Seed pseudo-random number generator
  // Should be seeded only once before the program execution

  srand(time(NULL));
  std::fstream file;
  file.open("data.txt");

  std::string numbers = "";
  bool reverseOrder = true;
  int numbersLengthGrowth = 10;

  int numberOfGenerations = 20000;

  for (int i = 0; i < numberOfGenerations; i++) {
    numbers += std::to_string(rand());
  }

  int j = 1;
  std::vector<std::string> nums1, tempnums, nums2;

  for (int i = 0; i < numbers.length(); i = i + j) {
    nums1.push_back(numbers.substr(i, j));
    j = j + numbersLengthGrowth;
  }

  numbers = "";
  for (int i = 0; i < numberOfGenerations; i++) {
    numbers += std::to_string(rand());
  }

  j = 1;
  if (reverseOrder) {
    /*** Reversed generation ***/
    for (int i = 0; i < numbers.length(); i = i + j) {
      tempnums.push_back(numbers.substr(i, j));
      j++;
    }

    for (int i = tempnums.size() - 1; i >= 0; i--) {
      nums2.push_back(tempnums[i]);
    }
  } else {
    /*** Normal generation ***/
    for (int i = 0; i < numbers.length(); i = i + j) {
      nums2.push_back(numbers.substr(i, j));
      j = j + numbersLengthGrowth;
    }
  }

  std::string generatedString = "";
  for (int i = 0; i < nums1.size(); i++) {
    generatedString +=
        "NumbersSet(\"" + nums1[i] + "\",\"" + nums2[i] + "\"),\n";
  }
  file << generatedString;

  // file << numbers;
  file.close();
}

int main(int argc, const char **argv) {
  // generateNumbersSet();

  BigInt b1 = "-150";
  BigInt b2 = "-13";

  std::cout << b1 / b2 << std::endl;

  PerformanceTest ptest;

  try {
    // ArithmeticsTest().runAll();
    // ArithmeticsTest().devideBruteTest();
    // ComparisonTest().runAll();
    // AssignmentTest().runAll();
    // AssignmentTest().addAssignTest();
    // PublicUtilsTest().toStringTest();
    // ConstructorsTest().intConstructorTest();
    // ConstructorsTest().stringConstructorTest();
    // ptest.addition();
    // ptest.substruction();
    // ptest.karatsubaMultiplication();
    // ptest.longMultiplication();
    // ptest.division();
    ptest.modulus();
    // ArithmeticsTest().multiplyTest();

  } catch (const char *e) {
    std::cout << e << std::endl;
  }

  return 0;
}
