/*

  For data type T,
    T*
  is the data type for a pointer to an object of type T.

  For "object x" of type T,
    &x
  is an expression that yiels the address of x, as T*


  A computer’s memory is a sequence of bytes. We can number the bytes from 0 to the last one. We call such “a number
that indicates a location in memory” an address. You can think of an address as a kind of integer value. The first byte
of memory has the address 0, the next the address 1, and so on.

  Everything we put in memory has an address. For example:

      int var = 17;

will set aside an “int-size” piece of memory for var somewhere and put the value 17 into that memory. But where exactly?
- The “address of” operator, unary &, is used to get the address of an object.

    int* ptr = &var; 

A variable that holds an address value is called a pointer. For example, the type needed to hold the address of an int
is called a “pointer to int” or an “int pointer” and the notation is int*

If we want to see the value of the object pointed to, we can do that using the “contents of” operator “(often called the
dereference operator), unary *

Note that ptr stores a memory address location, whereas *ptr refers to the value stored in that address.

The type void* means “pointer to some memory that the compiler doesn’t know the type of.” We use void* when we want to
transmit an address between pieces of code that really don’t know each other’s types. A pointer to any object type can
be assigned to a void*. For example:

    void* pv1 = new int;        // OK: int* converts to void*
    void* pv2 = new double[10]; // OK: double* converts to void*

A static_cast can be used to explicitly convert between related pointer types, such as void* and double*

    int* pi = static_cast<int*>(pv1); // OK: explicit conversion



Pointers and references
You can think of a reference as an automatically dereferenced immutable pointer or as an alternative name for an object.
Pointers and references differ in these ways:
    • Assignment to a pointer changes the pointer’s value (not the pointed-to value).
    • To get a pointer you generally need to use new or &.
    • To access an object pointed to by a pointer you use * or [ ].
    • Assignment to a reference changes the value of the object referred to (not the reference itself).
    • You cannot make a reference refer to a different object after initialization.
    • Assignment of references does deep copy (assigns to the referred-to object); assignment of pointers does not
(assigns to the pointer object itself).
    • Beware of null pointers.


Copy terminology
The basic issue is whether you copy a pointer (or reference) or copy the information pointed to (referred to):

    • Shallow copy copies only a pointer so that the two pointers now refer to the same object. That’s what pointers and
references do.

    // int n = 7; int* p = &n;
    int* p = new int{7};
    int* q = p; // copy the pointer p


        name    * -- p -- *  * -- q -- *         -- heap ---
                |         |  |         |        |           |
        val     |  0x100  |  |  0x100  |        |     7     |
                * ------- *  * ------- *         -----------
        addr    0x300       0x200              0x100


                 * ---- *
                 |  p   |
                 * ---- *     - - - - >          ------------
                                                |     7      |
                 * ---- *     - - - - >          ------------
                 |  q   |
                 * ---- *

    • Deep copy copies what a pointer points to so that the two pointers now refer to distinct objects. That’s what
vectors, strings, etc. do. We defi ne copy constructors and copy assignments when we want deep copy for objects of our
classes.


Pointers, references, and inheritance
A derived class, such as Circle, could be used where an object of its public base class Shape was required.
    void rotate(Shape* s, int n); // rotate *s n degrees
    Shape* p = new Circle{Point{100,100},40};
    Circle c {Point{200,200},50};


Dynamic Memory
When you start a C++ program, the compiler sets aside memory for your code (sometimes called code storage or text
storage) and for the global variables you define (called static storage). It also sets aside some memory to be used when
you call functions, and they need space for their arguments and local variables (that’s called stack storage or
automatic storage). The rest of the computer’s memory is potentially available for other uses; it is “free”

We request memory to be allocated on the free store by the "new" operator. The new operator returns a pointer to the
object it creates. If it created several objects (an array), it returns a pointer to the first of those objects. (A
pointer does not know how many elements it points to, the value is the address of the first byte of the memory.)

       double* p = new double[4];

This asks the C++ run-time system to allocate four doubles on the free store and return a pointer to the first double to
us.

Unlike a reference, a pointer is an object in its own right. A pointer variable has its own identity : a distinct,
visible memory address that can be taken with the unary &operator and a certain amount of space that can be measured
with the sizeof operator.


There are three common problems with using new and delete to manage dynamic memory:

    1. Forgetting to delete memory. Neglecting to delete dynamic memory is known as a “memory leak”, because the memory
is never returned to the free store. Testing for memory leaks is difficult because they usually cannot be detected until
the application is run for a long enough time to actually exhaust memory.

    2. Deleting the same memory twice. This error can happen when two pointers address the same dynamically allocated
object. If delete is applied to one of the pointers, then the object’s memory is returned to the free store.

    3. Using an object after it has been deleted. This error can sometimes be detected by making the pointer null after
the delete.

You can avoid all of these problems by using smart pointers exclusively.

Classes that allocate resources—and that do not define destructors to free those resources—can be subject to the same
kind of errors that arise when we use dynamic memory.

When we delete a pointer, that pointer becomes invalid. Although the pointer is invalid, on many machines the pointer
continues to hold the address of the (freed) dynamic memory. After the delete, the pointer becomes what is referred to
as a dangling pointer. A dangling pointer is one that refers to memory that once held an object but no longer does so.
Dangling pointers have all the problems of uninitialized pointers.

Dynamically allocated objects have a lifetime that is independent of where they are created; they exist until they are
explicitly freed.

*/

#include <assert.h> /* assert */

#include <iostream>
#include <vector>

#include "functions.h"

using namespace std;
using namespace mk;

/*
Destructors
One of the most common problems with the free store is that people forget to delete.

The basic idea is to have the compiler know about a function that does the opposite of a constructor. Such a
function is called a destructor. In the same way that a constructor is implicitly called when an object of a
class is created, a destructor is implicitly called when an object goes out of scope. A constructor makes sure
that an object is properly created and initialized. Conversely, a destructor makes sure that an object is
properly cleaned up before it is destroyed.

Destructors are conceptually simple but are the foundation for many of the most effective C++ programming
techniques. The basic idea is simple:

        • Whatever resources a class object needs to function, it acquires in a constructor.
        • During the object’s lifetime it may release resources and acquire new ones.
        • At the end of the object’s lifetime, the destructor releases all resources still owned by the object.
*/
class SimpleContainer
{
    int size;         // the size
    double *elements; // a pointer to the elements

  public:
    // Space for the elements is allocated using new in the constructor, and the pointer returned from the free store is
    // stored in the member pointer elements.
    SimpleContainer(int s) : size{s}, elements{new double[s]}
    {
        // initialize elements
        for (int i = 0; i < s; ++i)
            elements[i] = 0.0;
    }

    // destructor
    ~SimpleContainer()
    {
        delete[] elements; // free memory
    }

    int getSize() const
    {
        return size;
    } // the current size
      // . . .
};

void checkParams(Box *b)
{
    if (!b)
        cout << "No Box!" << endl;
}

void pointerBasics()
{

    // Pointers must be declared before they can be used, just like a normal variable.
    // Unlike a reference, a pointer need not be initialized at the time it is defined
    int *aPtr; // uninitialized: likely trouble
    // int& myNewRef; // ERR reference declaration requires initialization

    cout << "Adress: " << aPtr << endl;
    cout << "Garbage value: " << aPtr << endl;

    // *aPtr = 7.0; // dereferencd a pointer without initializing it is asking for
    // trouble.

    int x = 10;

    // Initializing a pointer via the Address-Of Operator (&)
    // The “address of” operator, unary &, is used to get the address of an object.
    int *px = &x; // 0x...

    cout << "x\t: " << x << endl;
    cout << "Adress of x (&x): " << &x << endl;
    cout << "Adress of pointer (&px): " << &px << endl;
    cout << "Pointer to value (*px): " << *px << endl;

    int a = 5;
    int b = 6;
    int *iptr;
    iptr = &a;

    /*
    Access through pointers:
    When a pointer points to an object(!), we can use the dereference operator (the * operator) to access that
    object. The “contents of” operator * (also called the dereference operator) allows us to read and write the
    object pointed to by a pointer

    Note: We may dereference only a valid pointer that points to an object.

    Advice: Initialize all Pointers. Uninitialized pointers are a common source of run-time errors. What happens
    when we use an uninitialized pointer is undefined. Using an uninitialized pointer almost always results in a
    run-time crash. Debugging the resulting crashes can be surprisingly hard - There is no way to distinguish a
    valid address from an invalid one formed from the bits that happen to be in the memory in which the pointer was
    allocated. (garbage!) If there is no object to bind to a pointer, then initialize the pointer to nullptr or
    zero. That way, the program can detect that the pointer does not point to an object.
    */
    int *notInitializedPtr;
    // *notInitializedPtr = 7.0; // ERR: dereferencing a pointer without
    // initializing it is asking for trouble.

    // If we want to see the value of the object pointed to, we can do that using the “contents of” operator “(often
    // called the dereference operator), unary *
    *iptr += 5; // a is now 10, When we assign to *ptr we are assigning to the object to which ptr points.

    iptr = &b; // Re-assign a pointer
    *iptr = 1; // b is now 1

    assert(a == 10);
    assert(b == 1);

    int *pi = iptr; // Re-assign a pointer

    void *pv01 = new int;                 // OK: int* converts to void*
    void *pv02 = new double[10];          // OK: double* converts to void*
    int *pi01 = static_cast<int *>(pv01); // OK: explicit conversion

    // A pointer can only hold an address of the declared type; it cannot hold an address of a different type.
    // double *pd = iptr; // ERR: types of iptr and pd differ

    /*
    arrays "decay" into pointers.
    The term decay signifies loss of type and dimension; numbers decay into int* by losing the dimension. If you're
    passing an array by value, what you're really doing is copying a pointer - a pointer to the array's first
    element is copied to the parameter (whose type should also be a pointer the array element's type). This works
    due to array's decaying nature; once decayed, sizeof no longer gives the complete array's size, because it
    essentially becomes a pointer. In addition to using the dereference operator * on a pointer, we can use the
    subscript operator []
    */
    cout << "==== DECAY ====" << endl;

    int arr[5]{11, 22, 33, 44, 55};

    assert(arr == &arr[0]); // OK
    assert(*arr == arr[0]); // OK

    cout << "arr \t:" << arr << endl;
    cout << "&arr[0]\t:" << &arr[0] << endl;

    cout << "*arr\t:" << *arr << endl;
    cout << "arr[0]\t:" << arr[0] << endl;

    /*
    The major problem with pointers is that a pointer doesn’t “know” how many elements it points to.

    Does pd have a third element pd[2]? Does it have a fifth element pd[4]? If we look at the definition of pd, we
    find that the answers are yes and no, respectively. However, the compiler doesn’t know that; it does not keep
    track of pointer values. Our code will simply access memory as if we had allocated enough memory. It will even
    access pd[–3]. We have no idea what the memory locations marked pd[–3] and pd[4] are used for. However, we do
    know that they weren’t meant to be used as part of our array of three doubles pointed to by pd. Most likely,
    they are parts of other objects and we just scribbled all over those. That’s not a good idea. In fact, it is
    typically a disastrously poor idea: “disastrous” as in “My program crashes mysteriously” or “My program gives
    wrong output.” Out-of-range access is particularly nasty because apparently unrelated parts of a program are
    affected. An out-of-range read gives us a “random” value that may depend on some completely unrelated
    computation:
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

    // this is obvious
    int y = increment(x);
    cout << "x: " << x << endl; // 10

    increment_ptr(&x);
    cout << "x: " << x << endl; // 11

    // “Pass-by-reference" - pass like regular variable:
    // We do not know looking at caller syntax if parameter is int reference or
    // int !! We have to look method signature.
    increment_ref(x);
    cout << "x: " << x << endl; // 12

    /*
    A null pointer does not point to any object.
    Code can check whether a pointer is null before attempting to use it. There are several ways to obtain a null
    pointer, and the most direct approach is to initialize the pointer using the literal nullptr. Alternatively, we
    can initialize a pointer to the literal 0.

    Using an uninitialized pointer is not the same as initializing with nullptr - There is no way to distinguish a
    valid address from an invalid one formed from the bits that happen to be in the memory in which the pointer was
    allocated. (garbage!)

    Older programs sometimes use a preprocessor variable named NULL, which the cstdlib header defines as 0. When we
    use a preprocessor variable, the preprocessor automatically replaces the variable by its value. Hence,
    initializing a pointer to NULL is equivalent to initializing it to 0.
    */

    int *nPtr1 = 0;
    int *nPtr2 = NULL; // define NULL 0
    int *nPtr3 = nullptr;
    cout << "nPtr1:" << nPtr1 << endl << "nPtr2: " << nPtr2 << endl << "nPtr3: " << nPtr3 << endl;

    // Dereferencing a null pointer causes exception
    // cout << "*nPtr1:" << *nPtr1 << endl << "*nPtr2: " << *nPtr2 << endl << "*nPtr3: " << *nPtr3 << endl;

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

void dynamicMemory()
{

    /*
    In C++, dynamic memory is managed through a pair of operators:

        A. new, which allocates, and optionally initializes, an object in dynamic memory and returns a pointer to
    that object (Objects allocated on the free store are unnamed, so new offers no way to name the objects that it
    allocates. Instead, new returns a pointer to the object it allocates)

    We request memory to be allocated on the free store by the new operator. The new operator can allocate
    individual elements or sequences (arrays) of elements.
        - The new operator returns a pointer to the allocated memory.
        - A pointer value is the address of the first byte of the memory.
        - A pointer points to an object of a specified type.
        - A pointer does not know how many elements it points to.

        B. delete, which takes a pointer to a dynamic object, destroys that object, and frees the associated memory.
    The "new" operator allocates (“gets”) memory from the free store. Since a computer’s memory is limited, it is
    usually a good idea to return memory to the free store once we are finished using it. That way, the free store
    can reuse that memory for a new allocation. For large programs and for long-running programs such freeing of
    memory for reuse is essential. The operator for returning memory to the free store is called delete.

    There are two forms of delete:
        • delete p frees the memory for an individual object allocated by new.
        • delete[] p frees the memory for an array of objects allocated by new.





    */

    // default initialized; *pi1 is “undefined”
    int *pi1 = new int;

    // For class types (such as string) that define their own constructors …
    string *ps = new string; // point to empty string

    // We can initialize a dynamically allocated object using direct initialization, traditional construction (using
    // parentheses), and under the new standard, list initialization (with curly braces):

    int *pi2 = new int(1024);
    int *pi3 = new int{5};
    int *pi4(new int(42));         // p points to dynamic mem
    Entity *pe(new Entity("PE1")); // copy initialize a pointer like an object: T* ptr( new X() )
    simplePrint<Entity>(pe);
    vector<int> *pv = new vector<int>{0, 1, 2, 3, 4, 5};

    // We ask new to allocate an array of objects by specifying the number of objects to allocate in a pair of
    // square brackets after a type name. block of ten uninitialized ints
    int *pia = new int[10]; // vs. new int(10) !

    // block of ten ints value initialized to 0
    int *pia2 = new int[10]();

    // block of ten empty strings
    string *psa = new string[10];

    // block of ten empty strings
    string *psa2 = new string[10]();

    // block of five ints each initialized from the corresponding initializer
    int *pia3 = new int[5]{0, 1, 2, 3, 4};

    // block of ten strings; the first four are initialized from the given initializers and remaining elements are
    // value initialized
    string *psa3 = new string[10]{"a", "an", "the", string(3, 'x')};

    // free memory
    // The standard form of operator delete[] will take only one parameter.
    delete[] pia;
    delete[] pia2;
    delete[] pia3;
    delete[] psa;
    delete[] psa2;
    delete[] psa3;

    // one of the major reasons for using the free store:
    // we can create objects in a function and pass them back to a caller.
    double *r = createAndPassBack(5);

    // use r
    cout << "received address: " << r << endl;
    cout << "r[4] value: " << r[4] << endl;

    // free memory r
    delete[] r;
}

void smartPointers()
{

    /*
    Properly freeing dynamic objects turns out to be a surprisingly rich source of bugs. To make using dynamic
    memory easier (and safer), the new library provides two smart pointer types that manage dynamic objects. A smart
    pointer acts like a regular pointer with the important exception that it automatically deletes the object to
    which it points. We use a smart pointer in ways that are similar to using a pointer. Dereferencing a smart
    pointer returns the object to which the pointer points.

    When we use a smart pointer, the smart pointer class ensures that memory is freed when it is no longer needed
    even if the block is exited prematurely. In contrast, memory that we manage directly is not automatically freed
    when an exception occurs. If an exception happens between the new and the delete, and is not caught, then this
    memory may never be freed.

    Smart pointers are templates. Therefore, when we create a smart pointer, we must supply additional
    information—in this case, the type to which the pointer can point.

    A default initialized smart pointer holds a null pointer. The smart pointer types define a function named get
    that returns a built-in pointer to the object that the smart pointer is managing. (Note. Don’t delete the
    pointer returned from get() )

        • unique_ptr
    A unique_ptr “owns” the object to which it points. Unlike shared_ptr, only one unique_ptr at a time can point to
    a given object.

    Because a unique_ptr owns the object to which it points, unique_ptr does not support ordinary copy or
    assignment.

    The object to which a unique_ptr points is destroyed when the unique_ptr is destroyed.

    unique_ptr is defined in the <memory> header in the C++ Standard Library. It is exactly as efficient as a raw
    pointer and can be used in C++ Standard Library containers.

    In addition to managing the pointed object's lifetime, unique_ptr provides the other expected capabilities of a
    smart pointer: it overloads operator* and operator->, provides a means to obtain the raw pointer (get), to
    relinquish control of the pointed object (release), and to replace the object it manages (reset).

    */

    unique_ptr<string> up;

    unique_ptr<string> up1(new string("Stegosaurs")); // still using new: unique_ptr<T>(new T())

    cout << "*unique_ptr<string>: " << *up1 << endl;

    /*
    A unique_ptr does not share its pointer. It cannot be copied to another unique_ptr, passed by value to a
    function, or used in any C++ Standard Library algorithm that requires copies to be made. A unique_ptr can only
    be moved. This means that the ownership of the memory resource is transferred to another unique_ptr and the
    original unique_ptr no longer owns it.
    */

    // ERR no copy: constructor explicitly deleted
    // unique_ptr<string> up2(up1);

    // ERR no assign: operator= explicitly deleted
    // up = up1;

    // make_unique
    // Create and return a unique_ptr to an object of the specified type
    // The addition of make_unique finally means we can tell people to 'never' use new rather than the previous rule
    // to "never use new except when you make a unique_ptr".

    // Use the constructor that matches these arguments C++14?
    // can use auto with make_unique
    auto upi1 = make_unique<int>(5);
    cout << "*make_unique<int>(5): " << *upi1 << endl;

    // Use the Entity default constructor.
    unique_ptr<Entity> upe1 = make_unique<Entity>();

    // Use the constructor that matches these arguments
    auto upe2 = make_unique<Entity>("Felis", 22);

    // Create a unique_ptr to an array of 5 Entities
    unique_ptr<Entity[]> upe3 = make_unique<Entity[]>(5);

    // unique_ptr can be used in standard containers
    vector<unique_ptr<Entity>> vec;
    // ERR C2280
    // attempting to invoke copy constructor, which is a deleted function.
    // vec.push_back(upe2);

    // OK. upe2 no longer points to anything
    vec.push_back(std::move(upe2));
}

/*
A pointer is an object in memory, so like any object it has an address.
Therefore, we can store the address of a pointer in another pointer.
*/
void pointerToAPointer()
{
    int ival = 1024;
    int *pi = &ival; // pi points to an int (1 kere sekerek objeye gidersin)
    int **ppi = &pi; // ppi points to a pointer to an int (2 kere sekerek objeye
                     // gidersin)

    cout << "The value of ival\n==================\n"
         << "direct value: " << ival << "\n"
         << "indirect value: " << *pi << "\n"
         << "doubly indirect value: " << **ppi << endl;
}

/*
When you want to change the value of a variable to a value computed by a function, you have three choices. For example:

    int incr_v(int x) { return x+1; } // compute a new value and return it
    void incr_p(int* p) { ++*p; } // pass a pointer, dereference it and increment the result
    void incr_r(int& r) { ++r; } // pass a reference

How do you choose? We think returning the value often leads to the most obvious (and therefore least error-prone) code;
that is:

    int x = 2;
    x = incr_v(x); // copy x to incr_v(); then copy the result out and assign it

We prefer that style for small objects, such as an int.
In addition, if a “large object” has a move constructor we can efficiently pass it back and forth.

If you use a pointer as a function argument, the function has to beware that someone might call it with a null pointer,
that is, with a "nullptr". (remember to test for nullptr)
*/

int increment(int arg)
{
    return ++arg;
}

/*
Pointer Parameters
Pointers behave like any other nonreference type. When we copy a pointer, the value of the pointer is copied.
After the copy, the two pointers are distinct.
However, a pointer also gives us indirect access to the object to which that pointer points.
We can change the value of that object by assigning through the pointer (dereferencing).

(Programmers accustomed to programming in C often use pointer parameters to access objects outside a function.
In C++, programmers generally use reference parameters instead.)
*/
void increment_ptr(int *ptr)
{
    // dereferencing a pointer to modify the value of the variable pointed
    ++(*ptr);
}
/*
Passing Arguments by Reference
Operations on a reference are actually operations on the object to which the reference refers.
Reference parameters exploit this behavior.
They are often used to allow a function to operate directly and change the value of one or more of its arguments.
(If you want to change the value of the object passed, you must use a non-const reference.)

Our rule of thumb is:
1. Use pass-by-value to pass very small objects.
2. Use pass-by-const-reference to pass large objects that you don’t need to modify.
3. Return a result rather than modifying an object through a reference argument.
4. Use pass-by-reference only when you have to. (If we see an argument passed by non-const reference, we must assume
that the called function will modify that argument.)
*/
void increment_ref(int &ref)
{
    // no need to dereference
    ref++;
}

// Reference parameters that are not changed inside a function should be references to const
void print_refToConst(const string &s)
{
    for (const auto &c : s)
        std::cout << c << "  ";

    std::cout << endl;
}

// function body is the same. however, a const argument in the calling function cannot be passed!!
void print_refToNonConst(string &s)
{
    for (const auto &c : s)
        std::cout << c << "  ";

    std::cout << endl;
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
int *returnTheAddressOfALocal()
{
    int a = 5;
    return &a; // address of stack memory associated with local variable
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

Let's have a simple function foo:

    int foo (int x) { return 2+x; }

A function pointer type has the notation:

    int (*fptr)(int)

The key to writing the declaration for a function pointer is that you're just
writing out the declaration of a function but with (*func_name) where you'd
normally just put func_name. For example:

    f is a pointer to a function taking one integer argument, and returns void:

    void (*f)(int);     // do not forget paranthesis around *f

Invoke the function pointed to just as if you were calling a function.

now we can use f in the function decleration:

    processEvent( void (*f)(int) ){
        ...
        f(n);
        ...
    }

typedef is a language construct that associates a name to a type.
It can be used ease the reading of the code - especially for pointers to functions, or structure names.

    typedef void callback(int);     // like normal function decleration syntax. "callback" is now a typename.

now we can use f in the function decleration:
    processEvent( callback f ){ ... f(n); ... }


Function pointers provide a way of passing around instructions for how to do
something. You can write flexible functions and libraries that allow the
programmer to choose behavior by passing function pointers as arguments

*/

typedef void callback(int); // typename is now "callback"

// void loopAndCallBack(vector<int> &v, void (*f)(int))
void loopAndCallBack(const vector<int> &v, callback myHandler) // typedef
{
    for (int n : v)
    {
        // execute callback - with related parameters!
        myHandler(n);
    }
}

void incrementAllBoxes(vector<Box> &boxes, void (*f)(mk::Box &))
{
    for (Box &b : boxes)
    {
        // execute callback - with related parameters!
        f(b);
    }
}

void sampleHandler()
{
    cout << "Handler is called";
}

void process(void (*f)())
{
    // do some stuff
    f(); // callback
         // do some more stuff
}

void functionPointerBasics()
{
    process(sampleHandler);

    vector<int> nums{1, 2, 3, 4, 5};
    loopAndCallBack(nums, simplePrint);

    vector<Box> boxes;
    for (int i = 0; i < 5; i++)
    {
        Box b{i};
        boxes.push_back(b);
        cout << b;
    }

    incrementAllBoxes(boxes, mayModifyArgument);

    for (const Box &b : boxes)
    {
        cout << b;
    }
}

/*

  A reference is not an object. Instead, a reference is just another name for an already existing object. After a
  reference has been defined, all operations on that reference are actually operations on the object to which the
  reference is bound.

  Ordinarily, when we initialize a variable, the value of the initializer is copied into the object we are creating.
  When we define a reference, instead of copying the initializer’s value, we bind the reference to its initializer.
  Once initialized, a reference remains bound to its initial object. There is no way to rebind a reference to refer
  to a different object. Because there is no way to rebind a reference, references must be initialized.

      int& refVal2; //ERR:
      int& refVal3 = 10; //ERR: initializer must be an object

    • Assignment to a reference changes the value of the object referred to (not the reference itself).
    • You cannot make a reference refer to a different object after initialization.

*/
void referenceBasics()
{
    // Type& newname = existing name;

    int x = 10;
    // pointer
    int *xptr = &x;

    // reference
    int &xRef = x; // int& yerine int gönderebiliyoruz (as a reference)
    xRef = 7;      // assign to x through reference (no * needed)

    int &xRef2 = *xptr; // & is part of the declaration; * is the dereference operator
    int x2 = xRef;      // read x through reference (no * needed)

    // Because references are not objects, they don’t have addresses, &xRef
    // returns the address of the referenced object:
    cout << "x      : " << x << endl;
    cout << "xRef   : " << xRef << endl;
    cout << "xRef2  : " << xRef2 << endl;
    cout << "&x     : " << &x << endl;
    cout << "&xRef  : " << &xRef << endl;
    cout << "&xRef2 : " << &xRef2 << endl;
    cout << "xptr   : " << xptr << endl;

    // A pointer needs to be dereferenced  (*) to access the memory location it points to,
    // whereas a reference can be used directly.
    *xptr += 1;
    simplePrint("Modified through pointer", x);

    x += 2;
    simplePrint("x", x);

    // modify through reference, like a regular variable name!
    // reference just defines an alias.
    xRef += 3;
    simplePrint("Modified through reference", x);

    // call like regular variable: we do not know looking at caller syntax if
    // parameter is int reference or int !! We have to look method signature.
    increment_ref(x);
    simplePrint("Modified through a function arg (ref)", x);

    // reference to const
    string s1 = "Non-constant string";
    const string s2 = "Constant string";
    print_refToConst(s1);
    print_refToConst(s2);

    print_refToNonConst(s1);
    // print_refToNonConst(s2); // ERR! const argument to a non-const reference parameter!

    // Using 2 reference parameters, as an alternative to returning 2 values
    int o_min, o_max;
    min_max(o_min, o_max, 333, 11);
    cout << "Min:\t" << o_min << "\nMax:\t" << o_max << endl;
}

// Remember: If we see an argument passed by non-const reference,
// we must assume that the called function will modify that argument.
void mayModifyArgument(mk::Box &b)
{
    cout << __func__ << endl;
    ++b;
}

// Remember: Use pass-by-const-reference to pass large objects that you don’t need to modify.
void doNotModifyArgument(const mk::Box &b)
{
    cout << __func__ << endl;
}

void resetArgument(int &arg)
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