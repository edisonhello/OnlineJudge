#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MOD = 1000000009;
int n;
struct D {
  long long w, h;
  // D() {}
  bool operator < (const D& dd) const {
    return w <= dd.w && h <= dd.h;
  }
  bool operator > (const D& dd) const {
    return w >= dd.w && h >= dd.h;
  }
};

// priority_queue<d, vector<d>, greater
D d[1000010];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> d[i].w >> d[i].h;
  }
  long long mx = 0;
  // sort(d, d + n);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (d[i] > d[j]) mx += d[i].w * d[i].h - d[j].w * d[j].h, mx %= MOD;
      else if (d[i] < d[j]) mx += d[j].w * d[j].h - d[i].w * d[i].h, mx %= MOD;
    }
  }
  cout << mx % MOD << endl;
}
