#include <bits/stdc++.h>
using namespace std;

int N;
bool sol(int, int);

int main() {
  cin >> N;
  sol(N, 4);
  return 0;
}

bool sol(int N, int k) {
  if (k == 1) {
    if ((int)sqrt(N) * (int)sqrt(N) == N) return cout << (int)sqrt(N) << ' ', true;
    if (N == 0) return cout << 0 << ' ', true;
    return false;
  }
  for (int i = 0; i <= sqrt(N); ++i) {
    if (sol(N - i * i, k - 1)) return cout << i << ' ', true;
  }
  return false;
}
