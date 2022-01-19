#include "../include/BigInt.hpp"
#include "ArithmeticsTest.hpp"
#include "AssignmentTest.hpp"
#include "ComparisonTest.hpp"
#include <cstdio>
#include <iostream>
#include <iterator>
#include <string>

int main(int argc, const char **argv) {

  try {
    // ArithmeticsTest().runAll();
    // ComparisonTest().runAll();
    // AssignmentTest().runAll();
    // AssignmentTest().addAssignTest();

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