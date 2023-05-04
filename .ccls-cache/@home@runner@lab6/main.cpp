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

  std::ifstream fin(file);
  do {
    getline(fin, enter);
    if (enter != "")
      lst.push_back(enter);
  } while (enter != "");
  
  cout << "\n";
  if(lst.isExistData("Фролов","Антон","Данилович","кузнец","спуск Космонавтов, 81")){
    cout << "Exist";
  }else{
    cout << "No Exist";
  }
  return 0;
}