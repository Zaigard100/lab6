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

  file = "list.txt";

  std::ifstream fin(file);
  do {
    getline(fin, enter);
    if (enter != "")
      lst.push_back(enter);
  } while (enter != "");

  PeopleData *ptr = lst.head;
    while(ptr!=NULL){
    cout<<ptr->lastname<<' '<<ptr->name<<' '<<ptr->patronymic<<", "<<ptr->post<<", "      <<ptr->address<<'\n';
    ptr = ptr->next;
  }
  
  cout << "\n";
  if (lst.isExistData("Фролов", "Антон", "Данилович", "кузнец",
                      "спуск Космонавтов, 81")!=-1) {
    cout << "Exist";
  } else {
    cout << "No Exist";
  }
  cout << "\n";
  
  lst.sort(0);
  
  cout << "\n";
  ptr = lst.head;
  while(ptr!=NULL){
    cout<<ptr->lastname<<' '<<ptr->name<<' '<<ptr->patronymic<<", "<<ptr->post<<", "      <<ptr->address<<'\n';
    ptr = ptr->next;
  }
    
  return 0;
}

