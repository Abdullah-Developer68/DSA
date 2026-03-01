#include <iostream>
using namespace std;

void max_subarrays(int arr[], int size) {
  // sub arrays are continous

  for (int st = 0; st < size; size++) {
    for (int end = st; end < size; size++) {
      cout << "This is the" + to_string(st) + "subarray:" << endl;
      cout << arr[st] << " ";
    }
    cout << endl;
  }
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int st = 0;
  int size = sizeof(arr) / sizeof(arr[0]);
  max_subarrays(arr, size);

  return 0;
}
