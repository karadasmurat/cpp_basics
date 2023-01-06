#include "mk_datastructures.h"
#include <iostream>

using std::cout;

void heapBasics()
{
    cout << "Heap Basics\n=============\n";
    MaxHeap maxheap(15);
    maxheap.insert(100);
    maxheap.insert(90);
    maxheap.insert(80);
    cout << maxheap.toString() << std::endl;
    cout << "Parent of [2]: " << maxheap.getParentIndex(2) << std::endl;
    cout << "Left Child of [0]: " << maxheap.getLeftChildIndex(0) << std::endl;
    cout << "Right Child of [0]: " << maxheap.getRightChildIndex(0) << std::endl;
}