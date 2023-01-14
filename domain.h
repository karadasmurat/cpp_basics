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
    int capacity = 0;
    int size = 0;

  public:
    Box() = default;

    // constructor \w member initializer
    Box(int cap);

    ~Box();

    // Although every member must be declared inside its class,
    // we can define a member function’s body either inside or outside of the class body.
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

    // const member function: can't modify object - "const" follows parameter list
    // The purpose of that const is to modify the type of the implicit this pointer.
    // The fact that "this" is a pointer to const means that const member functions cannot change the object on
    // which they are called.

    // can be called for a const object.
    int getCapacity() const
    {
        // We do not need to use the implicit this pointer to access the members of the object on which a member
        // function is executing: this->size;
        return capacity;
    }

    // const member function: can't modify object
    int getSize() const
    {
        // We do not need to use the implicit this pointer to access the members of the object on which a member
        // function is executing: this->size;
        return size;
    }

}; // class Box

// Operator overloading using non-member function:
Box operator-(const Box &left, const Box &right);

// Operator overloading using non-member function:
std::ostream &operator<<(std::ostream &os, const Box &box);

class Entity
{
    std::string e_name = "";
    int e_size = 0;

  public:
    Entity() = default;

    // A default parameter is only used in the declaration.
    Entity(const std::string &n, int s = 1);

    // Copy constructor
    Entity(const Entity &other);

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

// operator overloading using non-member function
bool operator==(const Entity &lhs, const Entity &rhs);

// Operator overloading using non-member function:
std::ostream &operator<<(std::ostream &os, const mk::Entity &e);

} // namespace mk
