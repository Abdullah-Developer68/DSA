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

int max_subarray_sum(int arr[], int size) {
  // if we use 0 then if all elements are -ve then we will get 0
  // but to get the least -ve sum we need to use INT_MIN;
  int max_sum = INT_MIN;

  // 3 loops are not required because the previous elements appear in the
  // following subarrays as well, and only 1 last digit is different every
  // time. Hence, we calculate the sum of the previous digits and then
  // simply add the new one into it.
  for (int st = 0; st < size; st++) {
    int curr_subarr_sum = 0;
    for (int end = st; end < size; end++) {
      curr_subarr_sum += arr[end];
      // update max_sum
      if (curr_subarr_sum > max_sum) {
        max_sum = curr_subarr_sum;
      }
    }
  }
  return max_sum;
}

// calculating max_sum array using kadans algorithm (most optimized way to find
// max sum). This algorithm says that when we get curr_sum -ve reset it to 0.
// Time complexity is O(n) and space complexity is O(1)
// This is a type of DP problem
int kadans_algo(int arr[], int size) {
  int curr_sum = 0;
  int max_sum = INT_MIN;
  for (int i = 0; i < size; i++) {
    curr_sum += arr[i];
    if (curr_sum > max_sum) {
      max_sum = curr_sum;
    }
    // This is done after finding the max_sum because if the curr_sum is -ve and
    // max_sum is not defined then we need the -ve sum as an answer, but if we
    // reset it to 0 earlier then we will get 0 instead.
    if (curr_sum < 0) {
      curr_sum = 0;
    }
  }
  return max_sum;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int st = 0;
  int size = sizeof(arr) / sizeof(arr[0]);
  // Printing max sub arrays
  max_subarrays(arr, size);
  // Max sub array sum
  cout << endl;
  cout << "-----------The Max Subarrys sum is:----------" << endl;
  cout << max_subarray_sum(arr, size);
  cout << endl;
  cout << "-----------The Max Subarrys sum using Kadans Algo is:----------"
       << endl;
  cout << kadans_algo(arr, size);
  return 0;
}
