#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <math.h>

#include <fstream>
#include <string>

#include "BigInt.hpp"

#include <stdio.h>

void messureExecutionTime(const std::function<void()> &function,
                          std::string description) {
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  auto t1 = high_resolution_clock::now();
  function();
  auto t2 = high_resolution_clock::now();

  /* Getting number of milliseconds as an integer. */
  auto ms_int = duration_cast<milliseconds>(t2 - t1);

  /* Getting number of milliseconds as a double. */
  duration<double, std::milli> ms_double = t2 - t1;

  std::cout << description << std::endl;
  std::cout << ms_int.count() << "ms\n";
  std::cout << ms_double.count() << "ms\n";
}

int main(int, char **) {

  // BigInt n1 =
  //     "3567983423927357293759823795345734769347678348758723759772340238";

  // BigInt n2 =
  //     "2375977234023840234232349078503479857349758934798578934735679834";

  // auto addition = [=]() { n1 + n2; };
  // auto substruction = [=]() { n1 - n2; };
  // auto division = [=]() { n1 / n2; };
  // auto multiplication = [=]() { n1 *n2; };
  // auto modulus = [=]() { BigInt("123"); };

  // messureExecutionTime(addition, (n1.toString() + " + " + n2.toString()));
  // messureExecutionTime(substruction, (n1.toString() + " - " +
  // n2.toString())); messureExecutionTime(multiplication, (n1.toString() + " *
  // " + n2.toString())); messureExecutionTime(division, (n1.toString() + " / "
  // + n2.toString())); messureExecutionTime(modulus, (n1.toString() + " % " +
  // n2.toString()));

  for (int i = 1; i < 20; i++) {
    BigInt random = rand() % (pow(10, (i + 1))) + pow(10, i);
    std::cout << random << std::endl;
  }

  // std::cout << "Main function in src/" << std::endl;
  return 0;
}
