/* functions.h */
#if !defined(_FUNC_H_)

#define _FUNC_H_
#include "enums.h"
void helloWorld();
void variableBasics();

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
int incrementV1(int arg);
void incrementV2(int *arg);
void incrementV3(int &arg);
double *createAndPassBack(int size);
int *returnTheAddressOfALocal();

void enumBasics();
void printEnum(Day d);

#endif