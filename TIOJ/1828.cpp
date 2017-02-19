#include <bits/stdc++.h>
using namespace std;

int T, X, Y, Z;
bool check(int);

int main() {
  cin >> T;
  while (T--) {
    cin >> X >> Y >> Z;
    int L = 1, R = Z + 1;
    if (X == 0 && Y == 0) { cout << "-1\n"; continue; }
    if (X > 10000) { cout << "0\n"; continue; }
    if (Z == 0) { cout << "1\n"; continue; }
    while (L < R) {
      int M = (L + R) >> 1;
      if (check(M)) R = M;
      else L = M + 1;
    }
    cout << L << '\n';
  }
  return 0;
}

bool check(int v) {
  double t = (double)(10000 - X - v * Y) / (double)v;
  double dis = (double)Z * t;
  return dis < 10000.0;
}
