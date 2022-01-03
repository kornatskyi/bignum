#pragma once
#include <iostream>

#include "../BigInt.h"

#define RESET "\033[0m"
#define RED "\033[31m"              /* Red */
#define GREEN "\033[32m"            /* Green */
#define BOLDRED "\033[1m\033[31m"   /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m" /* Bold Green */

class TestBigInt {
public:
  static void stringValidationTest() {
    BigInt bigInt;
    assertion(true, bigInt.isValidString("0"), "0");
    assertion(true, bigInt.isValidString("1"), "1");
    assertion(true, bigInt.isValidString("11111"), "11111");
    assertion(true, bigInt.isValidString("321"), "321");
    assertion(true, bigInt.isValidString("99939129"), "99939129");
    assertion(true, bigInt.isValidString("-1"), "-1");
    assertion(true, bigInt.isValidString("+1010"), "+1010");
    assertion(true, bigInt.isValidString("+0"), "+0");
    assertion(true, bigInt.isValidString("-0"), "-0");
    assertion(true, bigInt.isValidString("9999999999"), "9999999999");
    assertion(true, bigInt.isValidString("-9999999999"), "-9999999999");
    assertion(false, bigInt.isValidString("-"), "-");
    assertion(false, bigInt.isValidString("--"), "--");
    assertion(false, bigInt.isValidString("--1"), "--1");
    assertion(false, bigInt.isValidString("--10"), "--10");
    assertion(false, bigInt.isValidString("--0"), "--0");
    assertion(false, bigInt.isValidString("++"), "++");
    assertion(false, bigInt.isValidString("+"), "+");
    assertion(false, bigInt.isValidString("+++1"), "+++1");
    assertion(false, bigInt.isValidString("++3"), "++3");
    assertion(false,
              bigInt.isValidString(
                  "++++++++++++++++++++++++++++++++++++++++++++++++"),
              "++++++++++++++++++++++++++++++++++++++++++++++++");

    assertion(
        false,
        bigInt.isValidString("------------------------------------------"),
        "------------------------------------------");
    assertion(false, bigInt.isValidString("slfdh"), "slfdh");
    assertion(false, bigInt.isValidString("a"), "a");
    assertion(false, bigInt.isValidString(""), "");
    assertion(false, bigInt.isValidString("1r"), "1r");
    assertion(false, bigInt.isValidString("3f"), "3f");
    assertion(false, bigInt.isValidString("f3"), "f3");
    assertion(false, bigInt.isValidString("-1f"), "-1f");
    assertion(false, bigInt.isValidString("-f"), "-f");
    assertion(false, bigInt.isValidString("-f3"), "-f3");
    assertion(false, bigInt.isValidString("-a"), "-a");
    assertion(false, bigInt.isValidString("-o"), "-o");
    assertion(false, bigInt.isValidString("-O"), "-O");
    assertion(false, bigInt.isValidString("-l"), "-l");
    assertion(false, bigInt.isValidString("-23r"), "-23r");
    assertion(false, bigInt.isValidString("9999999999a"), "9999999999a");
    assertion(false, bigInt.isValidString("-9999999999a"), "-9999999999a");
    assertion(false, bigInt.isValidString("+9999999999a"), "+9999999999a");
    assertion(false, bigInt.isValidString("a9999999999a"), "a9999999999a");
  }

  static void assertion(bool val1, bool val2) {
    if (val1 == val2) {
      std::cout << BOLDGREEN << "[ASSERTION] PASSED!" << RESET << std::endl;
    } else {
      std::cout << BOLDRED << "ASSERTION FAILED!" << RESET << std::endl;
    }
  }

  static void assertion(bool expected, bool excact, std::string val) {
    if (expected == excact) {
      std::cout << BOLDGREEN << "[ASSERTION] PASSED!" << RESET << std::endl;
    } else {
      std::cout << BOLDRED << "Expected: " << (expected ? "true" : "false")
                << " Get: " << (excact ? "true" : "false")
                << " [value]: " << val << RESET << std::endl;
    }
  }
};