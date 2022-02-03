#pragma once

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

class DataGenerator {

public:
  static char randomDigitButZero() {
    srand(time(NULL));
    std::string randomString = std::to_string(rand());
    char notZero = randomString[randomString.length() - 1];
    while (!notZero) {
      notZero = randomString[randomString.length() - 1];
    }
    return notZero;
  }

  static void generateNumberSets() {
    // Seed pseudo-random number generator
    // Should be seeded only once before the program execution
    srand(time(NULL));

    std::string OUTPUT_FILE_PATH = "data.txt";
    std::fstream file;
    file.open(OUTPUT_FILE_PATH);

    // string of digits
    std::string digits = "";
    // How many random numbers will be generated
    int numberOfGenerations = 100;
    // Adding each number to the `digits` string. Generating string of digits.
    for (int i = 0; i < numberOfGenerations; i++) {
      digits += std::to_string(rand());
    }

    // true == numbers will be added to the vector from smallest to largest,
    // false == largest -> smallest
    bool reverseOrder = true;
    // differenc between two numbers in digits
    int numbersLengthGrowth = 10;

    // j will be used as a split index for creating substing(number)
    int j = 1;
    // nums1 == fist array of numbers, numbs2 == seccond array of numbers,
    // tempnums used for creating reversed array of numbers
    std::vector<std::string> nums1, tempnums, nums2;

    // spliting string and pushing substrings(numbers) to the nums1
    for (int i = 0; i < digits.length(); i = i + j) {
      std::string substring = digits.substr(i, j);

      // if firs digit is zero replace it with random not zero value
      if (substring[0] == '0') {
        substring[0] = randomDigitButZero();
      }

      nums1.push_back(substring);
      j = j + numbersLengthGrowth;
    }

    // reseting string
    digits = "";
    // generating new string with the same length
    for (int i = 0; i < numberOfGenerations; i++) {
      digits += std::to_string(rand());
    }

    // reseting j
    j = 1;
    // check if we do nums2 in reversed order
    if (reverseOrder) {
      /*** Reversed generation ***/
      for (int i = 0; i < digits.length(); i = i + j) {
        std::string substring = digits.substr(i, j);

        // if firs digit is zero replace it with random not zero value
        if (substring[0] == '0') {
          substring[0] = randomDigitButZero();
        }

        tempnums.push_back(substring);
        j++;
      }

      for (int i = tempnums.size() - 1; i >= 0; i--) {
        nums2.push_back(tempnums[i]);
      }
    } else {
      /*** Normal generation ***/
      for (int i = 0; i < digits.length(); i = i + j) {
        std::string substring = digits.substr(i, j);

        // if firs digit is zero replace it with random not zero value
        if (substring[0] == '0') {
          substring[0] = randomDigitButZero();
        }

        nums2.push_back(substring);
        j = j + numbersLengthGrowth;
      }
    }

    // frame numbers into format that will be easy to copy and paste
    std::string generatedString = "";
    for (int i = 0; i < nums1.size(); i++) {
      generatedString +=
          "NumbersSet(\"" + nums1[i] + "\",\"" + nums2[i] + "\"),\n";
    }
    // writing to the file
    file << generatedString;

    file.close();
  }
};