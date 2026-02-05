#include <cmath>
#include <iostream>
using namespace std;

int decimal_to_binary(int decimal_num) {
  if (decimal_num == 0) {
    return 0;
  }
  int binary_num = 0;

  for (int i = 0; decimal_num > 0; i++) {
    int remainder = decimal_num % 2; // 1st: 0
    decimal_num = decimal_num / 2;   // 1st: 21
    binary_num = binary_num + (remainder * pow(10, i));
    // 1st: 0  + (0 * 10^0) = 0
    // 2nd: 0  + (1 * 10^1) = 10
  }

  return binary_num;
}

int main() {
  int decimal_num = 42;

  cout << decimal_to_binary(decimal_num);
}
