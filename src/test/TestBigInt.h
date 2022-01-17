#pragma once

#include <fstream>
#include <iostream>

#include "../../libs/nlohmann_json//single_include/nlohmann/json.hpp"

// for convenience
using json = nlohmann::json;

#include <string>
#include <vector>

#include "../BigInt.h"

#include "./Testing.h"

#define RESET "\033[0m"
#define RED "\033[31m"              /* Red */
#define GREEN "\033[32m"            /* Green */
#define BOLDRED "\033[1m\033[31m"   /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m" /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"
#define YELLOW "\033[33m"

class TestBigInt : public Testing {
public:
  void stringValidationTest() {

    // Test start message
    std::string testString =
        (std::string)BOLDYELLOW +
        "[stringValidationTest starts here]:" + (std::string)RESET;
    _logs.push_back(testString);
    bool isFailed = false;

    BigInt bigInt;
    std::ifstream stream("../src/test/testData.json");
    json j;
    stream >> j;

    int i = 0;
    json stringValidation = j["stringValidation"];

    while (!stringValidation[i].is_null()) {

      if (!assertionEquals(
              stringValidation[i]["expected"],
              bigInt.isValidString(stringValidation[i]["value"]),
              std::vector<std::string>{stringValidation[i]["value"]})) {
        isFailed = true;
      }

      i++;
    }

    // Test finish message
    if (isFailed) {
      testString = (std::string)BOLDRED + "[stringValidationTest FAILED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    } else {
      testString = (std::string)BOLDGREEN + "[stringValidationTest PASSED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    }
  }

  /*
      Test addition operation(+).
      Parsing test data from the JSON file.
  */
  void additionTest() {
    // Test start message
    std::string testString = (std::string)BOLDYELLOW +
                             "[additionTest starts here]:" + (std::string)RESET;
    _logs.push_back(testString);
    bool isFailed = false;

    // Test body
    BigInt bigInt;
    std::ifstream stream("../src/test/testData.json");
    json j;
    stream >> j;

    int i = 0;
    json additionTestCases = j["additionTestCases"];

    while (!additionTestCases[i].is_null()) {
      BigInt bi1((std::string)additionTestCases[i]["values"][0]);
      BigInt bi2((std::string)additionTestCases[i]["values"][1]);
      if (!assertionEquals(
              additionTestCases[i]["expected"], bi1.add(bi2).toString(),
              std::vector<std::string>{additionTestCases[i]["values"][0],
                                       additionTestCases[i]["values"][1]})) {
        isFailed = true;
      }

      i++;
    }

    // Broot force test cases

    int valuesFrom = -100;
    int valuesTo = 150;

    for (int i = valuesFrom; i < valuesTo; i++) {
      for (int j = valuesFrom; j < valuesTo; j++) {
        BigInt bi1(i);
        BigInt bi2(j);
        if (!assertionEquals(std::to_string((i + j)), bi1.add(bi2).toString(),
                             std::vector<std::string>{std::to_string(i),
                                                      std::to_string(j)})) {
          isFailed = true;
        }
      }
    }

    // Test finish message
    if (isFailed) {
      testString = (std::string)BOLDRED + "[additionTest FAILED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    } else {
      testString = (std::string)BOLDGREEN + "[additionTest PASSED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    }
  }

  /*
      Test substruct operation(-).
      Parsing test data from the JSON file.
  */
  void substructTest() {
    // Test start message
    std::string testString =
        (std::string)BOLDYELLOW +
        "[substructTest starts here]:" + (std::string)RESET;
    _logs.push_back(testString);
    bool isFailed = false;

    // Test body
    BigInt bigInt;
    std::ifstream stream("../src/test/testData.json");
    json j;
    stream >> j;

    int i = 0;
    json substructTestTestCases = j["substructTestTestCases"];

    while (!substructTestTestCases[i].is_null()) {
      BigInt bi1((std::string)substructTestTestCases[i]["values"][0]);
      BigInt bi2((std::string)substructTestTestCases[i]["values"][1]);

      if (!assertionEquals(substructTestTestCases[i]["expected"],
                           bi1.substruct(bi2).toString(),
                           std::vector<std::string>{
                               substructTestTestCases[i]["values"][0],
                               substructTestTestCases[i]["values"][1]})) {
        isFailed = true;
      }
      i++;
    }

    // Broot force test cases
    int valuesFrom = -100;
    int valuesTo = 150;

    for (int i = valuesFrom; i < valuesTo; i++) {
      for (int j = valuesFrom; j < valuesTo; j++) {
        BigInt bi1(i);
        BigInt bi2(j);

        if (!assertionEquals(std::to_string((i - j)),
                             bi1.substruct(bi2).toString(),
                             std::vector<std::string>{std::to_string(i),
                                                      std::to_string(j)})) {
          isFailed = true;
        }
      }
    }

    // Test finish message
    if (isFailed) {
      testString = (std::string)BOLDRED + "[substructTest FAILED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    } else {
      testString = (std::string)BOLDGREEN + "[substructTest PASSED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    }
  }

  /*
      Test multiply operation(*).
      Parsing test data from the JSON file.
  */
  void multiplyTest() {
    // Test start message
    std::string testString = (std::string)BOLDYELLOW +
                             "[multiplyTest starts here]:" + (std::string)RESET;
    _logs.push_back(testString);
    bool isFailed = false;

    // Test body
    BigInt bigInt;
    std::ifstream stream("../src/test/testData.json");
    json j;
    stream >> j;

    int i = 0;
    json multiplyTestCases = j["multiplyTestCases"];

    while (!multiplyTestCases[i].is_null()) {
      BigInt bi1((std::string)multiplyTestCases[i]["values"][0]);
      BigInt bi2((std::string)multiplyTestCases[i]["values"][1]);
      if (!assertionEquals(
              bi1.multiply(bi2).toString(), multiplyTestCases[i]["expected"],
              std::vector<std::string>{multiplyTestCases[i]["values"][0],
                                       multiplyTestCases[i]["values"][1]})) {
        isFailed = true;
      }
      i++;
    }

    // Broot force test cases
    int valuesFrom = -100;
    int valuesTo = 150;

    for (int i = valuesFrom; i < valuesTo; i++) {
      for (int j = valuesFrom; j < valuesTo; j++) {
        BigInt bi1(i);
        BigInt bi2(j);
        if (!assertionEquals(std::to_string((i * j)),
                             bi1.multiply(bi2).toString(),
                             std::vector<std::string>{std::to_string(i),
                                                      std::to_string(j)})) {
          isFailed = true;
        }
      }
    }

    // Test finish message
    if (isFailed) {
      testString = (std::string)BOLDRED + "[multiplyTest FAILED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    } else {
      testString = (std::string)BOLDGREEN + "[multiplyTest PASSED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    }
  }

  /*
      Test divide operation(/).
      Parsing test data from the JSON file.
  */
  void devideTest() {

    // Test start message
    std::string testString = (std::string)BOLDYELLOW +
                             "[devideTest starts here]:" + (std::string)RESET;
    _logs.push_back(testString);

    bool isFailed = false;
    std::string val1;
    std::string val2;

    BigInt bigInt;
    std::ifstream stream("../src/test/testData.json");
    json j;
    stream >> j;
    std::cout << "Size: " << j.size() << std::endl;
    int i = 0;
    json devideTestCases = j["devideTestCases"];

    while (!devideTestCases[i].is_null()) {
      val1 = (std::string)devideTestCases[i]["values"][0];
      val2 = (std::string)devideTestCases[i]["values"][1];
      BigInt bi1((std::string)devideTestCases[i]["values"][0]);
      BigInt bi2((std::string)devideTestCases[i]["values"][1]);
      if (!assertionEquals(
              bi1.divide(bi2).toString(), devideTestCases[i]["expected"],
              std::vector<std::string>{devideTestCases[i]["values"][0],
                                       devideTestCases[i]["values"][1]})) {
        isFailed = true;
      }
      i++;
    }

    // Broot force test cases
    int valuesFrom = -100;
    int valuesTo = 150;

    try {
      for (int i = valuesFrom; i < valuesTo; i++) {
        for (int j = valuesFrom; j < valuesTo; j++) {
          BigInt bi1(i);
          BigInt bi2(j);
          if (!assertionEquals(std::to_string((i / j)),
                               bi1.divide(bi2).toString(),
                               std::vector<std::string>{std::to_string(i),
                                                        std::to_string(j)})) {
            isFailed = true;
          }
        }
      }
    } catch (const char *e) {
      std::string exception =
          "Caught exceptions in devideTest. " + (std::string)RED + e + RESET;
      _logs.push_back(exception);
      isFailed = true;
    }

    // Test finish message
    if (isFailed) {
      testString = (std::string)BOLDRED + "[devideTest FAILED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    } else {
      testString = (std::string)BOLDGREEN + "[devideTest PASSED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    }
  }

  /*
        Test modulus operation(%).
        Parsing test data from the JSON file.
    */
  void modulusTest() {}

  /*
      Test comparison operation(<).
      Parsing test data from the JSON file.
  */
  void isLessThenTest() {

    // Test start message
    std::string testString =
        (std::string)BOLDYELLOW +
        "[isLessThenTest starts here]:" + (std::string)RESET;
    _logs.push_back(testString);
    bool isFailed = false;

    // Test body
    BigInt bigInt;
    std::ifstream stream("../src/test/testData.json");
    json j;
    stream >> j;

    int i = 0;
    json isLessThenTestCases = j["isLessThenTestCases"];

    while (!isLessThenTestCases[i].is_null()) {
      BigInt bi1((std::string)isLessThenTestCases[i]["values"][0]);
      BigInt bi2((std::string)isLessThenTestCases[i]["values"][1]);
      if (!assertionEquals(
              isLessThenTestCases[i]["expected"], bi1.isLessThen(bi2),
              std::vector<std::string>{isLessThenTestCases[i]["values"][0],
                                       isLessThenTestCases[i]["values"][1]})) {
        isFailed = true;
      }
      i++;
    }

    // Test finish message
    if (isFailed) {
      testString = (std::string)BOLDRED + "[isLessThenTest FAILED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    } else {
      testString = (std::string)BOLDGREEN + "[isLessThenTest PASSED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    }
  }

  /*
       Test comparison operation(==).
       Parsing test data from the JSON file.
   */
  void isEqualToTest() {
    // Test start message
    std::string testString =
        (std::string)BOLDYELLOW +
        "[isEqualToTest starts here]:" + (std::string)RESET;
    _logs.push_back(testString);
    bool isFailed = false;

    // Test body
    BigInt bigInt;
    std::ifstream stream("../src/test/testData.json");
    json j;
    stream >> j;

    int i = 0;
    json isEqualsToTestCases = j["isEqualsToTestCases"];

    while (!isEqualsToTestCases[i].is_null()) {
      BigInt bi1((std::string)isEqualsToTestCases[i]["values"][0]);
      BigInt bi2((std::string)isEqualsToTestCases[i]["values"][1]);
      if (!assertionEquals(
              isEqualsToTestCases[i]["expected"], bi1.isEqualTo(bi2),
              std::vector<std::string>{isEqualsToTestCases[i]["values"][0],
                                       isEqualsToTestCases[i]["values"][1]})) {
        isFailed = true;
      }
      i++;
    }
    // Test finish message
    if (isFailed) {
      testString = (std::string)BOLDRED + "[isEqualToTest FAILED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    } else {
      testString = (std::string)BOLDGREEN + "[isEqualToTest PASSED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    }
  }

  /*
       Test comparison operation(<).
       Generating data(numbers) in range from valsFrom to valsTo
   */
  void isLessThenBrootTest() {

    // Test start message
    std::string testString =
        (std::string)BOLDYELLOW +
        "[isLessThenBrootTest starts here]:" + (std::string)RESET;
    _logs.push_back(testString);
    bool isFailed = false;

    // Test body
    int valsFrom = -100;
    int valsTo = 100;

    for (int i = valsFrom; i < valsTo; i++) {
      for (int j = valsFrom; j < valsTo; j++) {
        BigInt n1(i);
        BigInt n2(j);

        if (!assertionEquals((i < j), n1.isLessThen(n2),
                             std::vector<std::string>{std::to_string(i),
                                                      std::to_string(j)})) {
          isFailed = true;
        }
      }
    }
    // Test finish message
    if (isFailed) {
      testString = (std::string)BOLDRED + "[isLessThenBrootTest FAILED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    } else {
      testString = (std::string)BOLDGREEN + "[isLessThenBrootTest PASSED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    }
  }

  /*
        Test comparison operation(>).
        Generating data(numbers) in range from valsFrom to valsTo
    */
  void isMoreThenBrootTest() {

    // Test start message
    std::string testString =
        (std::string)BOLDYELLOW +
        "[isMoreThenBrootTest starts here]:" + (std::string)RESET;
    _logs.push_back(testString);
    bool isFailed = false;

    // Test body
    int valsFrom = -150;
    int valsTo = 150;

    for (int i = valsFrom; i < valsTo; i++) {
      for (int j = valsFrom; j < valsTo; j++) {

        BigInt n1(i);
        BigInt n2(j);
        if (!assertionEquals((i > j), n1.isMoreThen(n2),
                             std::vector<std::string>{std::to_string(i),
                                                      std::to_string(j)})) {
          isFailed = true;
        }
      }
    }

    // Test finish message
    if (isFailed) {
      testString = (std::string)BOLDRED + "[isMoreThenBrootTest FAILED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    } else {
      testString = (std::string)BOLDGREEN + "[isMoreThenBrootTest PASSED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    }
  }

  /*
      Test comparison operation(==).
      Generating data(numbers) in range from valsFrom to valsTo
  */
  void isEqualToBrootTest() {

    // Test start message
    std::string testString =
        (std::string)BOLDYELLOW +
        "[isEqualToBrootTest starts here]:" + (std::string)RESET;
    _logs.push_back(testString);
    bool isFailed = false;

    // Test body
    int valsFrom = -100;
    int valsTo = 100;

    for (int i = valsFrom; i < valsTo; i++) {
      for (int j = valsFrom; j < valsTo; j++) {
        BigInt n1(i);
        BigInt n2(j);
        if (!assertionEquals((i == j), n1.isEqualTo(n2),
                             std::vector<std::string>{std::to_string(i),
                                                      std::to_string(j)})) {
          isFailed = true;
        }
      }
    }
    // Test finish message
    if (isFailed) {
      testString = (std::string)BOLDRED + "[isEqualToBrootTest FAILED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    } else {
      testString = (std::string)BOLDGREEN + "[isEqualToBrootTest PASSED]!" +
                   (std::string)RESET + "\n";
      _logs.push_back(testString);
    }
  }
};