#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

class PeopleData {
public:
  string lastname;
  string name;
  string patronymic;
  string post;
  string address;

  PeopleData *prev, *next;

public:
  PeopleData(string lastname, string name, string patronymic, string post,
             string address) {
    this->lastname = lastname;
    this->name = name;
    this->patronymic = patronymic;
    this->post = post;
    this->address = address;

    this->prev = NULL;
    this->next = NULL;
  }
  PeopleData(string data) {
    data += '\n';
    unsigned iter = 0, i = 0;
    string buf = "";
    while (iter < 5) {
      if (data[i] != ';' && data[i] != '\n') {
        buf += data[i];
      } else if (buf != "") {
        switch (iter) {
        case 0:
          this->lastname = buf;
          break;
        case 1:
          this->name = buf;
          break;
        case 2:
          this->patronymic = buf;
          break;
        case 3:
          this->post = buf;
          break;
        case 4:
          this->address = buf;
          break;
        }

        buf = "";
        iter++;
      }
      i++;
      if (data[i - 1] == '\n' && iter < 5) {
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
};
class PeopleLinkedList {
public:
  PeopleData *head, *tail;

public:
  PeopleLinkedList() {
    head = NULL;
    tail = NULL;
  }
  ~PeopleLinkedList() {
    while (head != NULL) {
      pop_front();
    }
  }
  // PUSH FRONT
  PeopleData *push_front(string lastname, string name, string patronymic,
                         string post, string address) {
    PeopleData *ptr = new PeopleData(lastname, name, patronymic, post, address);
    ptr->next = head;
    if (head != NULL) {
      head->prev = ptr;
    }
    if (tail == NULL) {
      tail = ptr;
    }
    return ptr;
  }

  PeopleData *push_front(string data) {
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
  // PUSH BACK
  PeopleData *push_back(string lastname, string name, string patronymic,
                        string post, string address) {
    PeopleData *ptr = new PeopleData(lastname, name, patronymic, post, address);
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

  PeopleData *push_back(string data) {
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
  // POP
  void pop_front() {
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

  void pop_back() {
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
  // GET
  PeopleData *getAt(unsigned index) {
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

  PeopleData *operator[](unsigned index) { return getAt(index); }
  // SET
  PeopleData *insert(unsigned index, string lastname, string name,
                     string patronymic, string post, string address) {
    PeopleData *right = getAt(index);
    PeopleData *left = getAt(index - 1);
    if (right == NULL) {
      return push_back(lastname, name, patronymic, post, address);
    }
    if (left == NULL) {
      return push_front(lastname, name, patronymic, post, address);
    }

    PeopleData *ptr = new PeopleData(lastname, name, patronymic, post, address);

    ptr->prev = left;
    ptr->next = right;
    left->next = ptr;
    right->prev = ptr;

    return ptr;
  }

  PeopleData *insert(unsigned index, string data) {
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
  // DEL
  void earse(unsigned index) {
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

  int isExist(int elementnum, string data) {

    PeopleData *ptr = this->head;
    int index = 0;
    string element;
    while (ptr != NULL) {

      if (elementnum != -1) {
        switch (elementnum) {
        case 0:
          element = ptr->lastname;
          break;
        case 1:
          element = ptr->name;
          break;
        case 2:
          element = ptr->patronymic;
          break;
        case 3:
          element = ptr->post;
          break;
        case 4:
          element = ptr->address;
          break;
        }
      } else {
        if (ptr->lastname == data)
          return index;
        if (ptr->name == data)
          return index;
        if (ptr->patronymic == data)
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

  int isExistData(string data) {
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
            if (buf != ptr->lastname)
              exist = false;
            break;
          case 1:
            if (buf != ptr->name)
              exist = false;
            break;
          case 2:
            if (buf != ptr->patronymic)
              exist = false;
            break;
          case 3:
            if (buf != ptr->post)
              exist = false;
            break;
          case 4:
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

  int isExistData(string lastname, string name, string patronymic, string post,
                  string address) {
    int index = 0;
    PeopleData *ptr = this->head;
    bool exist = true;
    while (ptr != NULL) {
      if (ptr->lastname != lastname)
        exist = false;
      if (ptr->name != name)
        exist = false;
      if (ptr->patronymic != patronymic)
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

  void castling(int first, int second) {
    
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
    if(second == first+1){
      
      PeopleData *ptr_1l = ptr_1->prev;
      PeopleData *ptr_2r = ptr_2->next;
      
      ptr_1->prev = ptr_2;
      ptr_1->next = ptr_2r;

      ptr_2->next = ptr_1;
      ptr_2->prev = ptr_1l;
      
      ptr_1l->next = ptr_2;
      ptr_2r->prev = ptr_1;
      
    }else{
    PeopleData *ptr_1l = ptr_1->prev;
    PeopleData *ptr_1r = ptr_1->next;
    PeopleData *ptr_2l = ptr_2->prev;
    PeopleData *ptr_2r = ptr_2->next;
      
    ptr_1->next = ptr_2r;
    ptr_1->prev = ptr_2l;

    ptr_2->next = ptr_1r;
    ptr_2->prev = ptr_1l;

    ptr_1l->next = ptr_2;
    ptr_1r->prev = ptr_2;

    ptr_2l->next = ptr_1;
    ptr_2r->prev = ptr_1;
    }
    cout << "\n";
    
    
  }
};