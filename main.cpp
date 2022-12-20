/*
$ g++ -std=c++20 main.cpp helloworld.cpp domain.cpp -o main && ./main
*/

#include <iostream>
#include "functions.h"
#include "domain.h"


using namespace std;
using namespace mkdomain;


void classBasics();
void inheritanceBasics();

class A{

  public:
    int id;
    
};

class B{

  public:
    int id;

    B(){
        cout << "Hello world, this is B!" << endl;
    }
    
};


int main(){

    // cout << "Hello, there!" << endl;
    helloWorld();

    cout << "getBiggerOfTwo(44, 55): " << getBiggerOfTwo(44, 55) << endl;

    cout << "getMax(33, 55, 44): " << getMax(33, 55, 44) << endl;
    
    addInputNumbers();
    classBasics();
    // inheritanceBasics();


    return 0;
}

void classBasics(){
    A a01;              // Class A does not have any explicit constructors, default is executed.
    a01.id = 1;         // public

    B b01;              // Class B defines a no parameter constructor, it is executed. 

    Entity e;
}

void inheritanceBasics(){

    // Vehicle vehicle1;   // Constructor with one optional parameter 
    // vehicle1.move();

    // // Create object of the Bicycle class
    // Bicycle bicycle1 = Bicycle(BicycleType::City);

    // // Calling members of the base class
    // bicycle1.move();

}

void addInputNumbers(){

    int x, y;

    cout << "Enter 2 numbers, seperated by space: ";
    cin >> x >> y;

    // cout << "Enter second number: ";
    // cin >> y;

    cout << x << " + " << y << " = " << x+y << endl;
    //return x+y;
}

int getBiggerOfTwo(int x, int y){
    return x > y ? x : y;
}

int getMax(int x, int y, int z){

    int max = x;
    if(y > max) max = y;
    if(z > max) max = z;

    return max;
}