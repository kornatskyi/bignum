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

  BigInt x;
  x.allocateVector(1);

  BigInt lhn =
      "547698734589679843576878934769845796874596547698734589679843576878934769"
      "3576878934769845796874596";
  BigInt rhn =
      "547698734589679843576878934769845796874596547698734589679843576878934769"
      "84579687459654769873458967984357687893476984579687459654769873458967984"
      "3";
  // std::cout << lhn.longMultiplication(rhn) << std::endl;
  // std::cout << lhn.karatsubaMultiplication(rhn) << std::endl;

  BigInt res = lhn.longMultiplication(rhn);
  // std::cout << "Muliplication:" << res << std::endl;
  BigInt resKaratsuba = lhn.karatsubaMultiplication(rhn);
  // std::cout << "Karatsuba:" << resKaratsuba << std::endl;

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
