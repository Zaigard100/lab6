#include "classes.h"
#include <fstream>
#include <iostream>
#include <string>

using std::cin;
using std::string;

int main() {
  PeopleLinkedList lst;
  string enter;
  string file;

  cout << "Из какого файла читать данные:\n";

  getline(cin, file);

  if (file == "")
    file = "list.txt";
  std::ifstream fin(file);
  do {
    getline(fin, enter);
    if (enter != "")
      lst.push_back(enter);
  } while (enter != "");

  cout << "\n\n";

  return 0;
}