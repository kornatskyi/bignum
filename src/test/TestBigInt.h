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

    BigInt bigInt;
    std::ifstream stream("../src/test/testData.json");
    json j;
    stream >> j;

    int i = 0;
    json additionTestCases = j["additionTestCases"];

    while (!additionTestCases[i].is_null()) {
      BigInt bi1((std::string)additionTestCases[i]["values"][0]);
      BigInt bi2((std::string)additionTestCases[i]["values"][1]);
      assertionEquals(
          bi1.add(bi2).toString(), additionTestCases[i]["expected"],
          std::vector<std::string>{additionTestCases[i]["values"][0],
                                   additionTestCases[i]["values"][1]});
      i++;
    }
  }

  static void isLessThenTest() {
    BigInt bigInt;
    std::ifstream stream("../src/test/testData.json");
    json j;
    stream >> j;

    int i = 0;
    json isLessThenTestCases = j["isLessThenTestCases"];

    while (!isLessThenTestCases[i].is_null()) {
      BigInt bi1((std::string)isLessThenTestCases[i]["values"][0]);
      BigInt bi2((std::string)isLessThenTestCases[i]["values"][1]);
      assertionEquals(
          bi1.isLessThen(bi2), isLessThenTestCases[i]["expected"],
          std::vector<std::string>{isLessThenTestCases[i]["values"][0],
                                   isLessThenTestCases[i]["values"][1]});
      i++;
    }
  }

  static void isEqualToTest() {
    BigInt bigInt;
    std::ifstream stream("../src/test/testData.json");
    json j;
    stream >> j;

    int i = 0;
    json isEqualsToTestCases = j["isEqualsToTestCases"];

    while (!isEqualsToTestCases[i].is_null()) {
      BigInt bi1((std::string)isEqualsToTestCases[i]["values"][0]);
      BigInt bi2((std::string)isEqualsToTestCases[i]["values"][1]);
      assertionEquals(
          bi1.isEqualTo(bi2), isEqualsToTestCases[i]["expected"],
          std::vector<std::string>{isEqualsToTestCases[i]["values"][0],
                                   isEqualsToTestCases[i]["values"][1]});
      i++;
    }
  }

  static void multiplyTest() {

    BigInt bigInt;
    std::ifstream stream("../src/test/testData.json");
    json j;
    stream >> j;

    int i = 0;
    json multiplyTestCases = j["multiplyTestCases"];

    while (!multiplyTestCases[i].is_null()) {
      BigInt bi1((std::string)multiplyTestCases[i]["values"][0]);
      BigInt bi2((std::string)multiplyTestCases[i]["values"][1]);
      assertionEquals(
          bi1.multiply(bi2).toString(), multiplyTestCases[i]["expected"],
          std::vector<std::string>{multiplyTestCases[i]["values"][0],
                                   multiplyTestCases[i]["values"][1]});
      i++;
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

  static void assertionEquals(bool exact, bool expected,
                              std::vector<std::string> values) {
    std::string valsstr = "";
    int i = 1;
    for (auto val : values) {
      valsstr = valsstr + "value" + std::to_string(i) + ": " + val + " ";
      i++;
    }

    if (exact == expected) {
      std::cout << BOLDGREEN << "[ASSERTION] PASSED!" << RESET << std::endl;
    } else {
      std::cout << BOLDRED << "[FAILED] Expected: " << expected
                << " Get: " << exact << std::endl
                << " - [values]: " << valsstr << RESET << std::endl
                << std::endl;
    }
  }
};