#pragma once
#include <iostream>
#include <string>
#include <vector>

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
    assertion(false, bigInt.isValidString("--123"), "--123");
  }

  static void additionTest() {

    // typedef void (BigInt::*PrintFuncPtr)();
    // void *func = &BigInt::print;
    // BigInt num;
    // (num.*func)();
    auto func = &BigInt::add;

    std::vector<std::string> firstValues{
        "1",   "0",  "3",  "1",  "2",          "0",
        "-10", "-3", "99", "88", "9999999999", "5",
    };
    std::vector<std::string> secondValues{
        "1", "0", "3", "-1", "0", "2", "1", "4", "1", "-89", "1", "-555",
    };
    std::vector<std::string> expectedValues{
        "2",  "0", "6",   "0",  "2",           "0",
        "-9", "1", "100", "-1", "10000000000", "-550",
    };

    for (int i = 0; i < firstValues.size(); i++) {
      BigInt bi1(firstValues[i]);
      BigInt bi2(secondValues[i]);
      std::vector<std::string> params{firstValues[i], secondValues[i]};
      assertionEquals(
          bi1.add(bi2).toString(), expectedValues[i],
          std::vector<std::string>{firstValues[i], secondValues[i]});
    }
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

  static void assertionEquals(std::string exact, std::string expected,
                              std::vector<std::string> values) {
    std::string valsstr = "";
    int i = 1;
    for (auto val : values) {
      valsstr = valsstr + "value" + std::to_string(i) + ": " + val + " ";
      i++;
    }

    if (exact.compare(expected) == 0) {
      std::cout << BOLDGREEN << "[ASSERTION] PASSED!" << RESET << std::endl;
    } else {
      std::cout << BOLDRED << "[FAILED] Expected: " << expected
                << " Get: " << exact << std::endl
                << " - [values]: " << valsstr << RESET << std::endl
                << std::endl;
    }
  }
};