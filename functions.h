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

void typeInference();
void templateFunctions();
template <typename T> T getMax(T a, T b);

void pointerBasics();
void referenceBasics();
void pointerToAPointer();
void checkParams(mkdomain::Box *b);
int incrementV1(int arg);
void incrementV2(int *arg);
void increment_ref(int &arg);
double *createAndPassBack(int size);
int *returnTheAddressOfALocal();
void functionPointerBasics();

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