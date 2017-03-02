#include <bits/stdc++.h>
using namespace std;

int f(int n) {
  return n == 1 ? 1 : f(n / 2) + 1;
}

int main() {
  int n; while (cin >> n) {
    cout << f(n) << '\n';
  }
  return 0;
}
