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
        std::cout << "Exception in additionTest: \n"
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

  void subtractTest() {
    bool isPassed = true;
    bool *isPassedP = &isPassed;

    auto lambda = [&](std::string expected, std::string value) {
      try {
        *isPassedP = (*this).assertion(expected, BigInt(value).toString(),
                                       std::vector<std::string>{value});
      } catch (...) {
        std::cout << "Exception in subtractTest: \n"
                  << "value: " << value << std::endl;
      }
    };
    lambda("4294967294",
           (BigInt("2147483647") - BigInt("-2147483647")).toString());
    lambda("-4294967294",
           (BigInt("-2147483647") - BigInt("2147483647")).toString());
    lambda("0", (BigInt("2147483647") - BigInt("2147483647")).toString());
    lambda("0", (BigInt("0") - BigInt("-0")).toString());
    lambda("2", (BigInt("1") - BigInt("-1")).toString());
    lambda("100000", (BigInt("99999") - BigInt("-1")).toString());
    lambda("99999", (BigInt("100000") - BigInt("1")).toString());
    lambda("-628864409219699061825412", (BigInt("45673458760754645068945") -
                                         BigInt("674537867980453706894357"))
                                            .toString());

    lambda("-347654311336939223596725372989599997684227179174845313417222845017"
           "37490025551",
           (BigInt("46234589342659721983759816985712395623897489236589"
                   "7235698237849236956823") -
            BigInt("3476589347958734895689237489712985689237"
                   "8956892376897238957982739586726982374"))
               .toString());

    testMessage(isPassed, "subtractTest");
  }

  void multiplyTest() {
    bool isPassed = true;
    bool *isPassedP = &isPassed;

    auto lambda = [&](BigInt expected, BigInt value) {
      try {
        *isPassedP =
            (*this).assertion(expected, BigInt(value),
                              std::vector<std::string>{value.toString()});
      } catch (...) {
        std::cout << "Exception in multiplyTest: \n"
                  << "value: " << value << std::endl;
      }
    };
    lambda(BigInt("81"), (BigInt("9") * BigInt("9")));

    lambda(BigInt("-81"), (BigInt("-9") * BigInt("9")));

    lambda(BigInt("160738680815937236285390686612472073585539643326415793195758"
                  "804746559870393978154968343064374209823658345472850784643569"
                  "67659153474389832237720037802"),
           (BigInt("46234589342659721983759816985712395623897489"
                   "2365897235698237849236956823") *
            BigInt("34765893479587348956892374897129856892378956"
                   "892376897238957982739586726982374")));
    testMessage(isPassed, "multiplyTest");
  }
  void devideTest() {
    bool isPassed = true;
    bool *isPassedP = &isPassed;

    auto lambda = [&](BigInt expected, BigInt value) {
      try {
        *isPassedP =
            (*this).assertion(expected, BigInt(value),
                              std::vector<std::string>{value.toString()});
      } catch (...) {
        std::cout << "Exception in devideTest: \n"
                  << "value: " << value << std::endl;
      }
    };
    lambda(BigInt("1"), (BigInt("9") / BigInt("9")));

    lambda(BigInt("-1"), (BigInt("-9") / BigInt("9")));
    lambda(BigInt("291754781101649063733415863880"),
           (BigInt("94598265892759237895723897492365325176349863217492317856238652") /
            BigInt("324238956892365892374923987985637")));
   
    testMessage(isPassed, "devideTest");
  }

  void modulusTest() {
        bool isPassed = true;
    bool *isPassedP = &isPassed;

    auto lambda = [&](BigInt expected, BigInt value) {
      try {
        *isPassedP =
            (*this).assertion(expected, BigInt(value),
                              std::vector<std::string>{value.toString()});
      } catch (...) {
        std::cout << "Exception in modulusTest: \n"
                  << "value: " << value << std::endl;
      }
    };
    lambda(BigInt("0"), (BigInt("9") % BigInt("9")));

    lambda(BigInt("0"), (BigInt("-9") % BigInt("9")));
    lambda(BigInt("-1"),
           (BigInt("-51") %
            BigInt("5")));
   
    testMessage(isPassed, "modulusTest");
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