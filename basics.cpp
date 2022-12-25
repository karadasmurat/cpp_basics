#include <iostream>
#include "functions.h"

using namespace std;

void simplePrint(int arg)
{
  cout << arg << endl;
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

  // int for integers
  int number_of_steps = 39; // initializer using the = syntax
  int y{2};                 // initializer using the {} syntax - define and immediately initialize with 2

  // double (default) and float for floating-point numbers
  double flying_time(3.5);
  float driving_time = 4.0f;

  // char: an individual character enclosed in single quotes
  char decimal_point = '.';

  // string: a sequence of characters delimited by double quotes
  string name = "Annemarie";

  // bool for logical variables. either true or false
  bool tap_on = true;

  // string name2 = 39; // error: 39 isn’t a string
  // int number_of_steps = "Annemarie";     // error: “Annemarie” is not an int”

  // implicit conversion from 'double' to 'int'
  int num = 9.99;
  cout << "int num = 9.99 -> " << num << endl;

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