/* functions.h */
#pragma once

#include <vector>

#include "domain.h"
#include "enums.h"

/*

Code inside headers ordinarily should not use using declarations.  If a header has a using
 declaration, then every program that includes that header gets that same using
 declaration. As a result, a program that didn’t intend to use the specified
library name might encounter unexpected name conflicts.


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

void vectorBasics();
void mapBasics();
void iteratorBasics();

void defaultArguments();

template <typename T> void traverseVector(const std::vector<T> &vect);

int getBiggerOfTwo(int x, int y);
template <typename T> const T &getMax(const T &a, const T &b);

void modifyValue(int &arg);
void min_max(int &min, int &max, int x, int y);

void inputBasics();
void getUserInputStr();
void addInputNumbers();
int sumAllInputs();
void compareInputs();

void typeInference();
void templateFunctions();

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
void lambdaBasics();
// void incrementAllBoxes(std::vector<mk::Box> &boxes, void *f(mk::Box &));
void destructionBasics();

void enumBasics();
void printEnum(Day d);

void simplePrint(int arg);
void simplePrint(double arg);
template <typename T> void simplePrint(T *p);
void simplePrint(const int *p);
void simplePrint(const std::string &title, int arg);
void simplePrint(const std::string &title, double arg);
void simplePrint(int cnt, int *arg);
void printArray_v1(int cnt, int arg[]);
template <typename T> void simplePrint(T *begin, T *end); // print array using iterator logic
void printTitle(const std::string &title);
void simplePrint(const std::vector<int> &vect);

void searchBasics();
int binarySearch(int *arr, int cnt, int arg);
void heapBasics();
void listBasics();
void stackBasics();
template <typename T> void processNode(T node);

void exceptionBasics();
void throwAnInt();
void throwAChar();
void throwACustomException();