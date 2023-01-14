#include "domain.h"
#include "functions.h"
#include <iomanip> // std::setprecision
#include <iostream>

using namespace std;

void printTitle(const std::string &title)
{
    cout << "\n---------- " << title << " ----------\n\n";
}
void simplePrint(int arg)
{
    cout << arg << endl;
}

void simplePrint(double arg)
{
    std::cout << std::fixed << std::setprecision(2) << arg << endl;
}

template <typename T> void simplePrint(T *p)
{
    cout << "ptr: " << p << ", *ptr: " << *p << endl;
}

void simplePrint(const int *p)
{
    cout << "ptr: " << p << ", *ptr: " << *p << endl;
}

void simplePrint(const std::string &title, int arg)
{
    cout << title << ": " << arg << endl;
}
void simplePrint(const std::string &title, double arg)
{
    cout << title << ": " << arg << endl;
}

// Remember: An array does not know its size.
void printArray_v1(int cnt, int arg[])
{
    cout << "Array contents: " << endl;
    for (int i = 0; i < cnt; i++)
    {
        cout << arg[i];
        if (i != cnt - 1)
            cout << ", ";
    }
}

void simplePrint(int cnt, int *arg)
{
    cout << "[";
    for (int i = 0; i < cnt; i++)
    {
        if (i != 0)
            cout << ", ";
        cout << arg[i]; // access arbitrary element: [i]
    }
    cout << "]" << endl;
}

// print an array using iterator logic
template <typename T> void simplePrint(T *begin, T *end)
{
    cout << "[";
    int i = 0; // just for the comma seperation
    while (begin != end)
    {
        if (i != 0)
            cout << ", ";
        cout << *begin++; // dereference iterator and then increment
        i++;
    }
    cout << "]" << endl;
}

// “Pass-by-const-reference”
void simplePrint(const std::vector<int> &vect)
{
    std::string separator;
    cout << "\n[";
    for (const auto &e : vect)
    {
        cout << separator << e;
        separator = ", ";
    }
    cout << "]" << endl;

    /* for (int i = 0; i < v.size(); i++) {
       cout << "v[" << i << "]: " << v[i];
       if (i != v.size() - 1)
         cout << ", ";
       else
         cout << endl;
     }*/
}

void variableBasics()
{

    /*
        In a C++ program, a name starts with a letter and contains only letters,
       digits, and underscores. Language reserves many (about 85) names as
       “keywords.” You can’t use those to name your variables, types, functions,
       etc.

        Our “house style” is to use underscores to separate words in an
       identifier, such as element_count, rather than alternatives, such as
       elementCount and ElementCount.

        We use an initial capital letter for types we define, such as Square and
       Graph. The C++ language and standard library don’t use the
       initial-capital-letter style, so it’s int rather than Int and string rather
       than String. Thus, our convention helps to minimize confusion between our
       types and the standard ones.

    */
    // C++ provides a rather large number of types. However, you can write
    // perfectly good programs using only five of those:

    /*
      Initialization is not assignment.

      It is tempting to think of initialization as a form of assignment, but
      initialization and assignment are different operations in C++. This concept
      is particularly confusing because in many languages the distinction is
      irrelevant and can be ignored. Initialization happens when a variable is
      given a value when it is created. Assignment obliterates an object’s current
      value and replaces that value with a new one. The generalized use of curly
      braces for initialization was introduced as part of the new standard. Most
      classes let us define objects without explicit initializers. Such classes
      supply an appropriate default value for us. For example, as we’ve just seen,
      the library string class says that if we do not supply an initializer, then
      the resulting string is the empty string

      std::string str;  // implicitly initialized to the empty string
  */

    // In C and C++, LOCAL primitives are NOT initialized by default.
    // Uninitialized variables can contain any value, and their use leads to
    // undefined behavior.
    int a, b, c; // Danger!
    a = b + c;
    simplePrint("a", a); // i.e 26677

    int y{2};                    // initializer using the {} syntax - define and immediately
                                 // initialize with 2
    y = 9.9;                     // implicit conversion!
    y = static_cast<int>(99.99); // 99

    int cnt = 39;
    y = cnt++; // 2 statements: y = cnt; cnt += 1;  therefore, y=39, cnt=40
    y = ++cnt; // 2 statements: cnt += 1; y = cnt;  therefore, y=41, cnt=41

    // double (default) and float for floating-point numbers
    double flying_time(3.5);
    float driving_time = 4.0f;
    double int_math = 3 / 2;      // integer math! equals 1.0
    double double_math = 3.0 / 2; // 1.5

    // char: an individual character enclosed in single quotes
    char decimal_point = '.';

    // string: a sequence of characters delimited by double quotes
    string name = "Annemarie";

    // bool for logical variables. either true or false
    bool tap_on = true;

    // string name2 = 39; // error: 39 isn’t a string
    // int number_of_steps = "Annemarie";     // error: “Annemarie” is not an int”

    /*
    Constants have the same declaration syntax as variables.
    They differ in having const as part of their type and requiring an
    initializer.
    */
    // It is almost always a good idea to initialize "variables" also; an
    // uninitialized variable is a recipe for obscure bugs.

    const int x1 = 7;
    const int x2{9}; // initializer using the {} syntax

    // TODO
    // sizes();
}

void stringBasics()
{

    // C Language does not support strings out of the box.
    // Instead of strings, C uses an array of single characters.

    // initialize using double quotes
    // Option 1: square braces []
    // An array of chars can be initialized with a string literal.
    // the compiler adds a terminating zero character at the end of a string literal.
    // this actually is
    // char name[6] = {'M','u','r','a','t','\0'};
    // so 6 element array is used to store 5 charecter string.
    // char name[5] = "Murat"; // ERR - a value of type const char[6] cannot be used to init an entity of type
    // char[5]
    char name[] = "Murat";

    // Option 2: USING A POINTER *
    // string literals are designed to be constant, stored in read-only memory
    // const modifier means that your compiler will complain if you try to modify an array with that particular
    // variable.
    const char *surname = "Karadas";

    // string.h functions
    // C supports a wide range of functions that manipulate null-terminated strings
    // Remember: An array does not know its size. Relying on the terminating zero
    // convention, we can write strlen()
    char episode1[25] = "The Phantom Menace";
    char episode2[25] = "Attack of the Clones";
    char episode3[25] = "Revenge of the Sith";
    const char *episode4 = "Star Wars";
    const char *episode5 = "The Empire Strikes Back";
    const char *episode6 = "Return of the Jedi";

    // name of an array is a pointer to (address of) first element, so access first element by dereferencing the name
    cout << "*episode1: " << *episode1 << endl;               // T
    cout << "episode1: " << episode1 << endl;                 // The Phantom Menace
    cout << "strlen(episode1): " << strlen(episode1) << endl; // 18 (does not count '\0')
    cout << "sizeof(episode1): " << sizeof(episode1) << endl; // 25 - array size: 25 * 1 bytes (char)

    cout << "*episode4: " << *episode4 << endl;               // S
    cout << "episode4: " << episode4 << endl;                 // Star Wars
    cout << "strlen(episode4): " << strlen(episode4) << endl; // 9 (does not count '\0')
    cout << "sizeof(episode4): " << sizeof(episode4) << endl; // 8 - pointer size!

    /*
    copy the string pointed by source (including the null character) to the destination.
    episode1 = episode4
    Note: the size of the destination string should be large enough to store the copied string.
    */
    strcpy(episode1, episode4); // episode1 is now "Star Wars"

    /*
    Copy block of memory
    void * memcpy ( void * destination, const void * source, size_t n );
    Copies "n" bytes from the location pointed to by source directly to destination, stops as soon as it reaches n
    bytes.
    */
    memcpy(episode2, episode4, strlen(episode4) + 1); // episode2 is now "Star Wars"
    cout << "memcpy(episode2, episode4, strlen(episode4) + 1)\n";
    cout << "Length of episode4: " << strlen(episode4) << "\n";
    cout << "episode2: " << episode2 << "\n";
    cout << "episode4: " << episode4 << endl;

    /* concatenates str1 and str2 */
    strcat(episode1, " Episode I"); // episode1 is now "Star Wars Episode I"
    cout << "strcat(episode1, ' Episode I ')\n";
    cout << "episode1: " << episode1 << endl;

    cout << "Length of episode4: " << strlen(episode4) << endl;

    cout << "\nv1, Loop over a char* by dereferencing and then incrementing the pointer: " << endl;
    while (*episode5)
    {
        cout << *episode5 << " ";
        ++episode5; // be careful, modifying the pointer!
    }

    cout << "\nv2, Loop over a char* using index and then incrementing the index: " << endl;
    size_t i = 0;
    while (episode6[i])
    {
        cout << episode6[i++] << "_";
    }

    // C++ has several different forms of initialization

    std::string s1;        // default initialization; empty string
    std::string s2("MK");  // direct initialization
    std::string s3 = s1;   // copy initialization
    std::string s4 = "MK"; // copy initialization
    s1 = "MK";             // copy assignment (operator=) (s1 was initialized before)

    // Ask the compiler to provide appropriate type by using "auto".
    // (string::size_type) Although we don’t know the precise type of
    // string::size_type, we do know that it is an unsigned type big enough to
    // hold the size of any string (machine independent manner)
    auto str_length = s1.size();
    cout << "\"MK\".size(): " << str_length << endl;

    if (s1.empty() || s1.size() < 2)
        cout << "Do we have a problem with the string?" << endl;

    // Dealing with the Characters in a string
    char mychar = 'A', mydigit = '5';
    if (isalpha(mychar) && isupper(mychar) && isdigit(mydigit))
        cout << "valid char" << endl;

// If we want to do something to every character in a string
// by far the best approach is to use a statement introduced by the new
// standard: the range for statement.
std:
    string username = "$abc123_";
    bool allAlphaNumericChars = true;
    // int punct_cnt = 0;
    decltype(username.size()) punct_cnt = 0; // decltype to declare our counter based on the string username.
                                             // (size_t)
    for (auto c : username)                  // char c
    {
        if (ispunct(c))
            ++punct_cnt;
        if (!isalnum(c))
            allAlphaNumericChars = false;
    }

    // convert to uppercase
    for (auto &c : username) // for each char in username (note: c is a reference)
    {
        c = toupper(c);
    }

    std::string result = allAlphaNumericChars ? "valid" : "invalid";
    cout << "Punctuation chars (" << username << "): " << punct_cnt << endl;
    cout << "Only alphanumeric chars (" << username << "): " << result << endl;

    // use the subscript operator to print the first character
    // When we use a subscript, we must ensure that the subscript is in range.
    // That is, the subscript must be >= 0 and < the size() of the string.
    // One way to simplify code that uses subscripts is always to use a variable
    // of type string::size_type as the subscript. Because that type is unsigned,
    // we ensure that the subscript cannot be less than zero.

    if (!username.empty())
        cout << "First character is: " << username[0] << endl;
}

void arrayBasics()
{
    /*
    An array (c-array) is a homogeneous sequence of objects allocated in
    contiguous memory; that is, all elements of an array have the same type and
    there are no gaps between the objects of the sequence. The elements of an
    array are numbered from 0 upward. In a declaration, an array is indicated by
    “square brackets”

    Note the limitation: the number of elements of a named array must be known at
    compile time. size cannot be changed.

    Declare an array: N elements of type T

      T identifier[N] // uninitialized!

    The name of an array refers to all the elements of the array. Consider:

      char ch[100];
      sizeof(ch);     // 100 * 1byte

    Access the pointer              : array_name        (pointer to the first element)
    Copy the pointer (assign)       : T* p = array_name
    Access element                  : *array_name       (first element)
    Access random element           : array_name[n]
    Move forward by arbitrary n     : array_name += n   (p += n)
    Distance between two elements   : q - p
    */

    // In a declaration, an array is indicated by square brackets
    // By default, regular arrays of primitives with local scope (i.e, those declared within a function) are left
    // uninitialized.
    int myArray[10];         // uninitilized
    simplePrint(5, myArray); // garbage! like, [-421667480, 1, -421667480, 1, 1876948592]

    int scores[5] = {0}; // scores has type int[5] and holds all zeroes
    int *p = scores;     // &scores[0]

    cout << "int scores[5] = {}\n";
    cout << "scores         : " << scores << "\n";     // 0x...
    cout << "&scores[0]     : " << &scores[0] << "\n"; // same
    cout << "scores[0]      : " << scores[0] << "\n";
    cout << "sizeof(scores) : " << sizeof(scores) << "\n"; // 5 * 4 bytes = 20
    cout << "size of ptr    : " << sizeof(p) << endl;      // 4 bytes

    // printArray_v1(5, scores);
    simplePrint(5, scores);

    // arrays can be initialized by a list of values of their element type
    double areas[] = {1.0, 2.0, 3.0};

    // declare an array of Entity objects
    // you would have to provide an initializer for each element of the array at the point where you define the array.
    mk::Entity entities[5]; // calls the default constructor 5 times

    // C Language does not support strings out of the box.
    // Instead of strings, C uses an array of single characters.

    // initialize using double quotes
    // Option 1: square braces []
    // An array of chars can be initialized with a string literal.
    // this actually is
    // char name[6] = {'M','u','r','a','t','\0'};
    // so 6 element array is used to store 5 charecter string.
    // char name[5] = "Murat"; // ERR - a value of type const char[6] cannot be used to init an entity of type
    // char[5]
    char name[] = "Murat";

    // Option 2: USING A POINTER *
    // string literals are designed to be constant, stored in read-only memory
    // const modifier means that your compiler will complain if you try to modify an array with that particular
    // variable.
    const char *surname = "Karadas";

    // stl algorithms
    const int SIZE = 7;
    double weights[SIZE] = {71.0, 82.5, 63.0, 57.9, 66.2, 103.8, 58.0};

    // begin is weights, or &weights[0]
    // end is 1 past last, which is weights+SIZE, or &weights[SIZE]
    // array size is: end - begin (index starts at 0)
    std::sort(weights, weights + SIZE);
    simplePrint(weights, weights + SIZE);
}

void listBasics()
{
    printTitle("List Basics");

    /*
    A container holds a collection of objects of a specified type.
    The sequential containers let the programmer control the order (the position at which elements are put into the
    container) in which the elements are stored and accessed.

    The list and forward_list containers are designed to make it fast to add or remove an element anywhere in the
    container. In exchange, these types do not support random access to elements: We can access an element only by
    iterating through the container. Moreover, the memory overhead for these containers is often substantial, when
    compared to vector, deque , and array.

    */
}

void vectorBasics()
{
    printTitle("Vector Basics");

    /*
    An ArrayList could be a better name, maybe.
    Vectors are sequence containers representing arrays that can change in size.

    Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements
    can also be accessed using offsets on regular pointers to its elements, and just as efficiently as in arrays.

    However, adding or removing elements in the middle of one of these containers takes time: All the elements after
    the one inserted or removed have to be moved to maintain contiguity. Moreover, adding an element can sometimes
    require that additional storage be allocated. In that case, every element must be moved into the new storage.

    The elements are stored contiguously, which means that elements can be accessed not only through iterators, but also
    using offsets to regular pointers to elements. This means that a pointer to an element of a vector may be passed to
    any function that expects a pointer to an element of an array.

    The storage of the vector is handled automatically, being expanded as needed. Vectors usually occupy more space
    than static arrays, because more memory is allocated to handle future growth. This way a vector does not need to
    reallocate each time an element is inserted, but only when the additional memory is exhausted. (thus the container
    may have an actual capacity() greater than the storage strictly needed to contain its elements (i.e., its size())

    Libraries can implement different strategies for growth to balance between memory usage and reallocations, but
    in any case, reallocations should only happen at "logarithmically growing intervals of size" so that the insertion
    of individual elements at the end of the vector can be provided with "amortized" constant time complexity (see
    push_back).

    Compared to arrays, vectors consume more memory in exchange for the ability to manage storage and grow
    dynamically in an efficient way. Extra memory can be returned to the system via a call to shrink_to_fit().


    The complexity (efficiency) of common operations on vectors is as follows:

        * Random access - constant O(1)
        * Insertion or removal of elements at the end - "amortized" constant O(1)
            (each time the array is full, allocate new space, copy your data into the new region, and free old space.)
        * Insertion or removal of elements - linear in the distance to the end of the vector O(n) (shifting)

    Compared to the other dynamic sequence containers (deques, lists and forward_lists), vectors are very efficient
    accessing its elements (just like arrays) and relatively efficient adding or removing elements from its end. For
    operations that involve inserting or removing elements at positions other than the end, they perform worse than the
    others, and have less consistent iterators and references than lists and forward_lists. A vector is the preferred
    container for a sequence when random-access performance is at a premium.


    Reallocations are usually costly operations in terms of performance. The reserve() function can be used to eliminate
    reallocations if the number of elements is known beforehand.

    When we use container operations that add or remove elements, it is essential to remember that these operations can
    invalidate iterators, pointers, or references to elements in the container.

    Note. vector is a template, not a type. We can define vectors to hold objects of most any type.
    Types generated from vector must include the element type, for example, vector<int>

    When we call a push or insert member, we pass objects of the element type and those objects are copied into the
    container. When we call an "emplace" member, we pass arguments to a constructor for the element type. The emplace
    members use those arguments to construct an element directly in space managed by the container.

    The emplace functions construct elements in the container.
    The arguments to these functions must match a constructor for the element type.
    */

    // Default initialize a vector, which creates an empty vector of the specified type
    vector<int> v;

    if (v.empty())
        cout << "Default initialized vector is empty.\n";

    cout << " capacity() : " << v.capacity() << "\n"; // 0
    cout << " size()     : " << v.size() << endl;     // 0

    // The call to push_back creates a new element at the end of container, increasing the size of container by 1.
    // The value of that element is a "copy" of the element, not the element itself.
    v.push_back(1);

    cout << "push_back(1);\n";
    cout << " capacity() : " << v.capacity() << "\n"; // 1
    cout << " size()     : " << v.size() << endl;     // 1

    cout << "For i = 2 To 100 push_back(i);\n";
    int prev_capacity = v.capacity();
    for (int i = 2; i < 100; i++)
    {
        v.push_back(i);
        if (v.capacity() - prev_capacity > 1)
            cout << "Reallocation - capacity is now " << v.capacity() << " from " << prev_capacity
                 << ", size: " << v.size() << "\n";

        prev_capacity = v.capacity();
    }

    // Accessing Elements
    // You can refer to an element by its index (subscript)
    // check that there are elements before dereferencing an iterator or calling front or back
    if (!v.empty())
    {
        cout << " v[0]: " << v[0] << endl;
        cout << " front(): " << v.front() << endl;
        cout << " at(0): " << v.at(0) << endl;
        cout << " Last element: " << v[v.size() - 1] << endl;
        cout << " back(): " << v.back() << endl;
    }

    // fill constructors
    // Constructs a container with n elements. Each element is a copy of val(if provided)
    vector<int> vect2(5); // create a vector of 5 integers with default value of 0
    simplePrint(vect2);

    std::vector<int> vect3(5, 10); // create a vector of 5 integers with value 10
    simplePrint(vect3);

    // initializer list
    vector<double> ages = {0.33, 22.0, 27.2};
    ages[2] = 22.2;

    // We can use the constructor that takes a size argument if the element type is
    // a built-in type or a class type that has a default constructor
    vector<mk::Entity> entities(5); // fill with objects, default constructor
    cout << "entities.size() : " << entities.size() << endl;

    vector<mk::Entity> entities2;
    entities2.reserve(2);

    cout << "Create and push_back()\n";
    mk::Entity e1{"E1", 1};  // initialize an Entity object
    entities2.push_back(e1); // copy(!) existing object into the container

    cout << "emplace_back()\n";
    // When we call an "emplace" member, we pass arguments to a constructor for the element type.
    // The emplace members use those arguments to construct an element directly in space managed by the container.
    entities2.emplace_back("E2", 2);

    vector<mk::Box> boxes2; // default initialize, empty vector
    boxes2.reserve(5);      // prevent reallocation if you know the size, ie., capacity 0 -> 1 -> 2 -> 4 ..
    cout << "boxes2.capacity(): " << boxes2.capacity() << endl;
    cout << "boxes2.size(): " << boxes2.size() << endl;

    traverseVector(entities);

    // The container equality operators use the element’s == operator, and the relational operators use the
    // element’s < operator. If the element type doesn’t support the required operator, then we cannot use the
    // corresponding operations on containers holding that type.
    if (entities == entities2)
        cout << "Two vectors are equal." << endl;
    else
        cout << "Two vectors are not equal" << endl;

    // No push_front() on vector but we can insert before begin()
    // warning : inserting anywhere but at the end of a vector might be slow
    vector<string> svec;
    svec.push_back("10");
    svec.push_back("20");
    svec.push_back("30");

    // like insert an element at svec[0]="0" and move the remaining:
    svec.insert(svec.begin(), "0!"); //[0!, 10, 20, 30]

    // like insert an element at svec[2]="15" and move the remaining:
    svec.insert(svec.begin() + 2, "15!"); // [0!, 10, 15!, 20, 30]
    traverseVector(svec);

    // insert last element of svec into the beginning of svec2
    vector<string> svec2 = {"ten", "eleven"};
    svec2.insert(svec2.begin(), svec.end() - 1, svec.end()); // [Three, ten, eleven]
    traverseVector(svec2);

    vector<string> va = {"A0", "A1", "A2"};
    vector<string> vb = {"B", "B1", "B"};

    cout << "Append vector vb to va:" << endl;
    va.insert(va.end(), vb.begin(), vb.end()); // [A0, A1, A2, B, B1, B]
    traverseVector(va);

    cout << "Erase element at index 2:" << endl;
    va.erase(va.begin() + 2); // [A0, A1, B, B1, B]
    traverseVector(va);

    cout << "Find and erase element 'B':" << endl;
    auto it = find(va.begin(), va.end(), "B");
    if (it != va.end())
        va.erase(it); // if found, delete element   [A0, A1, B1, B]
    else
        cout << "Element not found." << endl;
    traverseVector(va);

    // Almost any type can be used as the element type of a sequential container.
    vector<vector<string>> lines; // vector of vectors
}
template <typename T> void traverseVector(const vector<T> &vect)
{
    printTitle("Traverse a Vector");

    cout << "index[";
    // traverse using index
    for (int i = 0; i < vect.size(); ++i)
    {
        if (i != 0)
            cout << ", ";

        cout << vect[i];
    }
    cout << "]" << endl;

    cout << "iterator[";
    // traverse using iterator
    int comma = 0;
    for (auto it = vect.begin(); it != vect.end(); ++it)
    {
        if (comma++ != 0)
            cout << ", ";

        cout << *it;
    }
    cout << "]" << endl;

    cout << "foreach[";
    // traverse using for each
    comma = 0;
    for (const auto &item : vect)
    {
        if (comma++ != 0)
            cout << ", ";

        cout << item;
    }
    cout << "]" << endl;
}

/*
Use "const" keyword to prevent const objects from getting mutated.

const member functions cannot change object. (i.e. simple getters)
  - const objects can only invoke const member functions

- by default, pass pointers and references to const:

void cStr(const char* str);
void cppStr(const std::string& str);

read from right to left:

a. pointer is constant, and points to type T

    T* const ptr

b. ptr points to a constant of type T
(the value pointed is constant)

    const T* ptr;

you cant dereference pointer and mutate the value that is pointed!
    *ptr = T{ ... }; // ERR read only var

*/
void constBasics()
{
    int value = 11;

    // variation 1
    int *ptr1 = &value;
    simplePrint(ptr1);

    // variation 2 (as in function declerations)
    const int *ptr2 = &value;
    // simplePrint(ptr2);

    // variation 3
    int *const ptr3 = &value;
    // simplePrint(ptr3);

    // variation 4
    const int *const ptr4 = &value;
    // simplePrint(ptr4);

    int other_value = 22;

    // mutate the pointer: the value of the pointer can change:
    ptr1 = &other_value; // OK
    // mutate the pointee: the value pointed can change:
    *ptr1 = 33; // OK
    simplePrint(ptr1);

    ptr2 = &other_value;
    // (as in function decletations)
    // you cant dereference pointer and mutate the value that is pointed!
    // *ptr2 = 33; // ERR read only var
    // simplePrint(ptr2);

    // ptr3 = &other_value; //ERR
    *ptr3 = 333; // OK
                 // simplePrint(ptr3);

    // ptr4 = &other_value; //ERR
    // *ptr4 = 444; // ERR read only var
    // simplePrint(ptr4);

    mk::Box box1{10};
    const mk::Box box2{10};

    mayModifyArgument(box1); // OK
    // ERR: We cannot bind a plain reference to a const object.
    // Remember: If we see an argument passed by non-const reference,
    // we must assume that the called function will modify that argument.
    // mayModifyArgument(box2);

    doNotModifyArgument(box1); // OK
    doNotModifyArgument(box2); // OK
}

void inputBasics()
{
    getUserInputStr();
    // addInputNumbers();
    // sumAllInputs();
    // compareInputs();
}

void getUserInputStr()
{
    // read from s into x
    // s >> x

    // write x to s
    // s << x

    string name;

    // 1. A string read using >> is (by default) terminated by whitespace; that
    // is, it reads a single word. whitespace by default is ignored by >> cin >>
    // name; // read characters into name (only the first word)

    // 2. Sometimes we do not want to ignore the whitespace in our input.
    // In such cases, we can use the getline() function instead of the >>
    // operator.

    while (true)
    {
        // get input
        cout << "\nPlease enter your name: ";
        getline(cin, name);

        // check validity. If valid, break the loop
        if (name.empty())
            cout << "Missing name." << endl;
        else if (name.size() < 2) // returns string::size_t type value, not int.
                                  // (machine independent manner)
            cout << "At least 2 chars. " << endl;
        else
            break; // valid input, break the loop

    } // loop while there is a problem

    cout << "Hello, " << name << endl;
}
int sumAllInputs()
{
    int sum{0}, value{0};
    cout << "Enter numbers "
         << "\n[Q]uit and display the sum >";

    // read until end-of-file, calculating a running total of all values read
    // (Win: Ctrl-Z, Linux: Ctrl-D) When we use an istream as a condition, the
    // effect is to test the state of the stream. If the stream is valid—that is,
    // if the stream hasn’t encountered an error—then the test succeeds. An
    // istream becomes invalid when we hit end-of-file or encounter an invalid
    // input, such as reading a value that is not an integer.
    while (std::cin >> value)
    {
        sum += value;
        std::cout << "running sum: " << sum << std::endl;
    }
    std::cout << "Total: " << sum << std::endl;

    return sum;
}

void addInputNumbers()
{
    int x, y;

    cout << "Enter 2 numbers, seperated by space: ";
    cin >> x >> y;

    // cout << "Enter second number: ";
    // cin >> y;

    cout << x << " + " << y << " = " << x + y << endl;
    // return x+y;
}
void compareInputs()
{
    int x, y;

    cout << "Enter two integers\nPress | to exit): ";
    while (cin >> x >> y)
    {
        if (x == '|')
            break;
        else if (x == y)
        {
            cout << x << " == " << y << endl;
        }
        else if (x > y)
        {
            cout << x << " > " << y << endl;
        }
        else
        {
            cout << x << " < " << y << endl;
        }

        cout << "Enter two integers: ";
    }
}

/*
Function templates are special functions that can operate with generic types.
This allows us to create a function template whose functionality can be adapted
to more than one type or class without repeating the entire code for each type.
*/
template <typename T> const T &getMax(const T &a, const T &b)
{
    return a > b ? a : b;
}

void templateFunctions()
{

    std::cout << "smaller of 1 and 9999 is " << std::min(1, 9999) << '\n';

    int x{10}, y{20};
    double d1{33.3}, d2{22.2};

    int max_i = getMax(x, y);
    double max_d = getMax(d1, d2);

    simplePrint(max_i);
    simplePrint(max_d);
}

int getBiggerOfTwo(int x, int y)
{
    return x > y ? x : y;
}
/*
Like pointers, iterators give us indirect access to an object.
Unlike pointers, we do not use the address-of operator to obtain an iterator. Instead, types that have iterators have
members that return iterators. In particular, the begin member returns an iterator that denotes the first element (or
first character), if there is one.

The iterator returned by end() is an iterator positioned “one past the end” of the associated container (or string).
If the container is empty, the iterators returned by begin and end are equal—they are "both off-the-end" iterators.

The library uses left-inclusive ranges because such ranges have three convenient properties.
Assuming begin and end denote a valid iterator range, then
    * If begin equals end, the range is empty
    * If begin is not equal to end, there is at least one element in the range,
      and begin refers to the first element in that range
    * We can increment begin some number of times until begin == end

    while (begin != end) {
        *begin =  val;    // ok: range isn't empty so begin denotes an element
        ++begin;          // advance the iterator to get the next element
    }

If the object is const, then begin and end return a const_iterator.
if the object is not const, they return iterator.

Any operation, such as push_back, that changes the size of a vector potentially invalidates all iterators into that
vector.

*/
void iteratorBasics()
{
    printTitle("Iterator Basics");

    int numArr[] = {10, 20, 30, 40, 50};
    vector<int> numVect{100, 200, 300, 400, 500};

    cout << "Iterate an array using std::begin() and std::end() and dereferencing\n";

    // In general, we do not know (or care about) the precise type that an iterator has.
    // In this example, we used auto to define it
    // Iterators use the increment (++) operator to move from one element to the next.
    for (auto it = begin(numArr); it != end(numArr); it++)
    {
        // As with pointers, we can dereference an iterator to obtain the element denoted by an iterator.
        // Note that “Dereferencing an invalid iterator or an off-the-end iterator has undefined behavior.
        cout << *it << " ";
    }

    cout << "\nIterate a vector using vector::begin() and vector::end() and dereferencing\n";
    for (auto it = numVect.begin(); it != numVect.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<mk::Entity> entities;
    entities.reserve(3); // prevent reallocation if you know the size, ie., capacity 0 -> 1 -> 2 -> 4 ..
    entities.emplace_back(mk::Entity("E1", 1));
    entities.emplace_back(mk::Entity("E2", 2));
    entities.emplace_back(mk::Entity("E3", 3));

    vector<mk::Entity>::const_iterator it = entities.cbegin();
    while (it != entities.cend())
    {
        if (!(*it).getName().empty())
        {
            cout << (*it).getName(); // parantheses are necessary here.
            cout << it->getName(); // The arrow operator combines dereference and member access into a single operation
        }

        ++it;
    }

    // compute an iterator to the element closest to the midpoint
    // We can add (or subtract) an integral value and an iterator.
    auto mid = entities.begin() + (entities.size() / 2);
    cout << "\nvector midpoint: " << mid->getName() << endl;

    // We can also subtract two iterators
    // so long as they refer to elements in, or one off the end of, the same vector or string.
    std::string text = "abcdefghi";
    auto beg = text.begin(), end = text.end();
    auto midpoint = beg + ((end - beg) / 2); // original midpoint
    cout << "string midpoint: " << *midpoint << endl;

    // begin is array_name, or &array_name[0]
    // end is 1 past last, which is array_name+SIZE, or &array_name[SIZE]
    // array size is: end - begin (index starts at 0)
    std::sort(numArr, numArr + 5);
    simplePrint(numArr, numArr + 5);

    // If the object is const, then begin and end return a const_iterator.
    const vector<int> cv;
    auto it2 = cv.begin(); // it2 has type vector<int>::const_iterator

    // When write access is not needed, use cbegin and cend
    vector<double> vect3;
    auto it3 = vect3.cbegin(); // it3 has type vector<double>::const_iterator
}