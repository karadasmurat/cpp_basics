/*
$ g++ -std=c++20 main.cpp helloworld.cpp domain.cpp references.cpp basics.cpp pointers.cpp -o main && ./main

Format code on VSCode: Command Palette > Format Document With > C/C++
Shortcut: Alt Shift F
*/

#include <iostream>
#include "functions.h"
#include "domain.h"
#include "enums.h"

using namespace std;
using namespace mkdomain;

void classBasics();
void inheritanceBasics();
void referenceBasics();

class A
{

public:
    int id;
};

class B
{

public:
    int id;

    B()
    {
        cout << "Hello world, this is B!" << endl;
    }
};

int main()
{

    // cout << "Hello, there!" << endl;
    helloWorld();

    // variableBasics();

    // inputBasics();

    // cout << "getBiggerOfTwo(44, 55): " << getBiggerOfTwo(44, 55) << endl;

    // cout << "getMax(33, 55, 44): " << getMax(33, 55, 44) << endl;

    // pointerBasics();
    // referenceBasics();
    classBasics();
    // inheritanceBasics();

    enumBasics();

    return 0;
}

void classBasics()
{

    A a01;      // Class A does not have any explicit constructors, default is executed.
    a01.id = 1; // public

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

    // Vehicle vehicle1;   // Constructor with one optional parameter
    // vehicle1.move();

    // // Create object of the Bicycle class
    // Bicycle bicycle1 = Bicycle(BicycleType::City);

    // // Calling members of the base class
    // bicycle1.move();
}
