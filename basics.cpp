/*
For every condition that has a range, make sure the tests include the first and last items in the range, as well as
items before the first and after the last. The most common mistakes in range tests occur at the extremes of the range.

Data Types
1. Built-in (defined by the language)

Fundamental (Primitive) :
* Integer Type: A number without a fraction.
The signed types can be positive or negative; the unsigned types are only positive. (If we do not explicitly define
the sign of an integer, it is signed.) C++ allows three different sizes of integers. The language does not define the
exact size and ranges of the different integer data types, it emphasizes their relative sizes:
    long long >= long >= int >= short >= char

    1.b Compound

2. User Defined
    2.a Enumerated
    2.b Class
*/

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

    Basically, we can do nothing of interest with a computer without storing data in memory. “The “places” in which we
    store data are called objects. To access an object we need a name. A named object is called a variable and has a
    specific type (such as int or string) that determines what can be put into the object.

    A variable is a memory location, with a name and a type, that stores different values in each moment of a
    program’s execution.

    In a C++ program, a name starts with a letter and contains only letters, digits, and underscores. Language reserves
    many (about 85) names as “keywords.” You can’t use those to name your variables, types, functions, etc.

    The following are all invalid (illegal) identifiers and create a compilation error.

    3z      // starts with a digit
    $cnt    // symbols
    sum@    // symbols
    count-2 // symbols
    delete  // keyword
    double  // keyword

    Our “house style” is to use underscores to separate words in an identifier, such as element_count, rather than
    alternatives, such as elementCount and ElementCount.

    We use an initial capital letter for types we define, such as Square and Graph. The C++ language and
    standard library don’t use the initial-capital-letter style, so it’s int rather than Int and string rather than
    String. Thus, our convention helps to minimize confusion between our types and the standard ones.

    C++ provides a rather large number of types. However, you can write perfectly good programs using only five of
    those.

    Initialization is not assignment.
    It is tempting to think of initialization as a form of assignment, but initialization and assignment are different
    operations in C++. This concept is particularly confusing because in many languages the distinction is irrelevant
    and can be ignored. Initialization happens when a variable is given a value when it is created. Assignment
    obliterates an object’s current value and replaces that value with a new one. The generalized use of curly braces
    for initialization was introduced as part of the new standard.

    Most classes let us define objects without explicit initializers. Such classes supply an appropriate default value
    for us. For example, as we’ve just seen, the library string class says that if we do not supply an initializer, then
    the resulting string is the empty string

            std::string str;  // implicitly initialized to the empty string

    The modern form of initialization (introduced in C++11 as "uniform initialization") with curly braces:

                int i{42};
                std::string s{"hello"};

    This form of initialization, which is called brace initialization, has the following advantages:
        • It can be used with fundamental types, class types, aggregates, enumeration types, and auto
        • It can be used to initialize containers with multiple values
        • It can detect narrowing errors (e.g., initialization of an int by a floating-point value)
        • It cannot be confused with function declarations or calls

    If the braces are empty", the default constructors of (sub)objects are called and fundamental data types
    are guaranteed to be initialized with 0/false/nullptr.
          */

    // In C and C++, LOCAL primitives are NOT initialized by default.
    // Uninitialized variables can contain any value, and their use leads to undefined behavior.
    int a, b, c; // Danger! You declared but didn’t give an initial value. Therefore, you get some “garbage value” that
                 // happened to be in that part of memory when you started executing.

    // Assignment Operator (=)
    // A variable on the right side of an assignment operator means "copy" the value of the variable(as a source); a
    // variable on the left side of the assignment operator means store the value in that variable(as a destination).
    a = b + c;
    simplePrint("a", a); // i.e 26677
    int $cnt = 0;        // is this a valid identifier?

    // If the braces are empty", the default constructors of (sub)objects are called and fundamental data types are
    // guaranteed to be initialized with 0 / false / nullptr.
    int d{};                     // 0
    int y{2};                    // initializer using the {} syntax - define and immediately initialize with 2
    y = 9.9;                     // implicit conversion! from 9.9 to 9
    y = static_cast<int>(99.99); // 99

    int cnt = 39;
    y = cnt++; // 2 statements: y = cnt; cnt += 1;  therefore, y=39, cnt=40
    y = ++cnt; // 2 statements: cnt += 1; y = cnt;  therefore, y=41, cnt=41

    long cnt2 = 39L; // The default value is int (no suffix).
                     // To tell the compiler that we want long, we can use the suffix L (lowercase or uppercase)

    uint8_t u8 = UINT8_MAX;
    uint16_t u16 = UINT16_MAX;
    uint32_t u32 = UINT32_MAX;

    cout << "UINT8_MAX  : " << u8 << ", size: " << sizeof(u8) << "\n";   // 255, size: 1
    cout << "UINT16_MAX : " << u16 << ", size: " << sizeof(u16) << "\n"; // 65535, size: 2
    cout << "UINT32_MAX : " << u32 << ", size: " << sizeof(u32) << "\n"; // 4 294 967 295, size: 4

    short s = SHRT_MAX;
    unsigned short us = USHRT_MAX;
    int i = INT_MAX;
    unsigned int ui = UINT_MAX;
    long l = LONG_MAX;
    unsigned long ul = ULONG_MAX;
    long long ll = LLONG_MAX;
    unsigned long long ull = ULLONG_MAX;

    cout << "short max              : " << s << " \t\t\tsize:" << sizeof(s) << endl;    // 32767, size:2
    cout << "unsigned short max     : " << us << " \t\t\tsize: " << sizeof(us) << endl; // 65535, size: 2
    cout << "int max                : " << i << " \t\tsize: " << sizeof(i) << endl;     // 2147483647, size: 4
    cout << "unsigned int max       : " << ui << " \t\tsize: " << sizeof(ui) << endl;   // 4294967295, size: 4
    cout << "long max               : " << l << " \tsize: " << sizeof(l) << endl;       //
    cout << "unsigned long max      : " << ul << " \tsize: " << sizeof(ul) << endl;     //
    cout << "long long max          : " << ll << " \tsize: " << sizeof(ll) << endl;     //
    cout << "unsigned long long max : " << ull << " \tsize: " << sizeof(ull) << endl;   //

    unsigned int ui2 = -1;                               // Logical error, A negative value is changed to positive
    cout << "unsigned int assigned -1: " << ui2 << endl; // 4294967295

    // double (default) and float for floating-point numbers
    // The reason for the name double is historical: double is short for “double-precision floating point.” Floating
    // point is the computer’s approximation to the mathematical concept of a real number.
    // All floating-point numbers are signed.
    double flying_time(3.5);
    float driving_time = 4.0F;    // suffix F (lowercase or uppercase)
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

    // The new C++ standards have made it possible to use auto as a placeholder for types in various contexts and
    // let the compiler deduce the actual type. The auto specifier is basically a placeholder for an actual type.
    // If you use the auto specifier, you can still learn the type in  most IDEs by putting the cursor over a variable.
    // auto x; // ERR - cannot deduce auto type (initializer required)
    auto title = "Surname"; // const char* title
    auto count = 1;         // int count
    auto temp = 1.0;        // double temp
    auto il = {1, 2, 3};    // std::initializer_list<int> il

    // Declare named lambda functions,
    auto upp = [](const char c) { return toupper(c); }; // int upp(const char c)

    // "auto" means less typing and less concern for actual types that we don't care about anyway.
    // A very common case is with iterators:
    // auto it = m.cbegin();

    // TODO
    // sizes();

    // The size of a char as originally defined in C++ is 1 byte and it was implicitly unsigned.
    char first = 'A'; // A character literal is always enclosed in a pair of single quotes.
    char second = 65; // we can use integer literal

    cout << "Value of first char: " << first << "\tsize: " << sizeof(first) << endl;    // A, size: 1
    cout << "Value of second char: " << second << "\tsize: " << sizeof(second) << endl; // A, size: 1

    // The C++ language defines a type called Boolean (named after the French mathematician/ philosopher George Bool) to
    // represent a value that can be either true or false. The type is referred to as Boolean, but the type name used in
    // a program is actually bool, which is a keyword.
    // Since a Boolean type is in fact a 1 byte integer, we could use a small integer to represent a Boolean
    // literal. Traditionally, any zero value is interpreted as false; any nonzero value is interpreted as true. When
    // the value of a Boolean type is output, it is either 0 or 1.

    if (127)
        cout << "\n127 is true";
    if (-1)
        cout << "\n-1 is true";
    if (0)
        cout << "\n0 is true";
    else
        cout << "\n0 is false";

    bool u = true;
    bool v = false;

    cout << "Value of u: " << u << endl; // 1
    cout << "Value of v: " << v << endl; // 0

    // boolalpha output
    cout << std::boolalpha << "boolalpha true: " << true << '\n' << "boolalpha false: " << false << '\n';
    cout << std::noboolalpha << "noboolalpha true: " << true << '\n' << "noboolalpha false: " << false << '\n';
}

string reverse_str(const string &s)
{

    string res;
    res.resize(s.size());

    /* use strategy of std::reverse_copy
        auto  r = res.begin();
        auto b = s.begin();
        auto e = s.end();
        while(b != e){
            *r++ = *--e;
        }
    */

    std::reverse_copy(s.begin(), s.end(), res.begin());

    return res;
}

void stringBasics()
{

    // C Language does not support strings out of the box.
    // Instead of strings, C uses an array of single characters.

    // initialize using double quotes
    // Option 1: square braces []
    // An array of chars can be initialized with a string literal. (i.e. "Hagrid")
    // the compiler adds a terminating zero character at the end of a string literal.
    // this actually is
    // char name[6] = {'M','u','r','a','t','\0'};
    // so 6 element array is used to store 5 charecter string.
    // char name[5] = "Murat"; // ERR
    // - a value of type const char[6] cannot be used to init an entity of type char[5]
    char name[] = "Hagrid"; // An array of chars can be initialized with a string literal.

    // Option 2: USING A POINTER *
    // string literals are designed to be constant, stored in read-only memory
    // const modifier means that your compiler will complain if you try to modify an array with that particular
    // variable.
    const char *surname = "Snape";

    // The new C++ standards have made it possible to use auto as a placeholder for types in various contexts and
    // let the compiler deduce the actual type.
    auto title = "Surname"; // const char* title

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

    // To use the C++ string, we must include the header file <string>
    // C++ has several different forms of initialization

    std::string s1;        // default initialization; empty string
    std::string s2{"MK"};  // introduced in C++11 as "uniform initialization", with curly braces
    std::string s3(s2);    // copy initialization
    std::string s4 = s2;   // copy initialization
    std::string s5 = "MK"; // copy initialization
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
    std::string username = "$abc123_";
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

    // substring
    // string substr (size_t pos = 0, size_t len = npos) const;
    // Returns a newly constructed string object with its value initialized to a copy of a substring of this object.
    // Pos-> represents starting index of the substring, Len->represents length of the substring
    // The first character's index is 0
    std::string s01("0123456789");
    cout << "substring      : " << s01 << endl;
    cout << "substr(0, 3)   : " << s01.substr(0, 3) << endl; // start from index 1, 3 chars ("012")
    cout << "substr(2, 3)   : " << s01.substr(2, 3) << endl; // start from index 1, 3 chars ("234")
    cout << "substr(3)      : " << s01.substr(3) << endl;    // pos=3,  ("3456789")

    // return a reverse copy
    cout << "reverse copy of: " << s01 << endl;
    cout << reverse_str(s01) << endl;
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

void f_allDefaultArgs(int x = -1, int y = -2)
{
    cout << "x: " << x << ", y: " << y << endl;
}

void f_defaultArgs(int x, int y = -1)
{
    cout << "x: " << x << ", y: " << y << endl;
}

void defaultArguments()
{
    /*
    Default Arguments
    Allow a function to be called without providing one or more trailing arguments.
    */
    printTitle("Optional Parameters");
    f_defaultArgs(1);      // x: 1, y: -1
    f_defaultArgs(11, 22); // x: 11, y: 22

    f_allDefaultArgs();       // x: -1, y: -2
    f_allDefaultArgs(11);     // x: 11, y: -2  // first default argument is assigned first.
    f_allDefaultArgs(11, 22); // x: 11, y: 22
}