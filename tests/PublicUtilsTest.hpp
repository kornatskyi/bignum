#include "BigInt.hpp"
#include "Testing.hpp"

class PublicUtilsTest : public Testing {

public:
  void toStringTest() {
    bool isPassed = true;
    bool *isPassedP = &isPassed;

    auto lambda = [&](std::string s) {
      *isPassedP = (*this).assertion(s, BigInt(s).toString(),
                                     std::vector<std::string>{s});
    };
    lambda("123");
    lambda("0");
    lambda("1");
    lambda("-1");
    lambda("-123537985673498745423");
    lambda("1203");
    lambda("4567467375086974958670948576943579867984357");
    testMessage(isPassed, "toStringTest");
  }
};