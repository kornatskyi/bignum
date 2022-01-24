

#include <string>
#include <vector>
struct Numbers {
  std::string number1;
  std::string number2;
  Numbers(std::string n1, std::string n2) {
    number1 = n1;
    number2 = n2;
  }
};

std::vector<Numbers> dataset{
    Numbers("1", "1"),       Numbers("13", "75"),      Numbers("534", "784"),
    Numbers("2347", "4235"), Numbers("4277", "43555"), Numbers("1", "1"),
    Numbers("1", "1"),       Numbers("1", "1"),        Numbers("1", "1"),
    Numbers("1", "1"),       Numbers("1", "1"),        Numbers("1", "1"),
    Numbers("1", "1"),       Numbers("1", "1"),        Numbers("1", "1"),
    Numbers("1", "1"),       Numbers("1", "1"),        Numbers("1", "1"),
    Numbers("1", "1"),       Numbers("1", "1"),        Numbers("1", "1"),
    Numbers("1", "1"),       Numbers("1", "1"),        Numbers("1", "1"),
    Numbers("1", "1"),       Numbers("1", "1"),        Numbers("1", "1"),
    Numbers("1", "1"),       Numbers("1", "1"),

};