#include <bits/stdc++.h>
#define Lc(id) (id << 1)
#define Rc(id) (id << 1 | 1)
using namespace std;

const int maxn = 100000 + 5, MOD = 1000000007;
struct Seg { long long Max, Min; } seg[maxn << 2];
int n, q, a[maxn];

void build(int, int, int);
void pull(int);
void modify(int, int, int, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n ;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  build(1, 1, n);
  cout << ((seg[1].Max + MOD - seg[1].Min) % MOD + MOD) % MOD << '\n';
  cin >> q;
  while (q--) {
    int x, k;
    cin >> x >> k;
    modify(1, 1, n, x, k);
    cout << ((seg[1].Max + MOD - seg[1].Min) % MOD + MOD) % MOD << '\n';
  }
  return 0;
}

void build(int id, int L, int R) {
  if (L == R) {
    seg[id].Max = a[L];
    seg[id].Min = a[L];
    return;
  }
  int M = (L + R) >> 1;
  build(Lc(id), L, M); build(Rc(id), M + 1, R);
  pull(id);
}

void pull(int id) {
  seg[id].Max = max(seg[Lc(id)].Max, seg[Rc(id)].Max);
  seg[id].Min = min(seg[Lc(id)].Min, seg[Rc(id)].Min);
}

void modify(int id, int L, int R, int x, int k) {
  if (L == R) {
    seg[id].Max = seg[id].Max * (long long)k % MOD;
    seg[id].Min = seg[id].Min * (long long)k % MOD;
    return;
  }
  int M = (L + R) >> 1;
  if (x <= M) modify(Lc(id), L, M, x, k);
  else modify(Rc(id), M + 1, R, x, k);
  pull(id);
}
