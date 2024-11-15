#include "Contact.h"
#include <iostream>
#include <string>

Contact::Contact(std::string name, int phone, std::string email) {
  this->name = name;
  this->phone = phone;
  this->email = email;
}
Contact::~Contact() {}

void Contact::display() {
  std::cout << "\t" << this->returnRepresentation() << std::endl;
}

std::string Contact::returnRepresentation() {
  return this->name + " " + std::to_string(this->phone) + " " + this->email;
}
