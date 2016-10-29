#include <iostream>
#include <cmath>
#define INF (1 << 30)
using namespace std;

int T, h[1005], N, mn, best;
int H(int, int);

int main() {
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> h[i];
    for (int i = 0; i < N; ++i) {
      mn = INF;
      for (int j = 0; j < N; ++j) {
        // if (i == j) continue;
        // cout << "i: " << i << " j: " << j << ' ' << H(i, j) << endl;
        if (H(i, j) < mn) mn = H(i, j), best = j;
      }
      cout << best + 1 << ' ';
    }
    cout << endl;
  }
  return 0;
}

int H(int i, int j) {
  int ret = 0;
  for (int ii = 0; ii < N - 1; ++ii) {
    if (ii == i) {
      if (ii + 1 == j) ret += abs(h[j] - h[i]);
      else ret += abs(h[j] - h[ii + 1]);
    }
    else if (ii == i - 1) {
      // if ()
      ret += abs(h[ii] - h[j]);
    }
    else if (ii == j) {
      if (ii + 1 == i) ret += abs(h[i] - h[j]);
      else ret += abs(h[i] - h[ii + 1]);
    }
    else if (ii == j - 1) ret += abs(h[ii] - h[j]);
    else ret += abs(h[ii] - h[ii + 1]);
  }
  return ret;
}
