#include <bits/stdc++.h>
using namespace std;

const int maxn = 500000 + 5;
unordered_map<int, int> m[710];
vector<int> v[710];
int N, Q, lim, A, tp;
long long tag[710];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> Q;
  lim = 1 + (int)sqrt(N);
  for (int i = 1; i <= N; ++i) {
    cin >> A;
    v[i / lim].push_back(A);
  }
  while (Q--) {
    cin >> tp;
    if (tp == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      int st = 1;
      while (st < l) st += lim;
      int edblk = st / lim, ed = st;
      for (int i = st / lim, j = st; j + lim <= r; ++i, ++edblk, ed += lim, j += lim) tag[i] += x;
      for (int i = st - 1, j = v[i / lim].size() - 1; i >= 0; --i, --j) {
        m[i / lim][v[i / lim][j]]--;
        v[i / lim][j] += x;
        m[i / lim][v[i / lim][j]]++;
      }
      for (int i = ed, j = 0; i <= r; ++i, ++j) {
        m[edblk + 1][v[edblk + 1][j]]
        v[edblk + 1][j] += x;
      }
    }
  }
  return 0;
}
