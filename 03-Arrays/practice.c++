#include <iostream>
#include <vector> // allows multiple variables to be returned using one return as an array
using namespace std;

void print_arr(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
}

// Q1: calculate sum & product of all numbers in an array.
vector<int> sum_product(int arr[], int size) {
  int sum = 0;
  int product = 1;

  for (int i = 0; i < size; i++) {
    sum += arr[i];
    product *= arr[i];
  }
  // gets returned as a vector
  return {sum, product};
}

// Q2: swap the max & min number of an array.
void swap_min_max(int arr[], int size) {
  int min = arr[0];
  int min_pos = 0;
  int max = arr[0];
  int max_pos = 0;

  for (int i = 0; i < size; i++) {
    // find min
    if (min > arr[i]) {
      min = arr[i];
      min_pos = i;
    }
    // find max
    if (max < arr[i]) {
      max = arr[i];
      max_pos = i;
    }
  }
  swap(arr[min_pos], arr[max_pos]);
}
// Q3: print all the unique values in an array. nested loop
void print_unquie_values(int arr[], int size) {
  int curr_val;
  bool is_unqiue = true;
  bool check = true;
  int repeated_arr[100] = {};
  int rep_pos = 0;

  for (int i = 0; i < size; i++) {
    curr_val = arr[i];
    int repeated_size = sizeof(repeated_arr) / sizeof(repeated_arr[0]);
    // if value is repeat do not proceed
    for (int a = 0; a < repeated_size; a++) {
      if (curr_val == repeated_arr[a]) {
        check = false;
        break;
      }
    }

    if (!check) {
      check = true; // reset for next value
      continue;
    }

    // check for unqiuness
    for (int j = i + 1; j < size; j++) {
      if (curr_val == arr[j]) {
        is_unqiue = false;
        repeated_arr[rep_pos] = curr_val;
        rep_pos++;
        break;
      }
    }
    // print unqiue values
    if (is_unqiue) {
      cout << to_string(curr_val) + " is unique." << endl;
    } else {
      is_unqiue = true; // reset for next value
    }
  }
}

// Q4: print intersection return common elements of 2 arrays.
int main() {
  int arr[] = {1, 2, 3, 4, 4, 2, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  // sum and product
  vector<int> result = sum_product(arr, size);
  cout << "SUM: " + to_string(result[0]) << endl;
  cout << "PRODUCT: " + to_string(result[1]) << endl;

  // print unique values
  cout << "Unique Values: " << endl;
  print_unquie_values(arr, size);

  // swap min & max
  swap_min_max(arr, size);
  cout << "After Min & Max Swap: " << endl;
  print_arr(arr, size);
  cout << endl;

  return 0;
}
