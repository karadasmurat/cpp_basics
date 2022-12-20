/* domain.h */

// #ifndef - #define - #endif
#pragma once
#include <iostream>

using namespace std;

namespace mkdomain {

class Box {

  int capacity;

public:
  // constructor \w member initializer
  Box(int cap);
  // classic version to add
  Box add(const Box &other) const;

  // operator overloading
  Box operator+(const Box &other) const;

  int getCapacity() const { return capacity; }

private:
  // To get cout to accept a Box object after the insertion operator, overload
  // the insertion operator
  //friend ostream &operator<<(ostream &os, const Box &box);

}; // class Box

ostream &operator<<(ostream &os, const Box &box);



class Entity {

  string e_name;
  int e_size;

public:
  // default constructor
  // C++11 allows constructors to call other peer constructors ("delegation").
  // This allows constructors to utilize another constructor's behavior with a
  // minimum of added code.
  Entity();

  // A default parameter is only used in the declaration.
  Entity(const string &n, int s = 1);

  // Destructors are a “prepare to die” member function. It never takes any
  // parameters, and it never returns anything. The most common example is when
  // the constructor uses new, and the destructor uses delete.
  ~Entity();

  // getter
  const string &getName() const { return e_name; }
  int getSize() const { return e_size; }

}; // class Entity



} // namespace mkdomain
