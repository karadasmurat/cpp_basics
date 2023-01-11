#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

bool is_negative(int i)
{
    return i < 0;
}

void lambdaBasics()
{
    // Assign the lambda expression that squares a number to an auto variable.
    auto f = [](int x) { return x * x; }; // int f(int x)

    cout << f(5) << endl;

    // Class template std::function is a general-purpose polymorphic function wrapper.
    // std::function< void() > takes zero arguments and returns nothing.
    // std::function< double(int, int) > takes two int arguments and returns double.

    // store a free function
    std::function<bool(int)> f_neg = is_negative;
    cout << std::boolalpha << "f_neg(-9): " << f_neg(-9) << endl; // boolalpha flag

    // store a lambda
    // Assign lambda expression that adds two numbers to a function object.
    std::function<int(int, int)> add = [](int x, int y) { return x + y; };
    cout << add(11, 22) << endl;

    vector<int> nums = {3, 7, 42, -1, 99};

    // Use a free function as predicate, to find the first even number in the list.
    auto res = std::find_if(nums.begin(), nums.end(), [](int x) { return x % 2 == 0; });

    // Print the result.
    if (res != nums.end())
    {
        cout << "The first even number: " << *res << endl;
    }
    else
    {
        cout << "No even numbers." << endl;
    }

    // Use a free function as predicate
    auto neg = std::find_if(nums.begin(), nums.end(), is_negative);

    if (neg != nums.end())
    {
        cout << "The first negative number: " << *neg << endl;
    }
    else
    {
        cout << "No negative numbers." << endl;
    }
}