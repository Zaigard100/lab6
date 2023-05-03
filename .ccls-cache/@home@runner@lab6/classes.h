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
};