
#include "TestBigInt.h"

#define RESET "\033[0m"
#define RED "\033[31m"              /* Red */
#define GREEN "\033[32m"            /* Green */
#define BOLDRED "\033[1m\033[31m"   /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m" /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"
#define YELLOW "\033[33m"

void TestBigInt::stringValidationTest() {

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
void TestBigInt::additionTest() {
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
      if (!assertionEquals(
              std::to_string((i + j)), bi1.add(bi2).toString(),
              std::vector<std::string>{std::to_string(i), std::to_string(j)})) {
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
void TestBigInt::substructTest() {
  // Test start message
  std::string testString = (std::string)BOLDYELLOW +
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

    if (!assertionEquals(
            substructTestTestCases[i]["expected"],
            bi1.substruct(bi2).toString(),
            std::vector<std::string>{substructTestTestCases[i]["values"][0],
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

      if (!assertionEquals(
              std::to_string((i - j)), bi1.substruct(bi2).toString(),
              std::vector<std::string>{std::to_string(i), std::to_string(j)})) {
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
void TestBigInt::multiplyTest() {
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
      if (!assertionEquals(
              std::to_string((i * j)), bi1.multiply(bi2).toString(),
              std::vector<std::string>{std::to_string(i), std::to_string(j)})) {
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
void TestBigInt::devideTest() {

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
void TestBigInt::modulusTest() {}
