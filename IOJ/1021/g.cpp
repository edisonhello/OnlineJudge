#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;

int main() {
  srand(time(NULL));
  freopen("in24.txt", "w", stdout);
  cout << N << ' ' << rand() % 100 + 1 << '\n';
  for (int i = 1; i <= N; ++i) {
    cout << rand() % 100 + 1 << ' ' << rand() % 100 + 1 << '\n';
  }
  return 0;
}
