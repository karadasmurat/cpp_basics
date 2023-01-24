#include <iostream>

/*
Write a program that prints the following figure.
#
##
###
##
#

*/

void exercise1(int middle)
{

    // i: 1 to n
    // j: 1 to i
    for (int i = 1; i < middle; i++)
    {
        for (int j = 1; j <= i; j++)
            std::cout << "#";

        std::cout << std::endl;
    }
    // middle
    for (int i = 0; i < middle; i++)
        std::cout << "#";
    std::cout << std::endl;

    // down.
    for (int i = middle - 1; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
            std::cout << "#";

        std::cout << std::endl;
    }
}

/*
Write a program that calculates and prints the area and the perimeter of a square
when the size of one side is given.
*/

class Square
{
    int side;

  public:
    Square(int side) : side(side)
    {
    }

    int perimeter() const
    {
        return 4 * side;
    }

    int area() const
    {
        return side * side;
    }

    int get_side() const
    {
        return side;
    }
};

void exercise2(int side)
{
    Square square{side};
    std::cout << "Square w/ side: " << square.get_side() << "\n";
    std::cout << "Perimeter     : " << square.perimeter() << "\n";
    std::cout << "Area          : " << square.area() << "\n";
}

/*
implement a program that, given an integer, extracts and prints the first (rightmost) digit.
*/

int exercise3(int arg)
{
    int rightmost_digit = arg % 10;
    std::cout << "Number: " << arg << " Rightmost digit: " << rightmost_digit << std::endl;
    return rightmost_digit;
}

/*
Find how many hours, minutes, and second are in a time duration given in seconds.
*/

void exercise4(unsigned long timeInSeconds)
{
    int secInAMinute = 60;
    int secInAnHour = 3600;

    unsigned long hours = timeInSeconds / secInAnHour;
    unsigned long minutes = (timeInSeconds - hours * secInAnHour) / secInAMinute;
    unsigned long seconds = timeInSeconds - hours * secInAnHour - minutes * secInAMinute;

    std::cout << timeInSeconds << " seconds is " << hours << " hour(s), " << minutes << " minute(s), and " << seconds
              << " second(s)." << std::endl;
}

/*
Find absolute value of an integer
*/

int absolute(int arg)
{
    return (arg > 0 ? arg : -arg);
}

/*
calculate the weekly gross earnings for an employee. If the employee works more than 40 hours during the week, the
overtime pay rate for the extra hours is 130 percent of the base pay rate, 10usd/hour.
*/

double earnings(double workHours)
{
    const double baseRate = 10.0;
    double earnings = 0.0;
    if (workHours < 40)
        earnings = workHours * baseRate;
    else
        earnings = 40 * baseRate + (workHours - 40) * baseRate * 1.3;

    return earnings;
}
/*
Find the bigger of two integers.
*/

int getBiggerOfTwo(int x, int y)
{
    return x > y ? x : y;
}

/*
find the score of a student in a class based on the result of three tests. The professor believes that the student’s
score should be the average of the maximum and minimum of the three scores.
*/

int getScore(double test1, double test2, double test3)
{
    double max = test1;
    if (test2 > max)
        max = test2;
    if (test3 > max)
        max = test3;

    double min = test1;
    if (test2 < min)
        min = test2;
    if (test3 < min)
        min = test3;

    return (max + min) / 2;
}

/*
Write a program that, given the quantity and unit price of an item, calculates the total price after the discount:

Quantity    Discount
1  to 9     0%
10 to 49    3%
50 to 99    5%
100+        10%
*/

double getDiscountRate(int quantity)
{
    double discount = 0.0;
    if (quantity >= 100)
        discount = 0.1;
    else if (quantity >= 50)
        discount = 0.05;
    else if (quantity >= 10)
        discount = 0.03;

    return discount;
}

double totalPrice(int quantity, double price)
{
    return quantity * price * (1.0 - getDiscountRate(quantity));
}

/*
Find the factorial
Factorial is a special kind of multiplication in which the numbers to be multiplied are positive integers (from 1 to the
factorial number).
*/

unsigned long factorial(long n)
{
    if (n < 0)
        throw std::invalid_argument("The argument cannot be negative");

    if (n == 0)
        return 1L;

    unsigned long fact = 1;
    for (size_t i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}
