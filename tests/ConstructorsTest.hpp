

#include "BigInt.hpp"
#include "Testing.hpp"
class ConstructorsTest : public Testing {

public:
  void intConstructorTest() {
    bool isPassed = true;
    bool *isPassedP = &isPassed;

    auto lambda = [&](int n) {
      try {
        *isPassedP =
            (*this).assertion(n, BigInt(n).toInteger(), std::vector<int>{n});

      } catch (...) {
        std::cout << "Exception in intConstructorTest: \n"
                  << "value: " << n << std::endl;
      }
    };
    lambda(12);
    lambda(-0);
    lambda(-1);
    lambda(2147483647);
    lambda(-2147483647);
    testMessage(isPassed, "intConstructorTest");
  }

  void stringConstructorTest() {
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
    lambda("12", "12");
    lambda("0", "-0");
    lambda("-1", "-1");
    lambda("2147483647", "2147483647");
    lambda("-2147483647", "-2147483647");
    testMessage(isPassed, "stringConstructorTest");
  }
};