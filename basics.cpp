#include "domain.h"
#include "functions.h"
#include <iomanip> // std::setprecision
#include <iostream>

using namespace std;

void simplePrint(int arg)
{
    cout << arg << endl;
}

void simplePrint(double arg)
{
    std::cout << std::fixed << std::setprecision(2) << arg << endl;
}

void simplePrint(int *p)
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
template <typename T> T getMax(T a, T b)
{
    return a > b ? a : b;
}

void templateFunctions()
{

    int x{10}, y{20};
    double d1{10.0}, d2{20.0};

    int max_i = getMax(x, y);
    double max_d = getMax(d1, d2);

    simplePrint(max_i);
    simplePrint(max_d);
}

int getBiggerOfTwo(int x, int y)
{
    return x > y ? x : y;
}

int getMax(int x, int y, int z)
{

    int max = x;
    if (y > max)
        max = y;
    if (z > max)
        max = z;

    return max;
}

void iteratorBasics()
{
    cout << "Iterator Basics\n";

    int numArr[] = {10, 20, 30, 40, 50};
    vector<int> numVect{100, 200, 300, 400, 500};

    cout << "Iterate an array using std::begin() and std::end() and dereferencing\n";
    for (auto it = begin(numArr); it != end(numArr); it++)
    {
        cout << *it << " ";
    }

    cout << "\nIterate a vector using vector::begin() and vector::end() and dereferencing\n";
    for (auto it = numVect.begin(); it != numVect.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}