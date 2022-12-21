#pragma once

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

// altitude may be altitude::high or altitude::low
enum class Rank : char
{
    High = 'h',
    Low = 'l', // trailing comma only allowed after CWG 518
};

void printEnum(Day d);