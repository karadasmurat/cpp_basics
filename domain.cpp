/*
Classes control object initialization by defining one or more special member functions known as "constructors".
The job of a constructor is to initialize the data members of a class object.
A constructor is run whenever an object of a class type is created.
Constructors have the same name as the class. Unlike other functions, constructors have no return type.
The default constructor is one that takes no arguments. If our class does not explicitly define any constructors, the
compiler will implicitly define the default constructor for us.
If we define any constructors, the class will not have a default constructor unless we define that constructor
ourselves. (The compiler generates a default constructor automatically only if a class declares no constructors.)

The only difference between "struct" and "class" is the default access level.

Encapsulation provides two important advantages:
    • User code cannot inadvertently corrupt the state of an encapsulated object.
    • The implementation of an encapsulated class can change over time without requiring changes in user-level code.

A class can allow another class or function to access its nonpublic members by making that class or function a friend.
Friend declarations may appear only inside a class definition; they may appear anywhere in the class. Friends are not
members of the class and are not affected by the access control of the section in which they are declared.
*/

#include "domain.h"
#include <iostream>

using namespace mk;
using namespace std;

namespace mk
{
// constructor \w member initializer
Box::Box(int cap) : capacity(cap), size(0)
{
    cout << "Construct a Box object\n";
}

Box::~Box()
{
    cout << "Destruct Box object " << endl;
}

// Although every member must be declared inside its class,
// we can define a member function’s body either inside or outside of the class body.
void Box::addItems(int itemCount)
{
    size += itemCount;
}

// Prefix increment operator.
Box &Box::operator++()
{
    ++size;
    return *this;
}

// Postfix increment operator.
// The postfix operator returns a copy of the value before it was incremented!
Box Box::operator++(int)
{
    Box temp = *this;
    ++(*this);   // use prefix increment on this
    return temp; // return the value BEFORE it was incremented.
}

// classic version to add
Box Box::add(const Box &other) const
{
    return Box(capacity + other.getCapacity());
}

/*
OPERATOR OVERLOADING
If an expression of the form "x op y" is encountered, the compiler will check:

  - is there a member function in the class of object x of the form "operator op(Y) where Y is the class of object y,
and, if not,
  - is there a non-member function of the form "operator op(X,Y) where X is the class of object x and Y is the class of
object y.
*/

// operator overloading as member function
// a. classname:: prefixed.
// b. left operand becomes implicit *this object.
Box Box::operator+(const Box &other) const
{
    return Box(capacity + other.getCapacity());
}

/*
Since the std::string class has the move constructor, returning even the long strings by value is efficient. If an
object has a move constructor, it’s said to be characterized with move-semantics. Move-semantics imply that the object
is not copied to a different location on function return, thus, providing faster function execution time.

C++ way of toString() is overriding
std::ostream &operator<<(std::ostream&, const ClassName&);

*/
string Box::toString() const
{
    return "Box{\"capacity\":" + std::to_string(capacity) + ", \"size\":" + std::to_string(size) + "}\n";
}

// operator overloading as a non-member function
// the class to which the member function "should" be added is not available for modification. This frequently occurs
// with classes that are in standard class libraries.
Box operator-(const Box &left, const Box &right)
{
    return Box(left.getCapacity() - right.getCapacity());
}

// To get cout to accept a Box object after the insertion operator, overload the insertion operator to recognize an
// ostream object on the left and a Box on the right. like toString()

// cout is an object of ostream class and cin is an object of istream class  operators must be overloaded as a global
// function - if we want to make them a member method, then they must be made members of ostream and istream classes,
// which is not a good option most of the time. think the parameters like f(this, other)

// Defining Nonmember Class-Related Functions
// The overloaded operator returns a reference to the original ostream object, which means you can combine
// insertions
ostream &operator<<(ostream &os, const Box &box)
{
    return os << box.toString();
    // return os;
}

// DEFINITION into .cpp source file.
// default constructor
// C++11 allows constructors to call other peer constructors ("delegation").
// This allows constructors to utilize another constructor's behavior with a
// minimum of added code.
// Entity::Entity() : Entity("Default")
// {
// }

// A default parameter is only used in the declaration.
Entity::Entity(const string &name, int s) : e_name(name), e_size(s)
{
    cout << "Construct Entity{name:" << e_name << ", size:" << e_size << "}" << endl;
}

// Copy constructor
Entity::Entity(const Entity &other) : e_name(other.e_name), e_size(other.e_size)
{
    cout << "Copy Entity" << endl;
}

Entity::~Entity()
{
    cout << "Destruct Entity: " << e_name << endl;
}

// operator== overloading as a non-member function
// Assume 2 entity instances are equal if their specific data members (e_size) are equal.
bool operator==(const Entity &lhs, const Entity &rhs)
{
    // Guard self assignment
    if (&lhs == &rhs)
        return true;

    return lhs.getSize() == rhs.getSize();
}

ostream &operator<<(ostream &os, const Entity &e)
{
    return os << "Entity{name:" << e.getName() << ", size:" << e.getSize() << "}";
    // return os;
}

} // namespace mk
  /*
  #include <iostream>
  
  namespace mkdomain {
  
      class Vehicle{
  
          int capacity;
  
      public:
  
          // Constructor with an optional parameter and initializer list
          // Also a default constructor then ?!
          Vehicle(int vcapacity = 1): capacity(vcapacity){}
  
          void move() {
              std::cout << "The vehicle is moving by default!" << std::endl;
          }
  
      };
  
      enum class BicycleType{
  
          Mountain, City, Road, Gravel
      };
  
      class Bicycle: public Vehicle{
  
          public:
              BicycleType type;
              int gears;
  
              Bicycle(BicycleType btype, int gears=18, int capacity=1): Vehicle(capacity){
                  type = btype;
              }
  
              void move() {
                  std::cout << "Cycling with a " << int(type) << std::endl;
              }
  
  
      };
  } // namespace
  */