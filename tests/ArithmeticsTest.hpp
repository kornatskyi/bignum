#pragma once

#include <fstream>
#include <iostream>

#include <string>
#include <vector>

#include "BigInt.hpp"
#include "Testing.hpp"

class ArithmeticsTest : public Testing {
public:
  void runAll() {
    additionTest();
    subtractTest();
    multiplyTest();
    devideTest();
    modulusTest();
  }
  /*
    Arithmetic operations testing

  */

  void additionTest() {

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
    testMessage(isPassed, "additionTest");
  }

  void subtractTest() {

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
    testMessage(isPassed, "subtractTest");
  }
  void multiplyTest() {

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
    testMessage(isPassed, "multiplyTest");
  }
  void devideTest() {

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
    testMessage(isPassed, "devideTest");
  }
  void modulusTest() {

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
    testMessage(isPassed, "modulusTest");
  }
};