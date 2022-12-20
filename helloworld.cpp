/* helloworld.cpp */ 

#include <iostream> 
#include "functions.h"

void helloWorld(){

    // std::cout uses the scope operator (the :: operator) to say that we want to use the name "cout" that is defined in the namespace "std":
    std::cout << "Hello World!" 
        << std::endl;
}