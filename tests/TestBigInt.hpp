#pragma once

#include <fstream>
#include <iostream>

#include <string>
#include <vector>

#include "../include/BigInt.hpp"
#include "Testing.hpp"

class TestBigInt : public Testing {
public:
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

  void substructTest() {

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
    testMessage(isPassed, "substructTest");
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

  /*

    Comperison operations testing

  */
  void isLessThenTest() {

    int from = -150;
    int to = 150;
    int isPassed = true;

    for (int i = from; i < to; i++) {
      for (int j = from; j < to; j++) {

        std::vector<std::string> values{std::to_string(i), std::to_string(j)};
        if (!assertion(i < j, (BigInt(i) < BigInt(j)), values)) {

          isPassed = false;
        }
      }
    }
    testMessage(isPassed, "isLessThenTest");
  }
  void isEqualToTest() {

    int from = -150;
    int to = 150;
    int isPassed = true;

    for (int i = from; i < to; i++) {
      for (int j = from; j < to; j++) {

        std::vector<std::string> values{std::to_string(i), std::to_string(j)};
        if (!assertion(i == j, (BigInt(i) == BigInt(j)), values)) {

          isPassed = false;
        }
      }
    }
    testMessage(isPassed, "isEqualToTest");
  }

  void notEqualToTest() {

    int from = -150;
    int to = 150;
    int isPassed = true;

    for (int i = from; i < to; i++) {
      for (int j = from; j < to; j++) {

        std::vector<std::string> values{std::to_string(i), std::to_string(j)};
        if (!assertion(i != j, (BigInt(i) != BigInt(j)), values)) {

          isPassed = false;
        }
      }
    }
    testMessage(isPassed, "notEqualToTest");
  }
  void isMoreThenTest() {

    int from = -150;
    int to = 150;
    int isPassed = true;

    for (int i = from; i < to; i++) {
      for (int j = from; j < to; j++) {

        std::vector<std::string> values{std::to_string(i), std::to_string(j)};
        if (!assertion(i > j, (BigInt(i) > BigInt(j)), values)) {

          isPassed = false;
        }
      }
    }
    testMessage(isPassed, "isMoreThenTest");
  }
  void isLessOrEqualTo() {

    int from = -150;
    int to = 150;
    int isPassed = true;

    for (int i = from; i < to; i++) {
      for (int j = from; j < to; j++) {

        std::vector<std::string> values{std::to_string(i), std::to_string(j)};
        if (!assertion(i <= j, (BigInt(i) <= BigInt(j)), values)) {

          isPassed = false;
        }
      }
    }
    testMessage(isPassed, "isLessOrEqualTo");
  }
  void isMoreOrEqualTo() {

    int from = -150;
    int to = 150;
    int isPassed = true;

    for (int i = from; i < to; i++) {
      for (int j = from; j < to; j++) {

        std::vector<std::string> values{std::to_string(i), std::to_string(j)};
        if (!assertion(i >= j, (BigInt(i) >= BigInt(j)), values)) {

          isPassed = false;
        }
      }
    }
    testMessage(isPassed, "isMoreOrEqualTo");
  }

  void intAssignmentTest() {

    int from = -150;
    int to = 150;
    int isPassed = true;

    for (int i = from; i < to; i++) {

      BigInt bi = i;

      std::vector<std::string> values{std::to_string(i)};
      if (!assertion(std::to_string(i), bi.toString(), values)) {

        isPassed = false;
      }
    }
    testMessage(isPassed, "intAssignmentTest");
  }

  void stringAssignmentTest() {

    int from = -150;
    int to = 150;
    int isPassed = true;

    for (int i = from; i < to; i++) {
      BigInt bi = std::to_string(i);
      std::vector<std::string> values{std::to_string(i)};
      if (!assertion(std::to_string(i), bi.toString(), values)) {
        isPassed = false;
      }
    }
    testMessage(isPassed, "stringAssignmentTest");
  }

  // TODO
  void charArrAssignmentTest();

  /*
    Utilities methods testing
  */
  // TODO
  void stringValidationTest();
};