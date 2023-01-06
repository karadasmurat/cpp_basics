#include "functions.h"

using std::cout;
using std::endl;

int binarySearch(int *arr, int cnt, int arg) {
  cout << "binary search" << endl;
  int low = 0;
  int high = cnt - 1;

  while (low <= high) {

    // check middle
    int middle = (high + low) / 2;

    if (arr[middle] == arg) {
      cout << "Found " << arg << " at index " << middle << endl;
      return middle;
    } else if (arr[middle] > arg)
      // search lower half
      high = middle - 1;

    else
      // search upper half
      low = middle + 1;
  }

  cout << arg << " not found." << endl;
  return -1;
}