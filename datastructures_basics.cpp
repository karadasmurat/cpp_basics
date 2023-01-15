#include "functions.h"
#include "mk_datastructures.h"
#include <forward_list>
#include <iostream>
#include <stack>

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

template <typename T> void processNode(T node)
{
    cout << "Processing " << node << "\n";
}

void listBasics()
{
    printTitle("List Basics");

    /*
    A container holds a collection of objects of a specified type.
    The sequential containers let the programmer control the order (the position at which elements are put into the
    container) in which the elements are stored and accessed.

    The list and forward_list containers are designed to make it fast to add or remove an element anywhere in the
    container. In exchange, these types do not support random access to elements: We can access an element only by
    iterating through the container. Moreover, the memory overhead for these containers is often substantial, when
    compared to vector, deque , and array.

    */

    std::forward_list<int> flist = {1, 2, 3};

    while (!flist.empty())
    {

        // process first element
        processNode(flist.front());

        // done,remove the first element
        flist.pop_front();
    }
}
void stackBasics()
{
    /*
    Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out),
    where elements are inserted and extracted only from one end of the container.

    stacks are implemented as container adaptors, which are classes that use an encapsulated object of a specific
    container class as its underlying container, providing a specific set of member functions to access its elements.
    The standard container classes vector, deque and list fulfill requirements. By default, if no container class is
    specified for a particular stack class instantiation, the standard container deque is used.
    */
    printTitle("Stack Basics");

    std::stack<int> scores;
    for (int i = 0; i < 10; ++i)
    {
        // Inserts a new element at the top of the stack, above its current top element.
        // This member function effectively calls the member function push_back of the underlying container object.
        int val = i * 10;
        cout << "Insert element: " << val << "\n";
        scores.push(val);
    }

    while (!scores.empty())
    {
        // access the top element, and process it.
        processNode(scores.top());

        // done,remove top element
        // void stack::pop Removes the element on top of the stack, effectively reducing its size by one.
        // The element removed is the latest element inserted into the stack, whose value can be retrieved by calling
        // member stack::top. This member function effectively calls the member function pop_back of the underlying
        // container object.
        scores.pop();
    }
}