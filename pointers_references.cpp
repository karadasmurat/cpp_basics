#include <assert.h> /* assert */

#include <iostream>
#include <vector>

#include "functions.h"

using namespace std;
using namespace mkdomain;

void checkParams(Box *b) {
  if (!b) cout << "No Box!" << endl;
}

void pointerBasics() {
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

An object that holds an address value is called a pointer. For example, the type
needed to hold the address of an int is called a “pointer to int” or an “int
pointer” and the notation is int*

  If we want to see the value of the object pointed to, we can do that using the
  “contents of” operator “(often called the dereference operator), unary *


  When you start a C++ program, the compiler sets aside memory for your code
  (sometimes called code storage or text storage) and for the global variables
you define (called static storage). It also sets aside some memory to be used
when you call functions, and they need space for their arguments and local
variables (that’s called stack storage or automatic storage). The rest of the
computer’s memory is potentially available for other uses; it is “free”

We request memory to be allocated on the free store by the "new" operator.
The new operator returns a pointer to the object it creates.
If it created several objects (an array), it returns a pointer to the first of
those objects. (A pointer does not know how many elements it points to, the
value is the address of the first byte of the memory.)

     double* p = new double[4];

  This asks the C++ run-time system to allocate four doubles on the free store
  and return a pointer to the first double to us.

  Unlike a reference, a pointer is an object in its own right.
  A pointer variable has its own identity : a distinct, visible memory address
that can be taken with the unary &operator and a certain amount of space that
can be measured with the sizeof operator.

  */

  // Unlike a reference, a pointer need not be initialized at the time it is
  // defined
  int *aPtr;  // uninitialized: likely trouble
  // int& myNewRef; // ERR reference declaration requires initialization

  cout << "Adress: " << aPtr << endl;
  cout << "Garbage value: " << aPtr << endl;

  // *aPtr = 7.0; // dereferencd a pointer without initializing it is asking for
  // trouble.

  // nullptr
  int *nPtr1 = 0;
  int *nPtr2 = NULL;
  int *nPtr3 = nullptr;
  cout << "nPtr1:" << nPtr1 << endl
       << "nPtr2: " << nPtr2 << endl
       << "nPtr3: " << nPtr3 << endl;

  int x = 10;
  int *px = &x;  // 0x...

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

  /* Access through pointers:
    When a pointer points to an object(!), we can use the dereference operator
    (the * operator) to access that object. The “contents of” operator * (also
    called the dereference operator) allows us to read and write the object
    pointed to by a pointer

    Note: We may dereference only a valid pointer that points to an object.

    Advice: Initialize all Pointers. Uninitialized pointers are a common source
    of run-time errors. What happens when we use an uninitialized pointer is
    undefined. Using an uninitialized pointer almost always results in a
    run-time crash. Debugging the resulting crashes can be surprisingly hard -
    There is no way to distinguish a valid address from an invalid one formed
    from the bits that happen to be in the memory in which the pointer was
    allocated. (garbage!) If there is no object to bind to a pointer, then
    initialize the pointer to nullptr or zero. That way, the program can detect
    that the pointer does not point to an object.
*/
  int *notInitializedPtr;
  // *notInitializedPtr = 7.0; // ERR: dereferencing a pointer without
  // initializing it is asking for trouble.

  *ptr += 5;  // a is now 10, When we assign to *ptr we are assigning to the
              // object to which ptr points.

  // Re-assign a pointer
  ptr = &b;
  *ptr = 1;  // b is now 1

  assert(a == 10);
  assert(b == 1);

  int *pi = ptr;
  // double *pd = pi; // ERR: types of pi and pd differ

  /*
  arrays "decay" into pointers.
  The term decay signifies loss of type and dimension; numbers decay into int*
  by losing the dimension. If you're passing an array by value, what you're
  really doing is copying a pointer - a pointer to the array's first element is
  copied to the parameter (whose type should also be a pointer the array
  element's type). This works due to array's decaying nature; once decayed,
  sizeof no longer gives the complete array's size, because it essentially
  becomes a pointer. In addition to using the dereference operator * on a
  pointer, we can use the subscript operator []

*/
  cout << "==== DECAY ====" << endl;

  int arr[5]{11, 22, 33, 44, 55};

  assert(arr == &arr[0]);  // OK
  assert(*arr == arr[0]);  // OK

  cout << "arr \t:" << arr << endl;
  cout << "&arr[0]\t:" << &arr[0] << endl;

  cout << "*arr\t:" << *arr << endl;
  cout << "arr[0]\t:" << arr[0] << endl;

  /*
  The major problem with pointers is that a pointer doesn’t “know” how many
  elements it points to.

  Does pd have a third element pd[2]? Does it have a fifth element pd[4]?
  If we look at the definition of pd, we find that the answers are yes and no,
  respectively. However, the compiler doesn’t know that; it does not keep track
  of pointer values. Our code will simply access memory as if we had allocated
  enough memory. It will even access pd[–3]. We have no idea what the memory
  locations marked pd[–3] and pd[4] are used for. However, we do know that they
  weren’t meant to be used as part of our array of three doubles pointed to by
  pd. Most likely, they are parts of other objects and we just scribbled all
  over those. That’s not a good idea. In fact, it is typically a disastrously
  poor idea: “disastrous” as in “My program crashes mysteriously” or “My program
  gives wrong output.” Out-of-range access is particularly nasty because
  apparently unrelated parts of a program are affected. An out-of-range read
  gives us a “random” value that may depend on some completely unrelated
  computation:
*/
  int *pd = new int[3];  // allocate 3 ints on the free store
  pd[2] = 2;
  pd[4] = 4;    // !
  pd[-3] = -3;  // !

  cout << "pd[-3]: " << pd[-3] << endl;

  // Memory allocated by new is not initialized for built-in types:
  cout << "pd[1]: " << pd[1] << endl;

  // specify an initializer list for an array of objects allocated by new:
  int *ai = new int[3]{10, 20, 30};
  cout << "ai[2]: " << ai[2] << endl;

  /*
  The "new" operator allocates (“gets”) memory from the free store.
  Since a computer’s memory is limited, it is usually a good idea to return
  memory to the free store once we are finished using it. That way, the free
  store can reuse that memory for a new allocation. For large programs and for
  long-running programs such freeing of memory for reuse is essential. The
  operator for returning memory to the free store is called delete.

  There are two forms of delete:
      • delete p frees the memory for an individual object allocated by new.
      • delete[] p frees the memory for an array of objects allocated by new.

  */

  // one of the major reasons for using the free store:
  // we can create objects in a function and pass them back to a caller.
  double *r = createAndPassBack(5);

  // use r
  cout << "received address: " << r << endl;
  cout << "r[4] value: " << r[4] << endl;

  // free memory r
  delete[] r;

  // this is obvious
  int y = incrementV1(x);
  cout << "x: " << x << endl;  // 10

  incrementV2(&x);
  cout << "x: " << x << endl;  // 11

  // “Pass-by-reference" - pass like regular variable:
  // We do not know looking at caller syntax if parameter is int reference or
  // int !! We have to look method signature.
  increment_ref(x);
  cout << "x: " << x << endl;  // 12

  /*
  A null pointer does not point to any object.
  Code can check whether a pointer is null before attempting to use it.
  There are several ways to obtain a null pointer, and the most direct approach
  is to initialize the pointer using the literal nullptr. Alternatively, we can
  initialize a pointer to the literal 0.

  Using an uninitialized pointer is not the same as initializing with nullptr -
  There is no way to distinguish a valid address from an invalid one formed from
  the bits that happen to be in the memory in which the pointer was allocated.
  (garbage!)

  Older programs sometimes use a preprocessor variable named NULL, which the
  cstdlib header defines as 0. When we use a preprocessor variable, the
  preprocessor automatically replaces the variable by its value. Hence,
  initializing a pointer to NULL is equivalent to initializing it to 0.
  */
  int *np1 = nullptr;
  int *np2 = 0;

  checkParams(nullptr);

  pointerToAPointer();

  // Two pointers are equal if they hold the same address and unequal otherwise.

  /*
  The type void* is a special pointer type that can hold the address of any
  object. Like any other pointer, a void* pointer holds an address, but the type
  of the object at that address is unknown. We can pass it to or return it from
  a function
  */
}

/*
A pointer is an object in memory, so like any object it has an address.
Therefore, we can store the address of a pointer in another pointer.
*/
void pointerToAPointer() {
  int ival = 1024;
  int *pi = &ival;  // pi points to an int (1 kere sekerek objeye gidersin)
  int **ppi = &pi;  // ppi points to a pointer to an int (2 kere sekerek objeye
                    // gidersin)

  cout << "The value of ival\n==================\n"
       << "direct value: " << ival << "\n"
       << "indirect value: " << *pi << "\n"
       << "doubly indirect value: " << **ppi << endl;
}

int incrementV1(int arg) { return ++arg; }

void incrementV2(int *arg) {
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
void increment_ref(int &arg) {
  // no need to dereference
  arg++;
}

double *createAndPassBack(int size) {
  // the caller is responsible for the memory allocated for res
  double *res = new double[size];
  for (int i = 0; i < size; i++) {
    res[i] = 10 * i;
  }

  cout << "returning address: " << res << endl;

  return res;
}

/*
You rent a hotel room. You put a book in the top drawer of the bedside table and
go to sleep. You check out the next morning, but "forget" to give back your key.
You steal the key!

A week later, you return to the hotel, do not check in, sneak into your old room
with your stolen key, and look in the drawer. Your book is still there.
Astonishing!

 If no one else checks in after you, and you go back to your room illegally, all
your stuff is guaranteed to still be there in this particular hotel.

In this situation anything can happen. The book can be there -- you got lucky.
*/
int *returnTheAddressOfALocal() {
  int a = 5;
  return &a;  // address of stack memory associated with local variable
              // returned!!
}

/*
A function that accepts another function as an input.

A function pointer is a variable that stores the address of a function that can
later be called through that function pointer.

A use for function pointers is setting up "listener" or "callback" functions
that are invoked when a particular event happens. The function is called, and
this notifies your code that something of interest has taken place. One example
is when you're writing code for a graphical user interface (GUI). Most of the
time, the user will interact with a loop that allows the mouse pointer to move
and that redraws the interface. Sometimes, however, the user will click on a
button or enter text into a field. These operations are "events" that may
require a response that your program needs to handle. How can your code know
what's happening? Using Callback functions! The user's click should cause the
interface to call a function that you wrote to handle the event.

Function Pointer Syntax
The key to writing the declaration for a function pointer is that you're just
writing out the declaration of a function but with (*func_name) where you'd
normally just put func_name. For example:

    f is a pointer to a function taking one integer argument, and returns void:

    void (*f)(int);

Invoke the function pointed to just as if you were calling a function.

    f(n);

Function pointers provide a way of passing around instructions for how to do
something. You can write flexible functions and libraries that allow the
programmer to choose behavior by passing function pointers as arguments

*/

void loopAndCallBack(vector<int> &v, void (*f)(int)) {
  for (int n : v) {
    // execute callback - with related parameters!
    f(n);
  }
}

void functionPointerBasics() {
  vector<int> nums{1, 2, 3, 4, 5};
  loopAndCallBack(nums, simplePrint);
}

void referenceBasics() {
  // Type& newname = existing name;

  int x = 10;
  // pointer
  int *xptr = &x;

  // reference
  int &xRef = x;  // int& yerine int gönderebiliyoruz (as a reference)
  int &xRef2 =
      *xptr;  // & is part of the declaration; * is the dereference operator

  // Because references are not objects, they don’t have addresses, &xRef
  // returns the address of the referenced object:
  cout << "x      : " << x << endl;
  cout << "xRef   : " << xRef << endl;
  cout << "xRef2  : " << xRef2 << endl;
  cout << "&x     : " << &x << endl;
  cout << "&xRef  : " << &xRef << endl;
  cout << "&xRef2 : " << &xRef2 << endl;
  cout << "xptr   : " << xptr << endl;

  /*
    Ordinarily, when we initialize a variable, the value of the initializer is
    copied into the object we are creating. When we define a reference, instead
    of copying the initializer’s value, we bind the reference to its
    initializer. Once initialized, a reference remains bound to its initial
    object.  There is no way to rebind a reference to refer to a different
    object. Because there is no way to rebind a reference, references must be
    initialized.

        int& refVal2; //ERR:
        int& refVal3 = 10; //ERR: initializer must be an object

    A reference is not an object. Instead, a reference is just another name for
    an already existing object. After a reference has been defined, all
    operations on that reference are actually operations on the object to which
    the reference is bound
  */

  // A pointer needs to be dereferenced  (*) to access the memory location it
  // points to, whereas a reference can be used directly.
  *xptr += 1;
  simplePrint("Modified through pointer", x);

  x += 2;
  simplePrint("x", x);

  // modify through reference, like a regular variable name!
  xRef += 3;
  simplePrint("Modified through reference", x);

  // call like regular variable: we do not know looking at caller syntax if
  // parameter is int reference or int !! We have to look method signature.
  increment_ref(x);
  simplePrint("Modified through a function arg (ref)", x);

  // Using 2 reference parameters, as an alternative to returning 2 values
  int o_min, o_max;
  min_max(o_min, o_max, 333, 11);
  cout << "Min:\t" << o_min << "\nMax:\t" << o_max << endl;
}

void modifyValue(int &arg) { arg = 333; }

// 2 reference parameters, as an alternative to returning 2 values
void min_max(int &min, int &max, int x, int y) {
  if (x < y) {
    min = x;
    max = y;
  } else {
    min = y;
    max = x;
  }
}