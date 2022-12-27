#include <iostream>
#include "functions.h"

using namespace std;

void simplePrint(int arg)
{
  cout << arg << endl;
}

void simplePrint(int *p)
{
  cout << "ptr: " << p
       << ", *ptr: " << *p << endl;
}

void simplePrint(const int *p)
{
  cout << "ptr: " << p
       << ", *ptr: " << *p << endl;
}

void simplePrint(const std::string &title, int arg)
{
  cout << title << ": " << arg << endl;
}
void simplePrint(const std::string &title, double arg)
{
  cout << title << ": " << arg << endl;
}

void variableBasics()
{

  /*
      In a C++ program, a name starts with a letter and contains only letters, digits, and underscores.
      Language reserves many (about 85) names as “keywords.”
      You can’t use those to name your variables, types, functions, etc.

      Our “house style” is to use underscores to separate words in an identifier,
      such as element_count, rather than alternatives, such as elementCount and ElementCount.

      We use an initial capital letter for types we define, such as Square and Graph.
      The C++ language and standard library don’t use the initial-capital-letter style,
      so it’s int rather than Int and string rather than String.
      Thus, our convention helps to minimize confusion between our types and the standard ones.

  */
  // C++ provides a rather large number of types. However, you can write perfectly good programs using only five of those:

  /*
    Initialization is not assignment.

    It is tempting to think of initialization as a form of assignment, but initialization and assignment are different operations in C++.
    This concept is particularly confusing because in many languages the distinction is irrelevant and can be ignored.
    Initialization happens when a variable is given a value when it is created.
    Assignment obliterates an object’s current value and replaces that value with a new one.
    The generalized use of curly braces for initialization was introduced as part of the new standard.
    Most classes let us define objects without explicit initializers.
    Such classes supply an appropriate default value for us. For example, as we’ve just seen, the library string class says that if we do not supply an initializer, then the resulting string
    is the empty string

    std::string str;  // implicitly initialized to the empty string
*/

  // In C and C++, local variables aren't initialized by default.
  // Uninitialized variables can contain any value, and their use leads to undefined behavior.
  int a, b, c; // Danger!
  a = b + c;
  simplePrint("a", a); // i.e 26677

  int y{2};                    // initializer using the {} syntax - define and immediately initialize with 2
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
  They differ in having const as part of their type and requiring an initializer.
  */
  // It is almost always a good idea to initialize "variables" also; an uninitialized variable is a recipe for obscure bugs.

  const int x1 = 7;
  const int x2{9}; // initializer using the {} syntax

  // TODO
  // sizes();
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
}

void inputBasics()
{

  // getUserInput();
  addInputNumbers();
  // sumAllInputs();
  // compareInputs();
}
void getUserInput()
{

  // read from s into x
  // s >> x

  // write x to s
  // s << x

  string name;
  cout << "Please enter your name: ";

  // A string read using >> is (by default) terminated by whitespace; that is,
  // it reads a single word. whitespace by default is ignored by >>
  cin >> name; // read characters into name

  cout << "Hello, " << name << endl;
}
int sumAllInputs()
{

  int sum{0}, value{0};
  cout << "Enter numbers "
       << "\n[Q]uit and display the sum >";

  // read until end-of-file, calculating a running total of all values read (Win: Ctrl-Z, Linux: Ctrl-D)
  // When we use an istream as a condition, the effect is to test the state of the stream. If the stream is valid—that is, if the stream hasn’t encountered an error—then the test succeeds. An istream becomes invalid when we hit end-of-file or encounter an invalid input, such as reading a value that is not an integer.
  while (std::cin >> value)
  {
    sum += value;
    std::cout << "running sum: "
              << sum << std::endl;
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

  cout << "Enter two integers"
       << "\nPress | to exit): ";
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