#include <iostream>
using namespace std;

void do_something(int* a, const int& b, int c) {
  c = 10;
  a = b = 7;
}

int main() {
  int x = 8, y = 1, z = 5;
  do_something(&x, y, z);
  cout << x + y + z << endl;
  return 0;
}
