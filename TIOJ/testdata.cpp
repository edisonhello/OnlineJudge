#include <bits/stdc++.h>
using namespace std;

const int T = 10, N = 100000;

typedef long long LL;

int main() {
  freopen("in.txt", "w", stdout);
  srand(time(NULL));
  for (int _ = 0; _ < T; ++_) {
    cout << N << ' ' << N << '\n';
    int X = (LL)rand() * (LL)rand() % INT_MAX + 1;
    int Y = (LL)rand() * (LL)rand() % (INT_MAX - X + 1);
    for (int i = 0; i < N; ++i) {
      int X = (LL)rand() * (LL)rand() % INT_MAX + 1;
      int Y = (LL)rand() * (LL)rand() % (INT_MAX - X + 1);
      cout << X << ' ' << Y + X << ' ';
    }
    cout << '\n';
    for (int i = 0; i < N; ++i) {
      int X = (LL)rand() * (LL)rand() % INT_MAX + 1;
      int Y = (LL)rand() * (LL)rand() % (INT_MAX - X + 1);
      cout << X << ' ' << Y + X << ' ';
    }
    cout << '\n';
    cout << X << ' ' << Y + X << "\n\n";
  }
  return 0;
}
