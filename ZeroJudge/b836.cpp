#include <iostream>
using namespace std;

long long n, m, jizz;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> n >> m) {
    jizz = 1;
    if (m == 0) { cout << "Go Kevin!!\n"; continue; }
    while (true) {
      if (n == 0) { cout << "Go Kevin!!\n"; break; }
      if (n < 0) { cout << "No Stop!!\n"; break; }
      n -= jizz;
      jizz += m;
    }
  }
  return 0;
}
