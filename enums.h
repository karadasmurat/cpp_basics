#pragma once

/*
An enum (an enumeration) is a very simple user-defined type, specifying its set of values (its enumerators) as symbolic constants.

What do we use enumerations for? Basically, an enumeration is useful whenever we need A SET OF RELATED NAMED constants.
That happens all the time when we try to represent sets of alternatives (up, down; yes, no, maybe; on, off; n, ne, e, se, s, sw, w, nw)
or distinctive values (red, blue, green, yellow, maroon, crimson, black).

    // Unscoped enumeration
    Day d = Friday; 

The class in enum class means that the enumerators are in the scope of the enumeration. (Scoped enumeration)
That is, to refer to jan, we have to say Month::jan

    // Scoped enumeration
    Month m = Month::Feb;

(enum classes are new in C++11)

We don’t say Month.Feb (dot) because Month isn’t an object (it’s a type) and Feb isn’t a data member (it’s an enumerator — a symbolic constant).
Use :: after the name of a class, enumeration, or namespace and . (dot) after an object name.

How to store in a db?
If you store them by their int value, then you must be careful editing your enumeration later on in your project.
If somehow the integer values for the enumeration elements get redefined, all your data will be corrupted. But it will be the fastest/smallest datatype to use.
*/

// Scoped enumeration
enum class Month
{

    // You can give a specific representation value for an enumerator, as we did
    // for jan here, or leave it to the compiler to pick a suitable value. If you
    // leave it to the compiler to pick, it’ll give each enumerator the value of
    // the previous enumerator plus one. If we don’t initialize the first
    // enumerator, the count starts with 0”

    Jan = 1,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec

};

// Unscoped enumeration
// Day d = Friday;   // OK:  in scope
// Day d2 = Day::Friday;  // also OK

enum Day
{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

enum Size
{
    XS,
    S,
    M,
    L,
    XL,
    XXL
};

// altitude may be altitude::high or altitude::low
enum class Rank : char
{
    High = 'H',
    Low = 'L', // trailing comma only allowed after CWG 518
};

void printEnum(Day d);
