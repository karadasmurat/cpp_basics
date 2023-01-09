/* domain.h */

// #ifndef - #define - #endif
#pragma once
#include <iostream>

// using namespace std;
// using std::ostream;
// using std::string;

namespace mk
{

class Box
{
    int capacity;
    int size;

  public:
    // constructor \w member initializer
    Box(int cap);

    void addItems(int itemCount);

    // Declare prefix and postfix increment operators (as member function)
    // To distinguish between the two, the postfix form accepts an extra argument of type int.
    Box &operator++();   // Prefix increment operator.
    Box operator++(int); // Postfix increment operator.

    // classic version to add
    Box add(const Box &other) const;

    // operator overloading (as member function)
    // left operand becomes implicit *this object.
    Box operator+(const Box &other) const;

    std::string toString() const;

    // const member: can't modify object
    // "const" after argument list
    // can be called for a const object.
    int getCapacity() const
    {
        return capacity;
    }

    // const member: can't modify object
    int getSize() const
    {
        return size;
    }

}; // class Box

// Operator overloading using non-member function:
Box operator-(const Box &left, const Box &right);

// Operator overloading using non-member function:
std::ostream &operator<<(std::ostream &os, const Box &box);

class Entity
{
    std::string e_name;
    int e_size;

  public:
    Entity();

    // A default parameter is only used in the declaration.
    Entity(const std::string &n, int s = 1);

    // Destructors are a “prepare to die” member function. It never takes any
    // parameters, and it never returns anything. The most common example is when
    // the constructor uses new, and the destructor uses delete.
    ~Entity();

    // getter
    const std::string &getName() const
    {
        return e_name;
    }
    int getSize() const
    {
        return e_size;
    }

}; // class Entity

} // namespace mk
