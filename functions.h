/* functions.h */
#pragma once

#include <vector>
#include "domain.h"
#include "enums.h"

/*
In general, avoid putting using directives in header files (*.h) because any file that includes that header
will bring everything in the namespace into scope, which can cause name hiding and name collision problems
that are very difficult to debug.
Always use fully qualified names in a header file.
*/
// using std::vector;

void helloWorld();
void variableBasics();
void constBasics();

int getBiggerOfTwo(int x, int y);
int getMax(int x, int y, int z);

void modifyValue(int &arg);
void min_max(int &min, int &max, int x, int y);

void inputBasics();
void getUserInput();
void addInputNumbers();
int sumAllInputs();
void compareInputs();

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

void enumBasics();
void printEnum(Day d);

void simplePrint(int arg);
void simplePrint(int *p);
void simplePrint(const int *p);
void simplePrint(const std::string &title, int arg);
void simplePrint(const std::string &title, double arg);