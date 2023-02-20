#include "domain.h"
#include "functions.h"
#include <iomanip> // std::setprecision
#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;
using std::vector;

void vectorBasics()
{
    printTitle("Vector Basics");

    /*
    An ArrayList could be a better name, maybe.
    Vectors are sequence containers representing arrays that can change in size.

    Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements
    can also be accessed using offsets on regular pointers to its elements, and just as efficiently as in arrays.

    However, adding or removing elements in the middle of one of these containers takes time: All the elements after
    the one inserted or removed have to be moved to maintain contiguity. Moreover, adding an element can sometimes
    require that additional storage be allocated. In that case, every element must be moved into the new storage.

    The elements are stored contiguously, which means that elements can be accessed not only through iterators, but also
    using offsets to regular pointers to elements. This means that a pointer to an element of a vector may be passed to
    any function that expects a pointer to an element of an array.

    The storage of the vector is handled automatically, being expanded as needed. Vectors usually occupy more space
    than static arrays, because more memory is allocated to handle future growth. This way a vector does not need to
    reallocate each time an element is inserted, but only when the additional memory is exhausted. (thus the container
    may have an actual capacity() greater than the storage strictly needed to contain its elements (i.e., its size())

    Libraries can implement different strategies for growth to balance between memory usage and reallocations, but
    in any case, reallocations should only happen at "logarithmically growing intervals of size" so that the insertion
    of individual elements at the end of the vector can be provided with "amortized" constant time complexity (see
    push_back).

    Compared to arrays, vectors consume more memory in exchange for the ability to manage storage and grow
    dynamically in an efficient way. Extra memory can be returned to the system via a call to shrink_to_fit().


    The complexity (efficiency) of common operations on vectors is as follows:

        * Random access - constant O(1)
        * Insertion or removal of elements at the end - "amortized" constant O(1)
            (each time the array is full, allocate new space, copy your data into the new region, and free old space.)
        * Insertion or removal of elements - linear in the distance to the end of the vector O(n) (shifting)

    Compared to the other dynamic sequence containers (deques, lists and forward_lists), vectors are very efficient
    accessing its elements (just like arrays) and relatively efficient adding or removing elements from its end. For
    operations that involve inserting or removing elements at positions other than the end, they perform worse than the
    others, and have less consistent iterators and references than lists and forward_lists. A vector is the preferred
    container for a sequence when random-access performance is at a premium.


    Reallocations are usually costly operations in terms of performance. The reserve() function can be used to eliminate
    reallocations if the number of elements is known beforehand.

    When we use container operations that add or remove elements, it is essential to remember that these operations can
    invalidate iterators, pointers, or references to elements in the container.

    Note. vector is a template, not a type. We can define vectors to hold objects of most any type.
    Types generated from vector must include the element type, for example, vector<int>

    When we call a push or insert member, we pass objects of the element type and those objects are copied into the
    container. When we call an "emplace" member, we pass arguments to a constructor for the element type. The emplace
    members use those arguments to construct an element directly in space managed by the container.

    The emplace functions construct elements in the container.
    The arguments to these functions must match a constructor for the element type.
    */

    // Default initialize a vector, which creates an empty vector of the specified type
    vector<int> v;

    if (v.empty())
        cout << "Default initialized vector is empty.\n";

    cout << " capacity() : " << v.capacity() << "\n"; // 0
    cout << " size()     : " << v.size() << endl;     // 0

    // The call to push_back creates a new element at the end of container, increasing the size of container by 1.
    // The value of that element is a "copy" of the element, not the element itself.
    v.push_back(1);

    cout << "push_back(1);\n";
    cout << " capacity() : " << v.capacity() << "\n"; // 1
    cout << " size()     : " << v.size() << endl;     // 1

    cout << "For i = 2 To 100 push_back(i);\n";
    int prev_capacity = v.capacity();
    for (int i = 2; i < 100; i++)
    {
        v.push_back(i);
        if (v.capacity() - prev_capacity > 1)
            cout << "Reallocation - capacity is now " << v.capacity() << " from " << prev_capacity
                 << ", size: " << v.size() << "\n";

        prev_capacity = v.capacity();
    }

    // Accessing Elements
    // You can refer to an element by its index (subscript)
    // check that there are elements before dereferencing an iterator or calling front or back
    if (!v.empty())
    {
        cout << " v[0]: " << v[0] << endl;
        cout << " front(): " << v.front() << endl;
        cout << " at(0): " << v.at(0) << endl;
        cout << " Last element: " << v[v.size() - 1] << endl;
        cout << " back(): " << v.back() << endl;
    }

    // fill constructors
    // Constructs a container with n elements. Each element is a copy of val(if provided)
    vector<int> vect2(5); // create a vector of 5 integers with default value of 0
    simplePrint(vect2);

    std::vector<int> vect3(5, 10); // create a vector of 5 integers with value 10
    simplePrint(vect3);

    // initializer list
    vector<double> ages = {0.33, 22.0, 27.2};
    ages[2] = 22.2;

    // We can use the constructor that takes a size argument if the element type is
    // a built-in type or a class type that has a default constructor
    vector<mk::Entity> entities(5); // fill with objects, default constructor
    cout << "entities.size() : " << entities.size() << endl;

    vector<mk::Entity> entities2;
    entities2.reserve(2);

    cout << "Create and push_back()\n";
    mk::Entity e1{"E1", 1};  // initialize an Entity object
    entities2.push_back(e1); // copy(!) existing object into the container

    cout << "emplace_back()\n";
    // When we call an "emplace" member, we pass arguments to a constructor for the element type.
    // The emplace members use those arguments to construct an element directly in space managed by the container.
    entities2.emplace_back("E2", 2);

    vector<mk::Box> boxes2; // default initialize, empty vector
    boxes2.reserve(5);      // prevent reallocation if you know the size, ie., capacity 0 -> 1 -> 2 -> 4 ..
    cout << "boxes2.capacity(): " << boxes2.capacity() << endl;
    cout << "boxes2.size(): " << boxes2.size() << endl;

    traverseVector(entities);

    // The container equality operators use the element’s == operator, and the relational operators use the
    // element’s < operator. If the element type doesn’t support the required operator, then we cannot use the
    // corresponding operations on containers holding that type.
    if (entities == entities2)
        cout << "Two vectors are equal." << endl;
    else
        cout << "Two vectors are not equal" << endl;

    // No push_front() on vector but we can insert before begin()
    // warning : inserting anywhere but at the end of a vector might be slow
    vector<string> svec;
    svec.push_back("10");
    svec.push_back("20");
    svec.push_back("30");

    // like insert an element at svec[0]="0" and move the remaining:
    svec.insert(svec.begin(), "0!"); //[0!, 10, 20, 30]

    // like insert an element at svec[2]="15" and move the remaining:
    svec.insert(svec.begin() + 2, "15!"); // [0!, 10, 15!, 20, 30]
    traverseVector(svec);

    // insert last element of svec into the beginning of svec2
    vector<string> svec2 = {"ten", "eleven"};
    svec2.insert(svec2.begin(), svec.end() - 1, svec.end()); // [Three, ten, eleven]
    traverseVector(svec2);

    vector<string> va = {"A0", "A1", "A2"};
    vector<string> vb = {"B", "B1", "B"};

    cout << "Append vector vb to va:" << endl;
    va.insert(va.end(), vb.begin(), vb.end()); // [A0, A1, A2, B, B1, B]
    traverseVector(va);

    cout << "Erase element at index 2:" << endl;
    va.erase(va.begin() + 2); // [A0, A1, B, B1, B]
    traverseVector(va);

    cout << "Find and erase element 'B':" << endl;
    auto it = find(va.begin(), va.end(), "B");
    if (it != va.end())
        va.erase(it); // if found, delete element   [A0, A1, B1, B]
    else
        cout << "Element not found." << endl;
    traverseVector(va);

    // Almost any type can be used as the element type of a sequential container.
    vector<vector<string>> lines; // vector of vectors
}
template <typename T> void traverseVector(const vector<T> &vect)
{
    printTitle("Traverse a Vector");

    cout << "index[";
    // traverse using index
    for (int i = 0; i < vect.size(); ++i)
    {
        if (i != 0)
            cout << ", ";

        cout << vect[i];
    }
    cout << "]" << endl;

    cout << "iterator[";
    // traverse using iterator
    int comma = 0;
    for (auto it = vect.begin(); it != vect.end(); ++it)
    {
        if (comma++ != 0)
            cout << ", ";

        cout << *it;
    }
    cout << "]" << endl;

    cout << "foreach[";
    // traverse using for each
    comma = 0;
    for (const auto &item : vect)
    {
        if (comma++ != 0)
            cout << ", ";

        cout << item;
    }
    cout << "]" << endl;
}

void iteratorBasics()
{

    /*
Like pointers, iterators give us indirect access to an object.
Unlike pointers, we do not use the address-of operator to obtain an iterator. Instead, types that have iterators have
members that return iterators. In particular, the begin member returns an iterator that denotes the first element (or
first character), if there is one.

The iterator returned by end() is an iterator positioned “one past the end” of the associated container (or string).
If the container is empty, the iterators returned by begin and end are equal—they are "both off-the-end" iterators.

The library uses left-inclusive ranges because such ranges have three convenient properties.
Assuming begin and end denote a valid iterator range, then
    * If begin equals end, the range is empty
    * If begin is not equal to end, there is at least one element in the range,
      and begin refers to the first element in that range
    * We can increment begin some number of times until begin == end

    while (begin != end) {
        *begin =  val;    // ok: range isn't empty so begin denotes an element
        ++begin;          // advance the iterator to get the next element
    }

If the object is const, then begin and end return a const_iterator.
if the object is not const, they return iterator.

Any operation, such as push_back, that changes the size of a vector potentially invalidates all iterators into that
vector.

*/
    printTitle("Iterator Basics");

    int numArr[] = {10, 20, 30, 40, 50};
    vector<int> numVect{100, 200, 300, 400, 500};

    cout << "Iterate an array using std::begin() and std::end() and dereferencing\n";

    // In general, we do not know (or care about) the precise type that an iterator has.
    // In this example, we used auto to define it
    // Iterators use the increment (++) operator to move from one element to the next.
    for (auto it = std::begin(numArr); it != std::end(numArr); it++)
    {
        // As with pointers, we can dereference an iterator to obtain the element denoted by an iterator.
        // Note that “Dereferencing an invalid iterator or an off-the-end iterator has undefined behavior.
        cout << *it << " ";
    }

    cout << "\nIterate a vector using vector::begin() and vector::end() and dereferencing\n";
    for (auto it = numVect.begin(); it != numVect.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<mk::Entity> entities;
    entities.reserve(3); // prevent reallocation if you know the size, ie., capacity 0 -> 1 -> 2 -> 4 ..
    entities.emplace_back(mk::Entity("E1", 1));
    entities.emplace_back(mk::Entity("E2", 2));
    entities.emplace_back(mk::Entity("E3", 3));

    vector<mk::Entity>::const_iterator it = entities.cbegin();
    while (it != entities.cend())
    {
        if (!(*it).getName().empty())
        {
            cout << (*it).getName(); // parantheses are necessary here.
            cout << it->getName(); // The arrow operator combines dereference and member access into a single operation
        }

        ++it;
    }

    // compute an iterator to the element closest to the midpoint
    // We can add (or subtract) an integral value and an iterator.
    auto mid = entities.begin() + (entities.size() / 2);
    cout << "\nvector midpoint: " << mid->getName() << endl;

    // We can also subtract two iterators
    // so long as they refer to elements in, or one off the end of, the same vector or string.
    std::string text = "abcdefghi";
    auto beg = text.begin(), end = text.end();
    auto midpoint = beg + ((end - beg) / 2); // original midpoint
    cout << "string midpoint: " << *midpoint << endl;

    // begin is array_name, or &array_name[0]
    // end is 1 past last, which is array_name+SIZE, or &array_name[SIZE]
    // array size is: end - begin (index starts at 0)
    std::sort(numArr, numArr + 5);
    // TODO undefined symbols
    simplePrint(numArr, numArr + 5);

    // If the object is const, then begin and end return a const_iterator.
    const vector<int> cv;
    auto it2 = cv.begin(); // it2 has type vector<int>::const_iterator

    // When write access is not needed, use cbegin and cend
    vector<double> vect3;
    auto it3 = vect3.cbegin(); // it3 has type vector<double>::const_iterator
}

void mapBasics()
{

    /*
    A map is a collection of key–value pairs.

    For example, each pair might contain a person’s name as a key and a phone number as its value. We speak of such a
    data structure as “mapping names to phone numbers.”

    The map type is often referred to as an associative array. An associative array is like a “normal” array except that
    its subscripts don’t have to be integers. Values in a map are found by a key rather than by their position.

    Like the sequential containers, the associative containers are templates. To define a map, we must specify both the
    key and value types. The keys in a map or a set must be unique; there can be only one element with a given key.

    For the ordered containers (map, multimap) — the key type must define a way to compare the elements.
    By default, the library uses the < operator for the key type to compare the keys.

    The pair Type
    A pair, which is defined in the utility header, holds two data members. Unlike other library types, the data members
    of pair are public. These members are named first and second, respectively.

    Associative Container Iterators
    When we dereference an iterator, we get a reference to a value of the container’s value_type. In the case of map,
    the value_type is a pair in which first holds the const key and second holds the value. The associative container
    iterators are bidirectional.
    */

    printTitle("Map Basics");

    // create a pair named author, initialized with the values "James" and "Joyce".
    pair<string, string> author{"James", "Joyce"};

    cout << author.first << " " << author.second << endl;

    /*
    make_pair template function constructs a pair object. The template types can be implicitly deduced from the
    arguments passed

    template <class T1, class T2>  pair<T1,T2> make_pair (T1 x, T2 y);
    */
    auto myPair = std::make_pair("MK", 333);

    cout << typeid(myPair).name() << ", " << myPair.first << ", " << myPair.second << endl;

    // default constructor creates an empty container
    map<string, size_t> w_cnt;

    // insert element
    w_cnt.insert({"A", 1});
    w_cnt.insert(std::make_pair("B", 2));
    w_cnt.insert(pair<string, size_t>{"C", 3});

    // The map and unordered_map containers provide the subscript operator and a corresponding at function
    // insert a value - initialized element with key D; then assign 4 to its value
    w_cnt["D"] = 4;

    // Accessing elements
    cout << ++w_cnt["D"] << endl; // fetch the element indexed by Anna and add 1 to it (5)
    // at function Returns a reference to the mapped value of the element identified with key k.
    cout << w_cnt.at("A") << endl;

    // get an iterator to an element in word_count
    auto it = w_cnt.end();
    cout << (--it)->first << ": " << it->second << endl;

    // erase on a key returns the number of elements removed
    string removal_word{"B"};
    if (w_cnt.erase(removal_word))
        cout << "ok: " << removal_word << " removed\n";
    else
        cout << "oops: " << removal_word << " not found!\n";
}

void setBasics()
{

    printTitle("Set Basics");

    /*
    A set is simply a collection of keys.
    A set is most useful when we simply want to know whether a value is present.

    */
}