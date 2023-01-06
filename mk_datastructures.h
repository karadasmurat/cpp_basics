#pragma once
#include <iostream>
#include <sstream>

class MaxHeap
{
  private:
    int *arr;
    int size;
    int capacity;

  public:
    MaxHeap(int cap) : capacity(cap), size(0)
    {
        arr = new int[cap];
        std::cout << "Construct a MaxHeap\n";
    }

    // Destructors are used to release any resources allocated by the object.
    // The most common example is when the constructor uses new, and the
    // destructor uses delete.
    ~MaxHeap()
    {
        delete[] arr;
        std::cout << "Destruct a MaxHeap\n";
    };

    void insert(int arg)
    {
        arr[size++] = arg;
        // TODO heapify
    }

    std::string toString()
    {
        std::stringstream ss;
        ss << "[";
        for (int i = 0; i < size; i++)
        {
            if (i > 0)
                ss << ", ";
            ss << arr[i];
        }
        ss << "]";

        return ss.str();
    }

    int getParentIndex(int nodeIndex)
    {
        return (nodeIndex - 1) / 2;
    }

    int getLeftChildIndex(int nodeIndex)
    {
        return 2 * nodeIndex + 1;
    }

    int getRightChildIndex(int nodeIndex)
    {
        return 2 * nodeIndex + 2;
    }
};
