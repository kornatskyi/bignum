#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <math.h>

#include <fstream>
#include <string>

#include "BigInt.hpp"
#include "DataSet.hpp"

#include <stdio.h>

class PerformanceTest {
  DataSet _dataset;
  std::string _output = "time(ms)|n*m|n|m|operation\n";

public:
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

    _output += std::to_string(ms_double.count()) + "|" + description + "\n";

    // std::cout << description << std::endl;
    // std::cout << ms_int.count() << "ms\n";
    // std::cout << ms_double.count() << "ms\n";
  }

  void addition() {

    _output = "time(ms)|n*m|n|m|operation\n";

    for (int i = 0; i < _dataset.data.size(); i++) {
      BigInt *n1 = &_dataset.data[i].number1;
      BigInt *n2 = &_dataset.data[i].number2;
      auto addition = [=]() { (*n1) + (*n2); };

      int n = n1->length();
      int m = n2->length();
      std::string result = std::to_string(n * m) + "|" + std::to_string(n) +
                           "|" + std::to_string(m) + "|+";

      messureExecutionTime(addition, result);
    }
    writeOutputToTheFile("addition_performance_test.txt");
  }

  void substruction() {

    // Reset output
    _output = "time(ms)|n*m|n|m|operation\n";

    for (int i = 0; i < _dataset.data.size(); i++) {
      BigInt *n1 = &_dataset.data[i].number1;
      BigInt *n2 = &_dataset.data[i].number2;
      auto addition = [=]() { (*n1) - (*n2); };

      int n = n1->length();
      int m = n2->length();
      std::string result = std::to_string(n * m) + "|" + std::to_string(n) +
                           "|" + std::to_string(m) + "|-";

      messureExecutionTime(addition, result);
    }
    writeOutputToTheFile("substruction_performance_test.txt");
  }
  void multiplication() {

    _output = "time(ms)|n*m|n|m|operation\n";

    for (int i = 0; i < _dataset.data.size(); i++) {
      BigInt *n1 = &_dataset.data[i].number1;
      BigInt *n2 = &_dataset.data[i].number2;
      auto addition = [=]() { (*n1) * (*n2); };

      int n = n1->length();
      int m = n2->length();
      std::string result = std::to_string(n * m) + "|" + std::to_string(n) +
                           "|" + std::to_string(m) + "|*";

      messureExecutionTime(addition, result);
    }
    writeOutputToTheFile("multiplication_performance_test.txt");
  }

  void division() {

    _output = "time(ms)|n*m|n|m|operation\n";

    for (int i = 0; i < _dataset.data.size(); i++) {
      BigInt *n1 = &_dataset.data[i].number1;
      BigInt *n2 = &_dataset.data[i].number2;
      auto addition = [=]() { (*n1) / (*n2); };

      int n = n1->length();
      int m = n2->length();
      std::string result = std::to_string(n * m) + "|" + std::to_string(n) +
                           "|" + std::to_string(m) + "|/";

      messureExecutionTime(addition, result);
    }
    writeOutputToTheFile("division_performance_test.txt");
  }
  void modulus() {

    _output = "time(ms)|n*m|n|m|operation\n";

    for (int i = 0; i < _dataset.data.size(); i++) {
      BigInt *n1 = &_dataset.data[i].number1;
      BigInt *n2 = &_dataset.data[i].number2;
      auto addition = [=]() { (*n1) % (*n2); };

      int n = n1->length();
      int m = n2->length();
      std::string result = std::to_string(n * m) + "|" + std::to_string(n) +
                           "|" + std::to_string(m) + "|%";

      messureExecutionTime(addition, result);
    }
    writeOutputToTheFile("modulus_performance_test.txt");
  }

  void printOutput() { std::cout << _output << std::endl; }

  void writeOutputToTheFile(std::string filename) {
    std::ofstream output_file;
    output_file.open(filename);
    output_file << _output;

    output_file.close();
  }
};
