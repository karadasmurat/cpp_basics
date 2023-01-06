#include "functions.h"

using std::cout;
using std::endl;

void searchBasics()
{
    const int N = 9;
    int key = 10;
    int searchBase[N] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int found = binarySearch(searchBase, N, key);
}

int binarySearch(int *arr, int cnt, int q)
{
    cout << "binary search" << endl;
    int low = 0;
    int high = cnt - 1;

    while (low <= high)
    {
        // check middle
        int middle = (high + low) / 2;
        if (arr[middle] == q)
        {
            cout << "Found " << q << " at index " << middle << endl;
            return middle;
        }
        else if (q < arr[middle])
            // search lower half
            high = middle - 1;

        else
            // search upper half
            low = middle + 1;
    }

    cout << q << " not found." << endl;
    return -1;
}