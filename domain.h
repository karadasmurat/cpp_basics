/* domain.h */

// #ifndef - #define - #endif
#pragma once
#include <iostream>

using namespace std;

namespace mkdomain
{

    class Box
    {

        int capacity;
        int size;

    public:
        // constructor \w member initializer
        Box(int cap);

        void addItems(int itemCount);

        // classic version to add
        Box add(const Box &other) const;

        // operator overloading as member function
        // left operand becomes implicit *this object.
        Box operator+(const Box &other) const;

        string toString() const;

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

    private:
        // To get cout to accept a Box object after the insertion operator, overload
        // the insertion operator
        // friend ostream &operator<<(ostream &os, const Box &box);

    }; // class Box

    // Operator overloading using non-member function:
    Box operator-(const Box &left, const Box &right);

    // Operator overloading using non-member function:
    ostream &operator<<(ostream &os, const Box &box);

    class Entity
    {

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
