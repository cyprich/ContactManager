#pragma once
#include "Contact.h"
#include <string>

class Manager {
private:
  Contact **contactList;
  int contactListLength;
  int contactListCapacity;
  void resize();

public:
  Manager();
  ~Manager();
  void display();
  void addContact(Contact *contact);
  void addContact(std::string name, int phone, std::string email);
  void readFile(std::string filename);
  void writeFile(std::string filename);
};
