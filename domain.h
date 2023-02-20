/* domain.h */

// #ifndef - #define - #endif
#pragma once
#include <cmath>
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

class Shape2D
{

  public:
    double perimeter();

    void info()
    {
        std::cout << "This is Shape2D\n";
    }

    /*
    Member functions that are not declared as "virtual" are resolved at compile time, not run time.
    The base class defines virtual functions that it expects its derived classes to override. A base class specifies
    that a member function should be dynamically bound by preceding its declaration with the keyword "virtual" .
    Derived classes frequently, but not always, override the virtual functions that they inherit. If a derived class
    does not override a virtual from its base, then, like any other member, the derived class inherits the version
    defined in its base class.
    */
    virtual void draw()
    {
        std::cout << "Drawing a shape" << std::endl;
    }

    // An abstract class contains at least one pure virtual function. You declare a pure virtual function by using a
    // pure specifier(= 0) in the declaration of a virtual member function in the class declaration.
    virtual double area() = 0;
};

class Rectangle : public Shape2D
{
    double width, height;
};

class Circle : public Shape2D
{
    double radius;

  public:
    Circle(double r) : radius(r)
    {
    }

    void info()
    {
        std::cout << "This is Circle with radius: " << radius << "\n";
    }

    // A function that is declared as virtual in the base class is implicitly virtual in the derived classes as well.
    // The new standard lets a derived class explicitly note that it intends a member function to override a virtual
    // that it inherits. It does so by specifying override after the parameter list

    void draw() override
    {
        std::cout << "Drawing a Circle" << std::endl;
    }

    // override pure virtual function of the base.
    double area() override
    {
        double a = radius * radius * M_PI;
        std::cout << "Area: " << a << std::endl;
        return a;
    }
};

class NoCopy
{
    /*
    Declare the copy constructor and the copy assignment deleted
    The effect is to eliminate the otherwise default copy operations

            NoCopy nc1;
            NoCopy nc2;
            NoCopy nc3{nc1};    // ERR copy constructor deleted.
            NoCopy nc4 = nc1;   // ERR copy constructor deleted.
            nc2 = nc1;          // ERR copy assignment operator is deleted.
    */
  public:
    NoCopy() = default;

    /*
    Copy Constructor
    Initialization of objects of a class is done by a constructor. So, we need a constructor that copies.
    Unsurprisingly, such a constructor is called a copy constructor. It is defined to take as its argument a reference
    to the object from which to copy.
    */
    NoCopy(NoCopy &other) = delete; // prevent copying

    /*
    Copy assignments
    We handle copy construction (initialization), but we can also copy by assignment.
    As with copy initialization, the default meaning of copy assignment is memberwise copy.
    */
    NoCopy &operator=(const NoCopy &other) = delete; // prevent copying
};

// simple test class
struct X
{
    int val;

    void info(const std::string &s, int nv)
    {
        std::cout << this << "–>" << s << ": " << val << " (" << nv << ")\n";
    }

    // default constructor
    X() : val{0}
    {
        info("X()", val);
    }

    X(int v) : val{v}
    {
        info("X(int)", val);
    }

    // copy constructor
    X(const X &other) : val{other.val}
    {
        info("X(X&) ", val);
    }

    // copy assignment
    X &operator=(const X &other)
    {
        // do the copy
        val = other.val;

        info("X::operator=()", val);

        // return the existing object so we can chain this operator
        return *this;
    }

    // destructor
    ~X()
    {
        info("~X()", 0);
    }
};

} // namespace mk
