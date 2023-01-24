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