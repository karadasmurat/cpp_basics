#include <iostream>

using namespace std;

int addInputNumbers();
int getBiggerOfTwo(int x, int y);
int getMax(int x, int y, int z);

int main(){

    cout << "Hello, there!" << endl;

    cout << "getBiggerOfTwo(44, 55): " << getBiggerOfTwo(44, 55) << endl;

    cout << "getMax(33, 55, 44): " << getMax(33, 55, 44) << endl;
    
    // cout << addInputNumbers() << endl;

    return 0;
}

int addInputNumbers(){

    int x, y;

    cout << "Enter first number: ";
    cin >> x;

    cout << "Enter second number: ";
    cin >> y;

    return x+y;
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