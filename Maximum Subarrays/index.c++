#include <iostream>
using namespace std;

// Brute Force approach
void max_subarrays(int arr[], int size) {
  // sub arrays are continous

  // 1st loop: To decide a start
  for (int st = 0; st < size; st++) {
    cout << "Sub Arrays starting from index:" + to_string(st) << endl;
    // 2nd loop: To update the initial position of end
    for (int end = st; end < size; end++) {
      // 3rd loop: To print values between the range of st and end
      for (int i = st; i <= end; i++) {
        cout << arr[i];
      }
      cout << " ";
    }
    cout << endl;
  }
}

int max_subarray_sum(int arr[], int size) {}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int st = 0;
  int size = sizeof(arr) / sizeof(arr[0]);
  max_subarrays(arr, size);

  return 0;
}
