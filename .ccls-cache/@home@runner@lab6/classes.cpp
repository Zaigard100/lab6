#include <string>

using std::string;

class PeopleList {

public:
  PeopleList() { count = 0; }

  

  struct People {
    unsigned long key;
    struct People *prev;
    struct People *next;

    string surname;
    string middlename;
    string name;
    string post;
    string address;
  };

  struct Edges {
    struct People *node;
  };

  Edges *head;
  Edges *last;

  void add(string surname, string middlename, string name, string post,
           string address, bool last = true) {
    if (count == 0) {
      struct People *p;
      p = (struct People *)malloc(sizeof(People));
      
      p->surname = surname;
      p->middlename = middlename;
      p->name = name;
      p->post = post;
      p->address = address;
      
      head->node = p;
      last->node = p;
    }
    
  }

private:
  unsigned int count;
};