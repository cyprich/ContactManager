#pragma once
#include <string>

class Contact {
private:
  std::string name;
  int phone;
  std::string email;

public:
  Contact(std::string name, int phone, std::string email);
  ~Contact();
  std::string getName() { return this->name; }
  int getPhone() { return this->phone; }
  std::string getEmail() { return this->email; }
  void display();
  std::string returnRepresentation();
};
