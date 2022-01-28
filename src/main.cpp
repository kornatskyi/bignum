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

  BigInt lhn =
      "654635645075565463564506546356450755265463564507552654635645075526546356"
      "450755265463564507552654635645075526546356450755265463564507552654635645"
      "5";
  BigInt rhn =
      "-654635645654635646546356450755654635645075526546356450755265463"
      "564507552";

  BigInt res = lhn.longMultiplication(rhn);
  std::cout << "Muliplication:" << res << std::endl;
  BigInt resKaratsuba = lhn.karatsubaMultiplication(rhn);
  std::cout << "Karatsuba:" << resKaratsuba << std::endl;

  BigInt *n1 = &lhn;
  BigInt *n2 = &rhn;

  auto karatsuba = [=]() { (*n1).karatsubaMultiplication(*n2); };
  auto school = [=]() { (*n1).longMultiplication(*n2); };
  messureExecutionTime(school, "School:");
  messureExecutionTime(karatsuba, "Karatsuba:");

  // std::cout << "Res:" << res << std::endl;
  // std::cout << "Karatsuba res:" << resKaratsuba << std::endl;
  // std::cout << "Main function in src/" << std::endl;
  return 0;
}
