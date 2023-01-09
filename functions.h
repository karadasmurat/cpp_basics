/* functions.h */
#pragma once

#include <vector>

#include "domain.h"
#include "enums.h"

/*

“Code inside headers ordinarily should not use using
 declarations.  If a header has a using
 declaration, then every program that includes that header gets that same using
 declaration. As a result, a program that didn’t intend to use the specified
library name might encounter unexpected name conflicts.”

Excerpt From
C++ Primer, 5/e
Lippman, Stanley B.
This material may be protected by copyright.


In general, avoid putting using directives in header files (*.h)
The reason is that the contents of a header are copied into the including
program’s text: If a header has a using declaration, then every program that
includes that header gets that same using declaration. As a result, a program
that didn’t intend to use the specified library name might encounter unexpected
name conflicts.

Always use fully qualified names in a header file.
*/
// using std::vector;

void helloWorld();
void variableBasics();
void stringBasics();
void arrayBasics();
void constBasics();

int getBiggerOfTwo(int x, int y);
int getMax(int x, int y, int z);

void modifyValue(int &arg);
void min_max(int &min, int &max, int x, int y);

void inputBasics();
void getUserInputStr();
void addInputNumbers();
int sumAllInputs();
void compareInputs();
void iteratorBasics();

void typeInference();
void templateFunctions();
template <typename T> T getMax(T a, T b);

void pointerBasics();
void referenceBasics();
void mayModifyArgument(mk::Box &b);
void doNotModifyArgument(const mk::Box &b);
void pointerToAPointer();
void checkParams(mk::Box *b);
int increment(int arg);
void increment_ptr(int *ptr);
void increment_ref(int &ref);
void print_refToConst(const std::string &s);
void print_refToNonConst(std::string &s);
double *createAndPassBack(int size);
int *returnTheAddressOfALocal();
void functionPointerBasics();

void incrementAllBoxes(std::vector<mk::Box> &boxes, void *f(mk::Box &));
void destructionBasics();

void enumBasics();
void printEnum(Day d);

void simplePrint(int arg);
void simplePrint(double arg);
void simplePrint(int *p);
void simplePrint(const int *p);
void simplePrint(const std::string &title, int arg);
void simplePrint(const std::string &title, double arg);

void printArray_v1(int cnt, int arg[]);
void printArray_v2(int cnt, int *arg);

void searchBasics();
int binarySearch(int *arr, int cnt, int arg);
void heapBasics();

void exceptionBasics();
void throwAnInt();
void throwAChar();
void throwACustomException();