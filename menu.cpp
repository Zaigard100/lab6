#include "classes.h"
#include <fstream>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
PeopleLinkedList lst;

int uint_read(string data) {
  string buf = "";
  bool err = false;
  for (unsigned i = 0; i < data.length(); i++) {
    if (isdigit(data[i])) {
      if (buf == "0") {
        err = true;
        cout << "Недопустимый символ: " << data[i] << '(' << i << ")\n";
      }
    }
  }
  if (err) {
    return -1;
  }
  return stoi(data);
}

int menu() {
  cout << "1. Загрузить из файла.\n"
       << "2. Записать в файл.\n"
       << "3. Заполнить через консоль.\n"
       << "4. Очистить список\n"
       << "5. Добавить элемент в список.\n"
       << "6. Удалить элемент из списка.\n"
       << "7. Сортировать список.\n"
       << "8. Вывести список в консоль.\n"
       << "9. Вывести элемен в консоль.\n"
       << "10.Закрыть программу\n\n"
       << "Введите номер комманды:\n";

  string command;
  getline(cin, command);
  cout << "\n";
  if (command == "1") {

    cout << "Из какого файла читать данные:\n";
    string file, enter;
    getline(cin, file);
    std::ifstream fin(file);
    if (lst.head != NULL) {
      cout << "Список не пуст хотите её отчистить(Y/N):\n";
      while (true) {
        getline(cin, enter);
        if (enter == "Y" || enter == "y") {
          lst.clear();
          cout << "Список очищен.\n";
          break;
        } else if (enter == "N" || enter == "n") {
          cout << "Список будет дополнен.\n";
          break;
        } else {
          cout << "Повторите ввод:\n";
        }
      }
    }
    do {
      getline(fin, enter);
      if (enter != "")
        lst.push_back(enter);
    } while (enter != "");
    fin.close();

  } else if (command == "2") {

    cout << "В какой файл записать данные:\n";
    string file;
    getline(cin, file);
    std::ofstream fout(file);
    PeopleData *ptr = lst.head;
    while (ptr != NULL) {
      fout << ptr->fio << ';' << ptr->post << ';' << ptr->address << ';'
           << '\n';
      ptr = ptr->next;
    }
    fout.close();

  } else if (command == "3") {

    cout << "Вводите данные(Пробел - закончить):\n";
    string enter;
    if (lst.head != NULL) {
      cout << "Список не пуст хотите её отчистить(Y/N):\n";
      while (true) {
        getline(cin, enter);
        if (enter == "Y" || enter == "y") {
          lst.clear();
          cout << "Список очищен.\n";
          break;
        } else if (enter == "N" || enter == "n") {
          cout << "Список будет дополнен.\n";
          break;
        } else {
          cout << "Повторите ввод:\n";
        }
      }
    }
    do {
      getline(cin, enter);
      if (enter != "")
        lst.push_back(enter);
    } while (enter != "");

  } else if (command == "4") {
    cout << "Вы уверены(Y/N):\n";
    string enter;
    while (true) {
      getline(cin, enter);
      if (enter == "Y" || enter == "y") {
        lst.clear();
        cout << "Список очищен.\n";
        break;
      } else if (enter == "N" || enter == "n") {
        break;
      } else {
        cout << "Повторите ввод:\n";
      }
    }
  } else if (command == "5") {

    cout << "Введите номер куда вы хотите добавить данные:\n";
    string enter, data;

    getline(cin, enter);
    int index = uint_read(enter);

    cout << "Введите данные:\n";
    getline(cin, data);

    lst.insert(index, data);

  } else if (command == "6") {

    cout << "Введите номер элемента который вы хотите удалить:\n";
    string enter;
    getline(cin, enter);
    int index = uint_read(enter);

    lst.earse(index);

  } else if (command == "7") {

    cout << "Введите по какому элементу:\n";
    string enter;
    getline(cin, enter);
    int index = uint_read(enter);
    cout << "\n";
    if (index >= 0) {
      lst.sort(index);
      cout << "Список отсортирован.\n";
    }
  } else if (command == "8") {

    PeopleData *ptr = lst.head;

    if (ptr == NULL) {
      cout << "Список пуст.\n";
    }

    while (ptr != NULL) {
      cout << ptr->fio << ", " << ptr->post << ", " << ptr->address << '\n';
      ptr = ptr->next;
    }

  } else if (command == "9") {

    cout << "Введите номер элемента которы вы хотите вывести:\n";
    string enter;
    getline(cin, enter);
    int index = uint_read(enter);
    cout << "\n";
    PeopleData *ptr = lst.getAt(index);
    if (ptr == NULL) {
      cout << "Элемент пуст.\n";
    } else {
      cout << ptr->fio << ", " << ptr->post << ", " << ptr->address << '\n';
    }
  } else if (command == "10") {

    cout << "Вы уверены(Y/N):\n";
    string enter;
    while (true) {
      getline(cin, enter);
      if (enter == "Y" || enter == "y") {
        lst.clear();
        return -1;
        break;
      } else if (enter == "N" || enter == "n") {
        break;
      } else {
        cout << "Повторите ввод:\n";
      }
    }

  } else {
    cout << "Неверная команда\n";
  }
  cout << "\n";

  return 1;
}