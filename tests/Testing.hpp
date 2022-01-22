
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

#include "json.hpp"

class Testing {
protected:
  nlohmann::json _json;

public:
  Testing() {
    std::ifstream i("./tests/cases/testData.json");
    i >> _json;
  }

  bool assertion(bool expected, bool exact, std::vector<std::string> values) {
    if (expected == exact) {
      // std::cout << BOLDGREEN << "[ASSERTION] PASSED!" << RESET << std::endl;
      return true;
    } else {
      std::cout << RED << "ASSERTION FAILED!"
                << "\nExpected: " << expected << " Exact: " << exact << " ";
      int i = 1;
      for (std::string val : values) {
        std::cout << "Value" << i << ": " << val << " ";
        i++;
      }
      std::cout << RESET << std::endl;
      return false;
    }
  }

  bool assertion(std::string expected, std::string exact,
                 std::vector<std::string> values) {
    if (expected.compare(exact) == 0) {
      // std::cout << BOLDGREEN << "[ASSERTION] PASSED!" << RESET << std::endl;
      return true;
    } else {
      std::cout << RED << "ASSERTION FAILED!"
                << "\nExpected: " << expected << " Exact: " << exact << " ";
      int i = 1;
      for (std::string val : values) {
        std::cout << "Value" << i << ": " << val << " ";
        i++;
      }
      std::cout << RESET << std::endl;
      return false;
    }
  }

  void testMessage(bool isPassed, std::string testName) {

    if (isPassed) {
      std::cout << BOLDGREEN << "Test " << testName << " passed!" << RESET
                << std::endl;
    } else {
      std::cout << BOLDRED << "Test " << testName << " failed!" << RESET
                << std::endl;
    }
  }
};