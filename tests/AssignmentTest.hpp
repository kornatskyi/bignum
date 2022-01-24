#include "BigInt.hpp"

#include "./Testing.hpp"

class AssignmentTest : public Testing {
public:
  void runAll() {
    intAssignmentTest();
    stringAssignmentTest();
    charArrAssignmentTest();
  }

  // TODO
  void charArrAssignmentTest(){

  };

  void intAssignmentTest() {

    int from = -150;
    int to = 150;
    bool isPassed = true;

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
    bool isPassed = true;

    for (int i = from; i < to; i++) {
      BigInt bi = std::to_string(i);
      std::vector<std::string> values{std::to_string(i)};
      if (!assertion(std::to_string(i), bi.toString(), values)) {
        isPassed = false;
      }
    }
    testMessage(isPassed, "stringAssignmentTest");
  }

  /* Arithmetic assignmet */

  void addAssignTest() {

    bool isPassed = true;
    // isPassed = assertion();

    testMessage(isPassed, "addAssignTest");
  }
};