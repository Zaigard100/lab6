#ifndef MYSTRUCTURS_H
#define MYSTRUCTURS_H

#include <string>

using std::string;

struct People {

  struct People *prev;
  struct People *next;

  string surname;
  string middlename;
  string name;
  string post;
  string address;

};

struct People *init(string surname, string middlename, string name, string post,
                    string address) {
  
  struct People *lst;

  lst = (struct People *)malloc(sizeof(struct People));

  lst->surname = surname;
  lst->middlename = middlename;
  lst->name = name;
  lst->post = post;
  lst->address = address;

  lst->next = NULL;
  lst->prev = NULL;
  return (lst);
  
}

struct People *addelem(People *lst, string surname, string middlename,
                       string name, string post, string address) {
  
  struct People *temp, *p;
  temp = (struct People *)malloc(sizeof(People));
  p = lst->next;
  lst->next = temp;

  temp->surname = surname;
  temp->middlename = middlename;
  temp->name = name;
  temp->post = post;
  temp->address = address;

  temp->next = p;
  temp->prev = lst;
  if (p != NULL)
    p->prev = temp;
  return (temp);
  
}

struct People *deletelem(People *lst) {
  
  struct People *prev, *next;
  prev = lst->prev;
  next = lst->next;
  if (prev != NULL)
    prev->next = lst->next;
  if (next != NULL)
    next->prev = lst->prev;
  free(lst);
  return (prev);
  
}

void listprintr(People *lst) {
  
  struct People *p;
  p = lst;
  while (p->next != NULL)
    p = p->next;
  do {
    printf("%s %s %s, %s, %s", p->surname.c_str(), p->middlename.c_str(),
           p->name.c_str(), p->post.c_str(), p->address.c_str());
    p = p->prev;
  } while (p != NULL);
  
}

#endif