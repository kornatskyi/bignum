#pragma once

#include <fstream>
#include <iostream>

#include "../libs/json/single_include/nlohmann/json.hpp"

// for convenience
using json = nlohmann::json;

#include <string>
#include <vector>

#include "BigInt.hpp"
#include "Testing.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"              /* Red */
#define GREEN "\033[32m"            /* Green */
#define BOLDRED "\033[1m\033[31m"   /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m" /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"
#define YELLOW "\033[33m"

class TestBigInt : public Testing {
public:
  /*

    Arithmetic operations testing

  */

  void additionTest();
  void substructTest();
  void multiplyTest();
  void devideTest();
  void modulusTest();

  /*

    Comperison operations testing

  */
  void isLessThenTest();
  void isEqualToTest();
  void isLessThenBrootTest();
  void isMoreThenBrootTest();
  void isEqualToBrootTest();

  /*
    Utilities methods testing
  */

  void stringValidationTest();
};