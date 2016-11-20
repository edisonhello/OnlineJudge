#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int A[22][22], N, dpa[22][1 << 22], mx;
// short dx[] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dp(int, int);
void print(int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N;
  for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) cin >> A[i][j];
  cout << dp(N - 1, (1 << N) - 1) << endl;
  return 0;
}

int dp(int row, int s) {
  cout << "row: " << row << " s: ";
  print(s);
  if (row == -1) return 0;
  if (dpa[row][s]) return dpa[row][s];
  for (int i = 0; i < (1 << N); ++i) {
    if (s & i) {
      int ss = (1 << N) - 1, p = 0;
      for (int j = 0; j < N; ++j) {
        if (i & (1 << j) && ss & (1 << j)) {
          p += A[row][j];
          for (int _ = -1; _ <= 1; ++_) {
            if (j + _ < N && j + _ >= 0 && ss & (1 << (j + _))) ss ^= (1 << (j + _));
          }
        }
      }
      dpa[row][s] = max(dpa[row][s], dp(row - 1, ss) + p);
    }
  }
  return dpa[row][s];
}

void print(int s) {
  string ret = "";
  while (s) {
    if (s % 2) ret += '1';
    else ret += '0';
    s /= 2;
  }
  while (ret.length() < N) ret += '0';
  reverse(ret.begin(), ret.end());
  cout << ret << endl;
}
