#pragma once
#include <fstream>
#include <iostream>

#include "../../libs/nlohmann_json//single_include/nlohmann/json.hpp"

// for convenience
using json = nlohmann::json;

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
    std::ifstream stream("../src/test/testData.json");
    json j;
    stream >> j;
    if (j["stringValidation"][1].is_null()) {
      std::cout << "/* message */" << std::endl;
    }
    // std::cout << str << std::endl;

    int i = 0;
    json stringValidation = j["stringValidation"];

    while (!stringValidation[i].is_null()) {

      assertion(stringValidation[i]["expected"],
                bigInt.isValidString(stringValidation[i]["value"]),
                stringValidation[i]["value"]);

      i++;
    }
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
        "2",  "0", "6",   "0",  "2",           "2",
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