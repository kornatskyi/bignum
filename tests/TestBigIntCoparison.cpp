#include "../src/BigInt.h"
#include "TestBigInt.h"

/*
      Test comparison operation(<).
      Parsing test data from the JSON file.
  */
void TestBigInt::isLessThenTest() {

  // Test start message
  std::string testString = (std::string)BOLDYELLOW +
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
void TestBigInt::isEqualToTest() {
  // Test start message
  std::string testString = (std::string)BOLDYELLOW +
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
void TestBigInt::isLessThenBrootTest() {

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

      if (!assertionEquals(
              (i < j), n1.isLessThen(n2),
              std::vector<std::string>{std::to_string(i), std::to_string(j)})) {
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
void TestBigInt::isMoreThenBrootTest() {

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
      if (!assertionEquals(
              (i > j), n1.isMoreThen(n2),
              std::vector<std::string>{std::to_string(i), std::to_string(j)})) {
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
void TestBigInt::isEqualToBrootTest() {

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
      if (!assertionEquals(
              (i == j), n1.isEqualTo(n2),
              std::vector<std::string>{std::to_string(i), std::to_string(j)})) {
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