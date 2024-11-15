#include "Manager.h"
#include <cstdlib>

int main(int argc, char *argv[]) {
  Manager manager;

  manager.readFile("input.txt");
  manager.display();
  manager.writeFile("output.txt");

  return 0;
}
