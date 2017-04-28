#include <iostream>
using namespace std;

int main() {
  double i = 0.0;
  int cnt = 0;
  for (; cnt < 10000; i += 0.0001, ++cnt);
  if (i == 1.0) cout << "Hao123" << endl;
  else cout << "Osas" << endl;
  return 0;
}
