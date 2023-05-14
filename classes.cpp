#include <iostream>
#include <string>
#include <cstring>
#include "classes.h"

using std::cin;
using std::cout;
using std::string;

  string PeopleData::get_data(int num){
      if(num == 0){
        return fio;
      }else if(num == 1){
        return post;
      }else if(num == 2){
        return address;
      }else{
        return "";
      }
    }


  PeopleData::PeopleData(string fio, string post,string address) {
    this->fio = fio;
    this->post = post;
    this->address = address;

    this->prev = NULL;
    this->next = NULL;
  }

  PeopleData::PeopleData(string data) {
    data += '\n';
    unsigned iter = 0, i = 0;
    string buf = "";
    while (iter < 3) {
      if (data[i] != ';' && data[i] != '\n') {
        buf += data[i];
      } else if (buf != "") {
        switch (iter) {
        case 0:
          this->fio = buf;
          break;
        case 1:
          this->post = buf;
          break;
        case 2:
          this->address = buf;
          break;
        }

        buf = "";
        iter++;
      }
      i++;
      if (data[i - 1] == '\n' && iter < 3) {
        cout << "Введено недостаточное колво данных количество данных\n";
        cout << "Повторите ввод: \n";
        getline(cin, data);
        iter = 0;
        i = 0;
        buf = "";
      }
    }
    this->prev = NULL;
    this->next = NULL;
  }



  PeopleLinkedList::PeopleLinkedList() {
    head = NULL;
    tail = NULL;
  }
  PeopleLinkedList::~PeopleLinkedList() {
    clear();
  }

  PeopleData *PeopleLinkedList::push_front(string fio, string post, string address) {
    PeopleData *ptr = new PeopleData(fio, post, address);
    ptr->next = head;
    if (head != NULL) {
      head->prev = ptr;
    }
    if (tail == NULL) {
      tail = ptr;
    }
    return ptr;
  }

  PeopleData *PeopleLinkedList::push_front(string data) {
    PeopleData *ptr = new PeopleData(data);
    ptr->next = head;
    if (head != NULL) {
      head->prev = ptr;
    }
    if (tail == NULL) {
      tail = ptr;
    }
    return ptr;
  }

  PeopleData *PeopleLinkedList::push_back(string fio, string post, string address) {
    PeopleData *ptr = new PeopleData(fio, post, address);
    ptr->next = head;
    if (head != NULL) {
      head->prev = ptr;
    }
    if (tail == NULL) {
      tail = ptr;
    }
    head = ptr;
    return ptr;
  }

  PeopleData *PeopleLinkedList::push_back(string data) {
    PeopleData *ptr = new PeopleData(data);
    ptr->prev = tail;
    if (tail != NULL) {
      tail->next = ptr;
    }
    if (head == NULL) {
      head = ptr;
    }
    tail = ptr;
    return ptr;
  }

  void PeopleLinkedList::pop_front() {
    if (head == NULL)
      return;
    PeopleData *ptr = head->next;
    if (ptr != NULL)
      ptr->prev = NULL;
    else
      tail = NULL;
    delete head;
    head = ptr;
  }

  void PeopleLinkedList::pop_back() {
    if (tail == NULL)
      return;
    PeopleData *ptr = tail->prev;
    if (ptr != NULL)
      ptr->next = NULL;
    else
      head = NULL;
    delete tail;
    tail = ptr;
  }
  PeopleData *PeopleLinkedList::getAt(unsigned index) {
    PeopleData *ptr = head;
    unsigned i = 0;

    while (i != index) {
      if (ptr == NULL)
        return NULL;
      ptr = ptr->next;
      i++;
    }
    return ptr;
  }

  PeopleData *PeopleLinkedList::insert(unsigned index, string fio, string post, string address) {
    PeopleData *right = getAt(index);
    PeopleData *left = getAt(index - 1);
    if (right == NULL) {
      return push_back(fio, post, address);
    }
    if (left == NULL) {
      return push_front(fio, post, address);
    }

    PeopleData *ptr = new PeopleData(fio, post, address);

    ptr->prev = left;
    ptr->next = right;
    left->next = ptr;
    right->prev = ptr;

    return ptr;
  }

  PeopleData *PeopleLinkedList::insert(unsigned index, string data) {
    PeopleData *right = getAt(index);
    PeopleData *left = getAt(index - 1);
    if (right == NULL) {
      return push_back(data);
    }
    if (left == NULL) {
      return push_front(data);
    }
    PeopleData *ptr = new PeopleData(data);

    ptr->prev = left;
    ptr->next = right;
    left->next = ptr;
    right->prev = ptr;

    return ptr;
  }

  void PeopleLinkedList::earse(unsigned index) {
    PeopleData *ptr = getAt(index);
    if (ptr == NULL)
      return;

    if (ptr->prev == NULL) {
      pop_front();
      return;
    }
    if (ptr->next == NULL) {
      pop_back();
      return;
    }

    PeopleData *right = ptr->next;
    PeopleData *left = ptr->prev;
    right->prev = left;
    left->next = right;
    delete ptr;
  }
  void PeopleLinkedList::clear(){
    while (head != NULL) {
      pop_front();
    }
  }

  int PeopleLinkedList::isExist(int elementnum, string data) {

    PeopleData *ptr = this->head;
    int index = 0;
    string element;
    while (ptr != NULL) {

      if (elementnum != -1) {
        switch (elementnum) {
        case 0:
          element = ptr->fio;
          break;
        case 1:
          element = ptr->post;
          break;
        case 2:
          element = ptr->address;
          break;
        }
      } else {
        if (ptr->fio == data)
          return index;
        if (ptr->post == data)
          return index;
        if (ptr->address == data)
          return index;
      }

      if (element == data)
        return index;
      ptr = ptr->next;
      index++;
    }
    return -1;
  }

  int PeopleLinkedList::isExistData(string data) {
    data += '\n';
    int index = 0;
    PeopleData *ptr = this->head;
    bool exist = true;
    while (ptr != NULL) {
      unsigned iter = 0, i = 0;
      string buf = "";
      while (iter < 5) {
        if (data[i] != ';' && data[i] != '\n') {
          buf += data[i];
        } else if (buf != "") {
          switch (iter) {
          case 0:
            if (buf != ptr->fio)
              exist = false;
            break;    
          case 1:
            if (buf != ptr->post)
              exist = false;
            break;
          case 2:
            if (buf != ptr->address)
              exist = false;
            break;
          }
          cout << buf << '\n';
          buf = "";
          iter++;
        }
        i++;
      }
      if (exist) {
        return true;
      } else {
        ptr = ptr->next;
        index++;
        exist = true;
      }
    }
    return -1;
  }

  int PeopleLinkedList::isExistData(string fio, string post,
                  string address) {
    int index = 0;
    PeopleData *ptr = this->head;
    bool exist = true;
    while (ptr != NULL) {
      if (ptr->fio != fio)
        exist = false;
      if (ptr->post != post)
        exist = false;
      if (ptr->address != address)
        exist = false;
      if (exist) {
        return index;
      } else {
        ptr = ptr->next;
        index++;
        exist = true;
      }
    }
    return -1;
  }

  void PeopleLinkedList::castling(int first, int second) {
    
    if(first == second) return;
    if(first == -1) return;
    if(second == -1) return;
    
    if(first>second){
      int buf = first;
      first = second;
      second = first;
    }
    
    PeopleData *ptr_1 = getAt(first);
    PeopleData *ptr_2 = getAt(second);
    if(tail == ptr_2) tail = ptr_1; 
    if(head == ptr_1) head = ptr_2;
    if(ptr_1 == ptr_2) return;
    if(second == first+1){
      
      PeopleData *ptr_1l = ptr_1->prev;
      PeopleData *ptr_2r = ptr_2->next;
      
      ptr_1->prev = ptr_2;
      ptr_1->next = ptr_2r;

      ptr_2->next = ptr_1;
      ptr_2->prev = ptr_1l;
      
      if(ptr_1l!=NULL) ptr_1l->next = ptr_2;
      if(ptr_2r!=NULL) ptr_2r->prev = ptr_1;
      
    }else{
    PeopleData *ptr_1l = ptr_1->prev;
    PeopleData *ptr_1r = ptr_1->next;
    PeopleData *ptr_2l = ptr_2->prev;
    PeopleData *ptr_2r = ptr_2->next;
      
    ptr_1->next = ptr_2r;
    ptr_1->prev = ptr_2l;

    ptr_2->next = ptr_1r;
    ptr_2->prev = ptr_1l;

    if(ptr_1l!=NULL) ptr_1l->next = ptr_2;
    if(ptr_1r!=NULL) ptr_1r->prev = ptr_2;

    if(ptr_2l!=NULL) ptr_2l->next = ptr_1;
    if(ptr_2r!=NULL) ptr_2r->prev = ptr_1;
    }
  }

  void PeopleLinkedList::sort(int elementnum){
    PeopleData *ptr = this->head;
    int index = 0;
    string element;
    int min_el = 0;
    int i = 0;
    string min = "";
    while (true) {
      if(ptr == NULL){
        castling(index, min_el);
        index++;
        i = index;
        min_el = i;
        min = "";
        ptr = getAt(i);
        if(ptr == NULL){
          return;
        }
      }
      element = ptr->get_data(elementnum);
      if(min == ""){
        min = element;
      }else{
        if(min>element){
          min = element;
          min_el = i;
        }
      }
      i++;
      ptr = ptr->next;
    }
  }

