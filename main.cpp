/*
$ g++ -std=c++20 main.cpp helloworld.cpp domain.cpp -o main && ./main

preprocessing output
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
2. compiler     : Takes pre-processed source file and compiles into
object-files.
3. linker       : Takes object files, links them into an executable program.

*/

/*

To allow programs to be written in logical parts, C++ supports what is commonly
known as separate compilation. Separate compilation lets us split our programs
into several files, each of which can be compiled independently.

To support separate compilation, C++ distinguishes between declarations and
definitions. A declaration makes a name known to the program. A file that wants
to use a name defined elsewhere includes a declaration for that name. A
definition creates the associated entity.

Since #include s logically happen before anything else a compiler does, handling
#includes is part of what is called "preprocessing" Including a header file
produces the same results as copying the header file into each source file that
needs it. Such copying would be time-consuming and error-prone. With a header
file, the related declarations appear in only one place. If they need to be
changed, they can be changed in one place, and programs that include the header
file will automatically use the new version when next recompiled.

In C, the usual convention is to give header files names that end with .h
*/

#include "domain.h"
#include "enums.h"
#include "functions.h"
#include "mk_datastructures.h"
#include <iostream>
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

using namespace std;
using namespace mkdomain;

// using declaration for a single identifier:
// using std::cin;
// using std::cout;

/*
    A "type alias" is a name that is a synonym for another type.
    Type aliases let us simplify complicated type definitions, making those
   types easier to use.

    Traditionally, we use a typedef. The new standard introduced a second way to
   define a type alias, via an alias declaration: using identifier = type;

        // C++11
        using counter = long;

        // C++03 equivalent:
        typedef long counter;

*/

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
        return "B{x:" + to_string(x) + "}\n";
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
    int *array; // pointer to an array of 10 integers

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
    double area();
    double perimeter();

    void info()
    {
        cout << "This is Shape2D\n";
    }

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
    void info()
    {
        cout << "This is Circle\n";
    }

    // we have a virtual function in the base class and it is being overridden in
    // the derived class
    void draw() override
    {
        cout << "Drawing a Circle" << endl;
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
    // constBasics();

    // inputBasics();

    // cout << "getBiggerOfTwo(44, 55): " << getBiggerOfTwo(44, 55) << endl;

    // cout << "getMax(33, 55, 44): " << getMax(33, 55, 44) << endl;

    // pointerBasics();
    // referenceBasics();
    // classBasics();
    // inheritanceBasics();

    // enumBasics();

    // destructionBasics();

    // functionPointerBasics();

    // templateFunctions();

    // const int N = 9;
    // int searchBase[N] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    // int found = binarySearch(searchBase, N, 10);

    heapBasics();

    return 0;
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
    cout << "Box: " << box1.getSize() << " / " << box1.getCapacity() << endl;

    const Box box2(100); // const object

    // box2.addItems(2); // ERR member function is not const
    box2.getCapacity(); // OK, const
    cout << box2;

    // operator overloading, member function
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
}

void inheritanceBasics()
{

    Shape2D s1;
    s1.info();

    Circle c1;
    c1.info();
    c1.draw();
    // c1.area(); // undefined reference!

    // Runtime polymorphism is achieved only through a pointer (or reference) of
    // base class type. A base class pointer can point to the objects of base
    // class as well as to the objects of derived class:
    Shape2D *sPtr = &c1;
    sPtr->info(); // shape, non-virtual
    sPtr->draw(); // circle, virtual

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
