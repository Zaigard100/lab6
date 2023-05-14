#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <cstring>

using std::cin;
using std::cout;
using std::string;

class PeopleData {
public: 
  string fio;
  string post;
  string address;

  PeopleData *prev, *next;

  string get_data(int num);
  PeopleData(string fio, string post,string address);
  PeopleData(string data);

};

class PeopleLinkedList {
public:
  PeopleData *head, *tail;

  PeopleLinkedList();
  ~PeopleLinkedList();

  PeopleData * push_front(string fio, string post, string address);
  PeopleData *push_front(string data);

  PeopleData *push_back(string fio, string post, string address);
  PeopleData *push_back(string data);

  void pop_front();
  void pop_back();

  PeopleData *getAt(unsigned index);

  PeopleData *operator[](unsigned index) { return getAt(index); }

  PeopleData *insert(unsigned index, string fio, string post, string address);
  PeopleData *insert(unsigned index, string data);

  void earse(unsigned index);

  void clear();

  int isExist(int elementnum, string data);

  int isExistData(string fio, string post,string address);
  int isExistData(string data);

  void castling(int first, int second);

  void sort(int elementnum);

};

#endif //CLASSES_H