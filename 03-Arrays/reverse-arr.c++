#include <iostream>
using namespace std;

/*
 * Program: Array Reversal using Two-Pointer Approach
 * 
 * This program demonstrates reversing an array in place using two pointers.
 * The approach works for arrays of even or odd length by swapping elements
 * from the start and end, moving towards the center.
 */

void reverse_arr(int arr[], int length) {
  int start = 0;
  int end = length - 1;

  while (start < end) {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}

int main() {
  int arr[] = {4, 2, 7, 8, 1, 2, 5};

  /*
   * Calculating Array Length:
   * - In C++, raw arrays don't have built-in length methods.
   * - You cannot calculate size using a loop because there's no end marker
   *   (e.g., accessing beyond bounds leads to undefined behavior like garbage values).
   * - Reliable method: Use sizeof(arr) / sizeof(arr[0])
   *   - sizeof(arr): Total bytes of the array (e.g., 7 ints * 4 bytes/int = 28 bytes)
   *   - sizeof(arr[0]): Bytes per element (4 bytes for int)
   *   - Result: 28 / 4 = 7 (the length)
   * - Note: This only works in the scope where the array is defined.
   *   It fails in functions because arrays decay to pointers.
   */
  int length = sizeof(arr) / sizeof(arr[0]);
  cout << "Length of arr: " << length << endl;

  reverse_arr(arr, length);
  for (int i = 0; i < length; i++) {
    cout << arr[i];
  }
  return 0;
}
