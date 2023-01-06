#include "mk_datastructures.h"
#include <iostream>

using std::cout;

void heapBasics()
{
    cout << "Heap Basics\n=============\n";
    MaxHeap maxheap(15);
    cout << maxheap.toString() << std::endl;

    maxheap.push(50); // [50]
    cout << maxheap.toString() << std::endl;

    maxheap.push(60); // [60, 50]
    maxheap.push(70); // [70, 50, 60]
    maxheap.push(80); // [80, 70, 60, 50]
    cout << maxheap.toString() << std::endl;

    int root = maxheap.pop(); // pop: 80 remaining: {size:3, items:[70, 50, 60]};
                              // this is different than just removing index[0] and moving the rest one left!
    cout << "pop: " << root << " remaining: " << maxheap.toString() << std::endl;

    root = maxheap.pop(); // pop: 70 remaining: {size:2, items:[60, 50]}
    cout << "pop: " << root << " remaining: " << maxheap.toString() << std::endl;
    root = maxheap.pop(); // pop: 60 remaining: {size:1, items:[50]}
    cout << "pop: " << root << " remaining: " << maxheap.toString() << std::endl;
    root = maxheap.pop(); // pop: 50 remaining: {size:0, items:[]}
    cout << "pop: " << root << " remaining: " << maxheap.toString() << std::endl;

    root = maxheap.pop(); // pop: -2147483648 remaining: {size:0, items:[]}
    cout << "pop: " << root << " remaining: " << maxheap.toString() << std::endl;

    maxheap.push(333); // [50]
    cout << maxheap.toString() << std::endl;
}