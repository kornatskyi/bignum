#pragma once
#include "BigInt.hpp"
#include "Testing.hpp"
#include <iostream>
#include <string>
#include <vector>
class ArithmeticsTest : public Testing {
public:
  void runAll() {
    additionTest();
    subtractTest();
    multiplyTest();
    devideTest();
    modulusTest();
    additionBruteTest();
    subtractBruteTest();
    multiplyBruteTest();
    devideBruteTest();
    modulusBruteTest();
  }
  /*
    Arithmetic operations testing
  */
  void additionTest() {
    bool isPassed = true;
    bool *isPassedP = &isPassed;

    auto lambda = [&](std::string expected, std::string value) {
      try {
        *isPassedP = (*this).assertion(expected, BigInt(value).toString(),
                                       std::vector<std::string>{value});
      } catch (...) {
        std::cout << "Exception in stringConstructorTest: \n"
                  << "value: " << value << std::endl;
      }
    };
    lambda("0", (BigInt("2147483647") + BigInt("-2147483647")).toString());
    lambda("0", (BigInt("0") + BigInt("-0")).toString());
    lambda("0", (BigInt("1") + BigInt("-1")).toString());
    lambda("100000", (BigInt("99999") + BigInt("1")).toString());
    lambda("99999", (BigInt("100000") + BigInt("-1")).toString());
    lambda("-628864409219699061825412", (BigInt("45673458760754645068945") +
                                         BigInt("-674537867980453706894357"))
                                            .toString());
    testMessage(isPassed, "additionTest");
  }

  void additionBruteTest() {

    int from = -150;
    int to = 150;
    int isPassed = true;

    for (int i = from; i < to; i++) {
      for (int j = from; j < to; j++) {

        BigInt res = BigInt(i) + BigInt(j);
        std::vector<std::string> values{std::to_string(i), std::to_string(j)};

        if (!assertion(std::to_string(i + j), res.toString(), values)) {

          isPassed = false;
        }
      }
    }
    testMessage(isPassed, "additionBruteTest");
  }

  void subtractTest() {}
  void multiplyTest() {}
  void devideTest() {}
  void modulusTest() {}

  void subtractBruteTest() {

    int from = -150;
    int to = 150;
    int isPassed = true;

    for (int i = from; i < to; i++) {
      for (int j = from; j < to; j++) {

        BigInt res = BigInt(i) - BigInt(j);
        std::vector<std::string> values{std::to_string(i), std::to_string(j)};

        if (!assertion(std::to_string(i - j), res.toString(), values)) {

          isPassed = false;
        }
      }
    }
    testMessage(isPassed, "subtractBruteTest");
  }
  void multiplyBruteTest() {

    int from = -150;
    int to = 150;
    int isPassed = true;

    for (int i = from; i < to; i++) {
      for (int j = from; j < to; j++) {

        BigInt res = BigInt(i) * BigInt(j);
        std::vector<std::string> values{std::to_string(i), std::to_string(j)};

        if (!assertion(std::to_string(i * j), res.toString(), values)) {

          isPassed = false;
        }
      }
    }
    testMessage(isPassed, "multiplyBruteTest");
  }
  void devideBruteTest() {

    int from = -150;
    int to = 150;
    int isPassed = true;

    for (int i = from; i < to; i++) {
      for (int j = from; j < to; j++) {
        if (j == 0)
          continue;
        BigInt res = BigInt(i) / BigInt(j);
        std::vector<std::string> values{std::to_string(i), std::to_string(j)};
        if (!assertion(std::to_string(i / j), res.toString(), values)) {

          isPassed = false;
        }
      }
    }
    testMessage(isPassed, "devideBruteTest");
  }
  void modulusBruteTest() {

    int from = -150;
    int to = 150;
    int isPassed = true;

    for (int i = from; i < to; i++) {
      for (int j = from; j < to; j++) {
        if (j == 0)
          continue;
        BigInt res = BigInt(i) % BigInt(j);
        std::vector<std::string> values{std::to_string(i), std::to_string(j)};
        if (!assertion(std::to_string(i % j), res.toString(), values)) {

          isPassed = false;
        }
      }
    }
    testMessage(isPassed, "modulusBruteTest");
  }
};