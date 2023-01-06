#pragma once
#include <iostream>
#include <sstream>
#include <utility> //std::swap
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

    // return the root element (the maximum) of the heap.
    int getMax()
    {
        return (size > 0) ? arr[0] : INT_MIN;
    }

    // insert value arg as the last leaf
    void push(int arg)
    {
        if (size == capacity)
        {
            std::cout << "\nOverflow: Could not insert.\n";
            return;
        }

        // value is inserted at the end.
        int i = size++;
        arr[i] = arg;

        // check with the parent till the root
        while (i != 0 && arr[i] > arr[getParentIndex(i)])
        {
            std::swap(arr[i], arr[getParentIndex(i)]);
            i = getParentIndex(i);
        }
    }

    // delete root (the maximum) element of the heap.
    // The size of heap is decreased by 1.
    // The heap elements are reorganised accordingly after this operation.
    int pop()
    {
        if (size == 0)
            return INT_MIN;

        else if (size == 1)

            return arr[--size];

        // Storing the maximum element
        // to remove it.
        int root = arr[0];

        // bring the last leaf to root
        arr[0] = arr[--size];

        // Restore the heap property: top to bottom
        maxHeapify(0);

        return root;
    }

    void maxHeapify(int nodeIndex)
    {
        int lc_index = getLeftChildIndex(nodeIndex);
        int rc_index = getRightChildIndex(nodeIndex);
        int largest = nodeIndex;

        if (lc_index < size && arr[lc_index] > arr[nodeIndex])
            largest = lc_index;
        if (rc_index < size && arr[rc_index] > arr[largest])
            largest = rc_index;
        if (largest != nodeIndex)
        {
            std::swap(arr[nodeIndex], arr[largest]);
            maxHeapify(largest);
        }
    }

    std::string toString()
    {
        std::stringstream ss;
        ss << "{size:" << size << ", items:[";
        for (int i = 0; i < size; i++)
        {
            if (i > 0)
                ss << ", ";
            ss << arr[i];
        }
        ss << "]}";

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
