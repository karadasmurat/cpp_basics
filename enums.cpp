#include <iostream>
#include "enums.h"

using namespace std;

/*

An enum (an enumeration) is a very simple user-defined type, specifying its
set of values (its enumerators) as symbolic constants.

What do we use enumerations for? Basically, an enumeration is useful whenever
we need a set of related named integer constants. That happens all the time
when we try to represent sets of alternatives (up, down; yes, no, maybe; on,
off; n, ne, e, se, s, sw, w, nw) or distinctive values (red, blue, green,
yellow, maroon, crimson, black).

The class in "enum class" means that the enumerators are in the scope of the
enumeration. That is, to refer to jan, we have to say Month::jan Month m =
Month::feb; (enum classes are new in C++11)

We don’t say Month.feb because Month isn’t an object (it’s a type) and mar
isn’t a data member (it’s an enumerator — a symbolic constant). Use :: after
the name of a class, enumeration, or namespace and . (dot) after an object
name.

*/

// Operator overloading
// 1. member functions - enum class do not have functions x
// 2. non-member function or friend function
Month operator++(Month &m)
{
    // prefix increment operator
    m = (m == Month::Dec) ? Month::Jan : Month(int(m) + 1);
    return m;
}

void enumBasics()
{

    Day thatDay = Friday;
    printEnum(thatDay);

    Month m = Month::Jan;

    // Unlike an unscoped enumeration, a scoped enumeration is not implicitly
    // convertible to its integer value. You need to explicitly convert it to an
    // integer cout << "Month m: " << m << endl;
    cout << "Month m: " << int(m) << endl;

    ++m; // Operator overloading
    cout << "++m: " << int(m) << endl;

    Size size = XS;
    Day day = Monday;

    // warning! enum-compare different enumeration types
    if (size == day) // true
        cout << "Different enumeration types are equal?" << endl;
}

void printEnum(Day d)
{

    std::cout << d << ": ";

    switch (d)
    {
    case Saturday:
        std::cout << "Saturday\n";
        break;
    case Sunday:
        std::cout << "Sunday\n";
        break;
    default:
        std::cout << "Well, another weekday.\n";
        break;
    }
}