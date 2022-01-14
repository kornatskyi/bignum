
#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define RESET "\033[0m"
#define RED "\033[31m"              /* Red */
#define GREEN "\033[32m"            /* Green */
#define BOLDRED "\033[1m\033[31m"   /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m" /* Bold Green */

class Testing {

public:
  std::vector<std::string> _logs;

public:
  void printLogs() {
    std::cout << BOLDGREEN << "[Tests LOGS]:" << RESET << std::endl;
    std::for_each(_logs.begin(), _logs.end(),
                  [](std::string s) { std::cout << s << std::endl; });
  }

  bool assertion(bool val1, bool val2) {
    if (val1 == val2) {
      //   std::cout << BOLDGREEN << "[ASSERTION] PASSED!" << RESET <<
      //   std::endl;
    } else {
      std::cout << RED << "ASSERTION FAILED!" << RESET << std::endl;
    }
  }

  bool assertion(bool expected, bool exact, std::string val) {
    if (expected == exact) {
      //   std::cout << BOLDGREEN << "[ASSERTION] PASSED!" << RESET <<
      //   std::endl;
    } else {

      std::string failString =
          (std::string)RED +
          "[ASSERTION FAILED] Expected: " + (expected ? "true" : "false") +
          " Get: " + (exact ? "true" : "false") + (std::string)RESET;
    }
  }

  bool assertionEquals(std::string expected, std::string exact,
                       std::vector<std::string> values) {
    std::string valsstr = "";
    int i = 1;
    for (auto val : values) {
      valsstr = valsstr + "value" + std::to_string(i) + ": " + val + " ";
      i++;
    }

    if (exact.compare(expected) == 0) {
      //   std::cout << BOLDGREEN << "[ASSERTION] PASSED!" << RESET <<
      //   std::endl;
      return true;
    } else {

      std::string failString = (std::string)RED +
                               "[FAILED] Expected: " + expected +
                               " Get: " + exact + "\n" +
                               " - [values]: " + valsstr + (std::string)RESET;

      _logs.push_back(failString);
      return false;
    }
  }

  bool assertionEquals(bool expected, bool exact,
                       std::vector<std::string> values) {
    std::string valsstr = "";

    int i = 1;

    for (auto val : values) {
      valsstr = valsstr + "value" + std::to_string(i) + ": " + val + " ";
      i++;
    }

    if (exact == expected) {
      //   std::cout << BOLDGREEN << "[ASSERTION] PASSED!" << RESET <<
      //   std::endl;
      return true;
    } else {

      std::string failString =
          (std::string)RED +
          "[ASSERTION FAILED] Expected: " + (expected ? "true" : "false") +
          " Get: " + (exact ? "true" : "false") + "\n" +
          " - [values]: " + valsstr + (std::string)RESET;

      _logs.push_back(failString);
      return false;
    }
  }
};