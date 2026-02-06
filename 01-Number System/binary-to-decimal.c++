#include <cmath>
#include <iostream>
using namespace std;

int binary_to_decimal(int binary_num) {

  if (binary_num == 0) {
    return 0;
  }

  int decimal_num = 0;

  for (int i = 0; binary_num > 0; i++) {
    int remainder = binary_num % 10;
    binary_num = binary_num / 10;
    decimal_num = decimal_num + (remainder * pow(2, i));
  }

  return decimal_num;
}

int main() {
  int binary_num = 101010;
  cout << binary_to_decimal(binary_num);
}
