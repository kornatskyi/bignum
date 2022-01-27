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
      "450736345807645068745306784503678943576087450896734589076890745324375623"
      "458973248906728349758720893659534580934859083490588923476742378609234705"
      "7890234760947309580234978609743906709342850983420957304927609234";
  BigInt rhn = "745697045389670347869734506734958768942790843589026385967234895"
               "798234758923468957348976890237589063428957342896893427589723489"
               "57893472857834758926589423659872349857983475897";
  BigInt res = lhn.longMultiplication(rhn);
  BigInt resKaratsuba = lhn * rhn;

  BigInt *n1 = &lhn;
  BigInt *n2 = &rhn;
  // std::cout << "Karatsuba:" << resKaratsuba << std::endl;
  // std::cout << "Muliplication:" << res << std::endl;

  auto karatsuba = [=]() { (*n1) * (*n2); };
  auto school = [=]() { (*n1).longMultiplication(*n2); };
  messureExecutionTime(school, "School:");
  messureExecutionTime(karatsuba, "Karatsuba:");

  // std::cout << "Res:" << res << std::endl;
  // std::cout << "Karatsuba res:" << resKaratsuba << std::endl;
  // std::cout << "Main function in src/" << std::endl;
  return 0;
}
