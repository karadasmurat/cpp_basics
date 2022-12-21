#include <iostream>
#include <assert.h> /* assert */
#include "functions.h"

using namespace std;

void pointerBasics()
{
    /*

  For data type T,
    T*
  is the data type for a pointer to an object of type T.

  For object x of type T,
    &x
  is an expression that yiels the address of x, as T*


    A computer’s memory is a sequence of bytes. We can number the bytes from 0 to
    the last one. We call such “a number that indicates a location in memory” an
    address. You can think of an address as a kind of integer value. The first
    byte of memory has the address 0, the next the address 1, and so on.

    Everything we put in memory has an address. For example:

      int var = 17;

  will set aside an “int-size” piece of memory for var somewhere and put the
    value 17 into that memory. But where exactly? - The “address of” operator,
    unary &, is used to get the address of an object.

    int* ptr = &var; 

  An object that holds an address value is called a pointer. For example, the type needed to hold the address of an int is called a “pointer to int” or an “int pointer” and the notation is int*

    If we want to see the value of the object pointed to, we can do that using the
    “contents of” operator “(often called the dereference operator), unary *


    When you start a C++ program, the compiler sets aside memory for your code
    (sometimes called code storage or text storage) and for the global variables you define (called static storage). It also sets aside some memory to be used when you call functions, and they need space for their arguments and local variables (that’s called stack storage or automatic storage). The rest of the computer’s memory is potentially available for other uses; it is “free”

  We request memory to be allocated on the free store by the "new" operator. The new operator returns a pointer to the object it creates. If it created several objects (an array), it returns a pointer to the first of those objects. (A pointer does not know how many elements it points to, the value is the address of the first byte of the memory.)

       double* p = new double[4];

    This asks the C++ run-time system to allocate four doubles on the free store
    and return a pointer to the first double to us.

    */

    // A pointer variable has its own identity: a distinct, visible memory address that can be taken with the unary & operator and a certain amount of space that can be measured with the sizeof operator.
    int *aPtr; // uninitialized: likely trouble
               // *aPtr = 7.0; // declaring without initializing it is asking for
               // trouble.

    int x = 10;
    int *px = &x; // 0x...

    cout << "x\t: " << x << endl;
    cout << "Adress of x (&x): " << &x << endl;
    cout << "Adress of pointer (&px): " << &px << endl;
    cout << "Pointer to value (*px): " << *px << endl;

    // new operator returns a pointer
    int *p2 = new int{5};

    int a = 5;
    int b = 6;
    int *ptr;
    ptr = &a;

    // Access through pointers:
    // The “contents of” operator * (also called the dereference operator) allows us to read and write the object pointed to by a pointer
    *ptr += 5; // a is now 10

    // Re-assign a pointer
    ptr = &b;
    *ptr = 1; // b is now 1

    assert(a == 10);
    assert(b == 1);

    // In addition to using the dereference operator * on a pointer, we can use the subscript operator [ ]

    /* The major problem with pointers is that a pointer doesn’t “know” how many elements it points to.

  “Does pd have a third element pd[2]? Does it have a fifth element pd[4]? If we look at the definition of pd, we find that the answers are yes and no, respectively. However, the compiler doesn’t know that; it does not keep track of pointer values. Our code will simply access memory as if we had allocated enough memory. It will even access pd[–3]. We have no idea what the memory locations marked pd[–3] and pd[4] are used for. However, we do know that they weren’t meant to be used as part of our array of three doubles pointed to by pd. Most likely, they are parts of other objects and we just scribbled all over those. That’s not a good idea. In fact, it is typically a disastrously poor idea: “disastrous” as in “My program crashes mysteriously” or “My program gives wrong output.”

  Out-of-range access is particularly nasty because apparently unrelated parts of a program are affected. An out-of-range read gives us a “random” value that may depend on some completely unrelated computation:
  */
    int *pd = new int[3]; // allocate 3 ints on the free store
    pd[2] = 2;
    pd[4] = 4;   // !
    pd[-3] = -3; // !

    cout << "pd[-3]: " << pd[-3] << endl;

    // Memory allocated by new is not initialized for built-in types:
    cout << "pd[1]: " << pd[1] << endl;

    // specify an initializer list for an array of objects allocated by new:
    int *ai = new int[3]{10, 20, 30};
    cout << "ai[2]: " << ai[2] << endl;

    /*
    The "new" operator allocates (“gets”) memory from the free store. Since a
    computer’s memory is limited, it is usually a good idea to return memory to
    the free store once we are finished using it. That way, the free store can
    reuse that memory for a new allocation. For large programs and for
    long-running programs such freeing of memory for reuse is essential. The
    operator for returning memory to the free store is called delete.

    There are two forms of delete:
        • delete p frees the memory for an individual object allocated by new.
        • delete[] p frees the memory for an array of objects allocated by new.

    */
    // one of the major reasons for using the free store: we can create objects in
    // a function and pass them back to a caller.

    double *r = createAndPassBack(5);

    // use r
    cout << "received address: " << r << endl;
    cout << "r[4] value: " << r[4] << endl;

    // free memory r
    delete[] r;

    // this is obvious
    int y = incrementV1(x);
    cout << "x: " << x << endl; // 10

    incrementV2(&x);
    cout << "x: " << x << endl; // 11

    incrementV3(x);
    cout << "x: " << x << endl; // 12
}

int incrementV1(int arg) { return ++arg; }

void incrementV2(int *arg)
{
    // dereferencing a pointer to modify the value of the variable pointed by this
    // pointer
    (*arg)++;
}

// “Pass-by-reference"
// (let the function refer back to the variable passed - If you want to change
// the value of the object passed, you must use a non-const reference
// Pass-by-reference is clearly a very powerful mechanism: we can have a
// function operate directly on any object to which we pass a reference.

// Our rule of thumb is:
// 1. Use pass-by-value to pass very small objects.
// 2. Use pass-by-const-reference to pass large objects that you don’t need to
// modify.
// 3. Return a result rather than modifying an object through a reference
// argument.
// 4. Use pass-by-reference only when you have to. (If we see an argument passed
// by non-const reference, we must assume that the called function will modify
// that argument.)
void incrementV3(int &arg)
{
    // no need to dereference
    arg++;
}

double *createAndPassBack(int size)
{

    // the caller is responsible for the memory allocated for res
    double *res = new double[size];
    for (int i = 0; i < size; i++)
    {
        res[i] = 10 * i;
    }

    cout << "returning address: " << res << endl;

    return res;
}

/*
You rent a hotel room. You put a book in the top drawer of the bedside table and go to sleep. You check out the next morning, but "forget" to give back your key. You steal the key!

A week later, you return to the hotel, do not check in, sneak into your old room with your stolen key, and look in the drawer. Your book is still there. Astonishing!

 If no one else checks in after you, and you go back to your room illegally, all your stuff is guaranteed to still be there in this particular hotel.

In this situation anything can happen. The book can be there -- you got lucky.
*/
int *returnTheAddressOfALocal()
{
    int a = 5;
    return &a; // address of stack memory associated with local variable returned!!
}