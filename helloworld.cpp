/* helloworld.cpp */

#include "functions.h"
#include <iostream>

void helloWorld() {

  // std::cout uses the scope operator (the :: operator) to say that we want to
  // use the name "cout" that is defined in the namespace "std":
  std::cout << "Hello World!" << std::endl;
}