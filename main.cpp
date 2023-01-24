/*
$ g++ -std=c++20 main.cpp helloworld.cpp domain.cpp -o main && ./main

to see preprocessing output:
$ clang -E helloworld.cpp -o helloworld.i

The Clang Compiler is an open-source compiler for the C family of programming
languages $ clang++ -std=c++20 *.cpp -o main && ./main

VSCode Run:
Ctrl Fn F5

GCC
The GNU Compiler Collection includes front ends for C, C++, Objective-C,
Fortran, Ada, Go, and D, as well as libraries for these languages
(libstdc++,...). GCC was originally written as the compiler for the GNU
operating system.

Mingw-w64
An advancement of the original mingw.org project, created to support the GCC
compiler on Windows systems.

Format code on VSCode: Command Palette > Format Document With > C/C++
Shortcut: Alt Shift F

The compilation process
1. pre-processor: Takes source code and produce pre-processed source file.
2. compiler     : Takes pre-processed source file and compiles into object-files.
3. linker       : Takes object files, links them into an executable program.


To allow programs to be written in logical parts, C++ supports what is commonly known as separate compilation. Separate
compilation lets us split our programs into several files, each of which can be compiled independently.

To support separate compilation, C++ distinguishes between declarations and definitions. A declaration makes a name
known to the program. A file that wants to use a name defined elsewhere includes a declaration for that name. A
definition creates the associated entity.

Preprocessor Directives
Since #include s logically happen before anything else a compiler does, handling #includes is part of what is called
"preprocessing" Including a header file produces the same results as copying the header file into each source file that
needs it. Such copying would be time-consuming and error-prone. With a header file, the related declarations appear in
only one place. If they need to be changed, they can be changed in one place, and programs that include the header file
will automatically use the new version when next recompiled.

In C, the usual convention is to give header files names that end with .h


Tokens
    * Identifiers: names of an entity in the C++ language. An identifier must start with a letter or an underscore, and
      it can have zero or more letters, digits, or underscores.
    * Literals are constant values of different types.
    * Symbols: C++ uses nonalphabetic symbols as operators and punctuation: [ ] ( ) { } * & -> << >> + ++ = == ! ...


*/

#include "domain.h" // no semicolon after any include directive.
#include "enums.h"
#include "exercises.h"
#include "functions.h"
#include "mk_datastructures.h"
#include "patterns.h"
#include <iostream>
#include <math.h>
#include <vector>

/*
A macro is a fragment of code which has been given a name. Whenever the name is
used, it is replaced by the contents of the macro. There are two kinds of
macros: Object-like macros resemble data objects when used, most commonly used
to give symbolic names to numeric constants.

#define BUFFER_SIZE 1024

Function-like macros resemble function calls.

#define LOG(msg) \
    std::cout << msg << std::endl

By convention, macro names are written in uppercase.

Conditional Uses

The conditional preprocessing block
    starts with #if, #ifdef or #ifndef directive,
    then optionally includes any number of #elif, #elifdef, or #elifndef (since
C++23) directives, then optionally includes at most one #else directive and is
terminated with #endif directive.

There are three general reasons to use a conditional.

 1. A program may need to use different code depending on the machine or
operating system it is to run on. In some cases the code for one operating
system may be erroneous on another operating system; for example, it might refer
to data types or constants that do not exist on the other system. When this
happens, it is not enough to avoid executing the invalid code. Its mere presence
will cause the compiler to reject the program. With a preprocessing conditional,
the offending code can be effectively excised from the program when it is not
valid.
 2. You may want to be able to compile the same source file into two different
programs. One version might make frequent time-consuming consistency checks on
its intermediate data, or print the values of those data for debugging, and the
other not.
 3. A conditional whose condition is always false is one way to exclude code
from the program but keep it as a sort of comment for future reference.
*/

#define LETSGO 1
#define DLEVEL 4

#if DLEVEL > 5
#define SIGNAL 1
#elif DLEVEL > 3
// helloWorld();
#else
#define STACK 200
#endif /* expression */

#ifdef MACRO
controlled text
#endif /* MACRO */

#define LOG(msg) std::cout << msg << std::endl

    // using directive for "all the identifiers" in the namespace
    ;

// using namespace std;
using namespace mk;

// using declaration for a single identifier:
using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
    A "type alias" is a name that is a synonym for another type.
    Type aliases let us simplify complicated type definitions, making those
   types easier to use.

    Traditionally, we use a typedef. The new standard introduced a second way to
   define a type alias, via an alias declaration: using identifier = type;
   */

// C++11
// using counter = long;

// C++03 equivalent:
// typedef long counter;

void macroBasics();
void classBasics();
void inheritanceBasics();
void referenceBasics();

/*
A namespace is a declarative region that provides a scope to the identifiers
(the names of types, functions, variables, etc) inside it. Namespaces are used
to organize code into logical groups and to prevent name collisions that can
occur especially when your code base includes multiple libraries.

All identifiers at namespace scope are visible to one another without
qualification. Identifiers outside the namespace can access the members by using
the fully qualified name for each identifier, (std::string str;) or else by a
using Declaration for a single identifier (using std::string), or a using
Directive for all the identifiers in the namespace (using namespace std;).

Code in header files should always use the fully qualified namespace name.
*/
namespace mk
{
int ns_var1{111};
int ns_var2{222};
}; // namespace mk

class A
{

  public:
    int id;
};

class B
{

    int x;

  public:
    B(int x = 1) : x(x)
    {
        cout << "Construct B!" << endl;
    }
    /*
    copy constructor
    classname (const classname&)
    The copy constructor is called whenever an object is initialized from another
    object of the same type.

    initialization:
        T a = b; or T a(b);, where b is of type T

    function argument passing: f(a)
    */
    B(const B &other) : x(other.x)
    {
        cout << "Copy B!" << endl;
    }

    string toString()
    {
        return "B{x:" + std::to_string(x) + "}\n";
    }
};

class NoCopy
{

  public:
    NoCopy()
    {
    }
    NoCopy(NoCopy &other) = delete;
};

class ResourceOnHeap
{
  private:
    int *array; // pointer to an array

  public:
    ResourceOnHeap()
    {
        // allocate the array on the heap
        array = new int[10];
        std::cout << "Construct a ResourceOnHeap object\n";
    }

    // Destructors are used to release any resources allocated by the object.
    // The most common example is when the constructor uses new, and the
    // destructor uses delete.
    ~ResourceOnHeap()
    {
        // free the resources by deleting the array
        delete[] array;
        std::cout << "Destruct a ResourceOnHeap object\n";
    }
};

class Shape2D
{

  public:
    // An abstract class contains at least one pure virtual function. You declare a pure virtual function by using a
    // pure specifier(= 0) in the declaration of a virtual member function in the class declaration.
    virtual double area() = 0;
    double perimeter();

    void info()
    {
        cout << "This is Shape2D\n";
    }

    // The base class defines as virtual those functions it expects its derived classes to override.
    // A base class specifies that a member function should be dynamically bound
    // by preceding its declaration with the keyword "virtual"
    // Member functions that are not declared as virtual are resolved at compile time, not run time.
    // Derived classes frequently, but not always, override the virtual functions that they inherit.
    // If a derived class does not override a virtual from its base, then, like any other member,
    // the derived class inherits the version defined in its base class.

    virtual void draw()
    {
        cout << "Drawing a shape" << endl;
    }
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
        cout << "This is Circle with radius: " << radius << "\n";
    }

    // A function that is declared as virtual in the base class is implicitly virtual in the derived classes as well.
    // The new standard lets a derived class explicitly note that it intends a member function to override a virtual
    // that it inherits. It does so by specifying override after the parameter list

    void draw() override
    {
        cout << "Drawing a Circle" << endl;
    }

    // override pure virtual function of the base.
    double area() override
    {
        double a = radius * radius * M_PI;
        cout << "Area: " << a << endl;
        return a;
    }
};

/*
In C++, an abstract class is a class that cannot be instantiated on its own, but
can be used as a base class for derived classes.

An abstract class contains at least one pure virtual function. You declare a
pure virtual function by using a pure specifier (= 0) in the declaration of a
virtual member function in the class declaration.

You can't declare an object of an abstract class. You can, however, declare
pointers and references to an abstract class.
*/
class AbstractBase
{

  public:
    void concreteMethod()
    {
        cout << "AbstractBase.concreteMethod()" << endl;
    }

    void noBodyMethod();

    // virtual function
    virtual void virtualFunc()
    {
        cout << "AbstractBase.virtualFunc()" << endl;
    }

    // pure virtual function
    virtual void pureVirtualFunc() = 0;
};

class Derived : public AbstractBase
{

  public:
    // MUST implement pure virtual function
    void pureVirtualFunc()
    {
        cout << "Derived.pureVirtualFunc()" << endl;
    }
};

void doNothing(B b);

/*
Every program in C++ has one function, always named main, that is always called
when your program first executes.

The return value from main() is passed to “the system” that invoked the program.
Some systems (such as Unix) often use that value, whereas others (such as
Windows) typically ignore it. A zero indicates successful completion and a
nonzero return value from main() indicates some sort of failure.
*/
int main()
{
    // cout << "Hello, there!" << endl;
    helloWorld();

    // identifier at namespace
    // simplePrint(mk::ns_var1);

    // macroBasics();

    // variableBasics();
    // stringBasics();
    // arrayBasics();
    // vectorBasics();
    // constBasics();

    // switchBasics(16);
    // loopBasics();

    // defaultArguments();

    // inputBasics();

    // cout << "getBiggerOfTwo(44, 55): " << getBiggerOfTwo(44, 55) << endl;

    // cout << "getMax(33, 55, 44): " << getMax(33, 55, 44) << endl;

    // pointerBasics();
    // dynamicMemory();
    // referenceBasics();
    // classBasics();
    // inheritanceBasics();

    // enumBasics();

    // destructionBasics();

    // functionPointerBasics();
    // lambdaBasics();

    // templateFunctions();

    // searchBasics();

    // heapBasics();
    // stackBasics();

    // exceptionBasics();

    // fileBasics();

    // mapBasics();
    // iteratorBasics();

    // memento();

    // ====== exercises =========
    try
    {
        factorial(-5L);
    }
    catch (std::invalid_argument e)
    {
        std::cout << e.what() << endl;
    }
    assert(factorial(5) == 120L);
    assert(factorial(0) == 1L);

    // exercise1(6);
    // exercise2(10);
    // exercise3(123);
    // exercise4(1);

    // assert(absolute(-1) == 1); // OK
    // assert(absolute(0) == 0);  // OK
    // assert(absolute(1) == 1);  // OK

    // assert(earnings(10.0) == 100.0); // OK
    // assert(earnings(40.0) == 400.0); // OK
    // assert(earnings(50.0) == 530.0); // OK

    // assert(getBiggerOfTwo(-1, 1) == 1);
    // assert(getBiggerOfTwo(-5, -1) == -1);
    // assert(getBiggerOfTwo(5, 1) == 5);

    // assert(getScore(50.0, 80.0, 70.0) == 65);

    // assert(totalPrice(1, 10) == 10);
    // assert(totalPrice(50, 10) == 475);
    // assert(totalPrice(100, 10) == 900);

    return EXIT_SUCCESS; // #define	EXIT_SUCCESS 0
}

// will copy b object !
void doNothing(B b)
{
}

void macroBasics()
{
    LOG("Hello, function like macro!");

#ifdef SIGNAL
    std::cout << "SIGNAL: yes\n";
#else
    std::cout << "SIGNAL: no\n";
#endif

// Abort the compilation process if the macro name LETSGO is not defined
#ifndef LETSGO
#error Houston, we have a problem!
#endif

#if (DLEVEL > 0)
    std::cout << "DLEVEL: positive\n";
#endif
}

/*
In C++ we use classes to define our own data types.
By defining types that mirror concepts in the problems we are trying to solve,
we can make our programs easier to write, debug, and modify.

“The fundamental ideas behind classes are data abstraction and encapsulation.
Data abstraction is a programming (and design) technique that relies on the separation of interface and implementation.

The interface of a class consists of the operations that users of the class can execute. The implementation includes the
class’ data members, the bodies of the functions that constitute the interface, and any functions needed to define the
class that are not intended for general use.


A well-designed class has an interface that is intuitive and easy to use and
has an implementation that is efficient enough for its intended use.


*/
void classBasics()
{

    A a01;      // Class A does not have any explicit constructors, default is
                // executed.
    a01.id = 1; // public

    B b1(10);
    B b2 = b1;
    B b3(b1);
    cout << b2.toString();
    cout << b3.toString();

    cout << "Before doNothing()\n";
    doNothing(b3); // Copy B!!
    cout << "After doNothing()\n";

    NoCopy nc1;
    // NoCopy nc2 = nc1; // ERR
    // NoCopy nc2(nc1);  // ERR

    B b01; // Class B defines a no parameter constructor, it is executed.

    Box box1(10);
    box1.addItems(2);
    box1.addItems(3);
    cout << box1.toString() << endl;

    const Box box2(100); // const object

    // box2.addItems(2); // ERR member function is not const
    box2.getCapacity(); // OK, const
    cout << box2;

    // operator overloading, member function
    cout << "Prefix and Postfix Increment Operator\n";
    cout << box1.toString();     // size:5
    cout << (box1++).toString(); // size:5 - postfix returns the value before increment
    cout << (++box1).toString(); // size:7

    // mkdomain::Box::operator+
    Box box3 = box2 + box1;
    cout << "box2 + box1: " << box3;

    // operator overloading, member function
    // mkdomain::operator-
    Box box4 = box2 - box1;
    cout << "box2 - box1: " << box4;

    Entity *ePtr;

    {             // scope
        Entity e; // default constructor!

        cout << "e.name: " << e.getName() << endl; // "Default"

        Entity e2("ENTITY_2");
        ePtr = &e2;

        Entity e3 = Entity("ENTITY_3");
    }
    // stack - when out of scope, auto destroyed
    // "Destruct Entity object" here, out of scope (x3)

    // ERR. use of undeclared identifier e
    // cout << "e.name: " << e.getName() << endl;

    cout << "ePtr->getSize(): " << ePtr->getSize() << endl; // TODO why print ENTITY_2 here?

    int *result = returnTheAddressOfALocal();
    cout << *result << endl;

    Entity ent1("E1", 1);
    Entity ent2("E2", 2);
    Entity ent3("E11", 1);

    if (ent1 == ent2)
        cout << ent1 << " is equal to " << ent2 << endl;
    else
        cout << ent1 << " is NOT equal to " << ent2 << endl;

    if (ent1 == ent3)
        cout << ent1 << " is equal to " << ent3 << endl;
    else
        cout << ent1 << " is NOT equal to " << ent3 << endl;
}

void inheritanceBasics()
{
    // You can't declare an object of an abstract class.
    // Shape2D s1;
    // s1.info();

    Circle c1(10);
    c1.info();
    c1.draw();
    c1.area();

    // Runtime polymorphism is achieved only through a pointer (or reference) of
    // base class type. A base class pointer can point to the objects of base
    // class as well as to the objects of derived class:

    cout << "Calling methods through a pointer to a base class, which is assigned a circle address\n";
    Shape2D *sPtr = &c1;
    sPtr->info(); // "This is Shape2D"  - non-virtual
    sPtr->draw(); // "Drawing a Circle" - virtual

    cout << "Calling methods through a reference to a base class, which is assigned a circle\n";
    Shape2D &sRef = c1;
    sRef.info(); // shape, not virtual
    sRef.draw(); // circle, virtual

    // You can't declare an object of an abstract class.
    // You can, however, declare pointers and references to an abstract class.
    // AbstractBase ab; // ERR
    Derived d;
    AbstractBase &abRef = d;

    // not implemented in derived
    abRef.virtualFunc();

    // not implemented in derived, therefore undefined reference err.
    // abRef.noBodyMethod(); // ERR

    // implemented (must) in derived
    abRef.pureVirtualFunc();

    // Vehicle vehicle1;   // Constructor with one optional parameter
    // vehicle1.move();

    // // Create object of the Bicycle class
    // Bicycle bicycle1 = Bicycle(BicycleType::City);

    // // Calling members of the base class
    // bicycle1.move();
}

void destructionBasics()
{

    ResourceOnHeap r;
}
