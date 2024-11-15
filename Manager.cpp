#include "Manager.h"
#include "Contact.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>

Manager::Manager() {
  contactListLength = 0;
  contactListCapacity = 2;
  contactList = new Contact *[contactListCapacity];
}
Manager::~Manager() {
  for (int i = 0; i < contactListLength; i++) {
    delete contactList[i];
  }

  delete[] contactList;
}

void Manager::display() {
  if (this->contactListLength == 0) {
    std::cout << "Nothing to display yet, contact list is empty" << std::endl;
  } else {
    std::cout << "Contact List with total of " << contactListLength
              << " element(s)" << std::endl;
    for (int i = 0; i < contactListLength; i++) {
      contactList[i]->display();
    }
  }
}

void Manager::addContact(Contact *contact) {
  if (contactListLength >= contactListCapacity) {
    resize();
  }
  contactList[contactListLength] = contact;
  contactListLength += 1;
}
void Manager::addContact(std::string name, int phone, std::string email) {
  addContact(new Contact(name, phone, email));
}

void Manager::resize() {
  contactListCapacity *= 2;
  Contact **newContactList = new Contact *[contactListCapacity];

  for (int i = 0; i < contactListLength; i++) {
    newContactList[i] = contactList[i];
  }

  delete[] contactList;
  contactList = newContactList;
}

void Manager::readFile(std::string inputfilename) {
  std::string line;

  std::ifstream file(inputfilename);
  if (!file.is_open()) {
    std::cerr << "Failed to open file " << inputfilename << " and read from it"
              << std::endl;
  }

  while (std::getline(file, line)) {
    std::stringstream ss(line); // for splitting the line
    std::string name, email;
    int phone;

    ss >> name >> phone >> email;
    this->addContact(name, phone, email);
  }

  file.close();
}

void Manager::writeFile(std::string filename) {
	std::ofstream file(filename);
  for (int i = 0; i < contactListLength; i++) {
    file << contactList[i]->returnRepresentation() << std::endl;
  }

  file.close();

}
