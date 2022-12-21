#include <iostream>

#include "functions.h"

using namespace std;

void referenceBasics()
{

    // Type& newname = existing name;

    int x = 10;
    // pointer
    int *xptr = &x;

    // refer an existing variable in another name
    int &xRef = x; // int& yerine int gönderebiliyoruz (as a reference)

    cout << "x: " << x << endl;

    // A pointer needs to be dereferenced with * to access the memory location it
    // points to, whereas a reference can be used directly.
    *xptr += 1;
    cout << "x: " << x << endl;

    x += 2;
    cout << "x: " << x << endl;

    // modify through reference
    xRef += 3;
    cout << "x: " << x << endl;

    int counter(0);
    modifyValue(counter);
    cout << "After a function call with no return: " << counter << endl;

    int min, max;

    // 2 reference parameters, as an alternative to returning 2 values
    min_max(min, max, 333, 11);

    cout << "Min:\t" << min << "\nMax:\t" << max << endl;
}

void modifyValue(int &arg)
{
    arg = 333;
}

// 2 reference parameters, as an alternative to returning 2 values
void min_max(int &min, int &max, int x, int y)
{

    if (x < y)
    {
        min = x;
        max = y;
    }
    else
    {
        min = y;
        max = x;
    }
}