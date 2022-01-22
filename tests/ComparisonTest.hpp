#pragma once

#include <fstream>
#include <iostream>

#include <string>
#include <vector>

#include "BigInt.hpp"
#include "Testing.hpp"

class ComparisonTest : public Testing {
public:
  void runAll() {
    isLessThenTest();
    isEqualToTest();
    isLessOrEqualTo();
    isMoreOrEqualTo();
    isMoreThenTest();
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
};