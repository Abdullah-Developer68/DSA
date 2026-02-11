#include <iostream>
using namespace std;
// Q1: Find if a number is power of 2 using loop
string check_power_loop(int n) {
  int original = n;

  for (int i = 0; n > 1; i++) {
    // check if n is divisible by 2
    if (n % 2 == 0) {
      n = n / 2;
    } else {
      break;
    }
  }
  // return results
  if (n == 1) {
    return "Yes, " + to_string(original) + " is power of 2;";
  }
  return "No, " + to_string(original) + " is not power of 2";
}

// Q2: Find if a number is power of 2 using Bitwise operators without using loop
string check_power(int n) {
  if (n <= 0) {
    return "No," + to_string(n) + "the number is not power of 2.";
  }
  int total_ones = __builtin_popcount(n);

  if (total_ones != 1) {
    return "No," + to_string(n) + "the number is not power of 2.";
  }
  int total_zeros = __builtin_ctz(n);

  int b = total_zeros;

  // Using Right Shift operator the result is a >> b -> a / 2 ^ b.
  // if n = 4 (100) then b = 1 and n >> 2 = 1 (1)
  int result = n >> b;

  if (result != 1) {
    return "No," + to_string(n) + "the number is not power of 2.";
  }
  return "Yes," + to_string(n) + "the number is power of 2.";
}

// Q3: Reverse an integer n.
int reverse_int(int n, int size) {
  int rev = 0;
  int p10 = 1;
  for (int i = 0; i < size; i++) {
    int remainder = n % 10;
    rev = (rev * 10) + remainder;
    n = n / 10;
    p10 = p10 * 10;
  }
  return rev;
}
// Q4: Find if a number is power of 2 without using loop or built-ins
string check_power_no_built(int n) {
    // when - 1 is done then from the first 1 till the end all bits are flip. 0 -> 1 and 1 -> 0
  if (n > 0 && (n & (n - 1)) == 0) {
    return "Yes, " + to_string(n) + " is power of 2.";
  }
  return "No, " + to_string(n) + " is not power of 2.";
}

int main() {
  cout << check_power_loop(32) << endl;
  cout << check_power(64) << endl;
  cout << check_power_loop(63) << endl;
  cout << reverse_int(125, 3); // 1 * 10^2 + 2 * 10^1 + 5 * 10^0
  return 0;
}
