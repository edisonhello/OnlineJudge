#include <bits/stdc++.h>
#define lowbit(x) (x & -x)
using namespace std;

const int maxn = 1000000 + 5;
int N, a[maxn], sz[maxn], Max, BIT[maxn], bridge[maxn], b[maxn];

void add(int, int);
int sum(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> a[i], a[i]++, b[N - i - 1] = a[i];
  fill(bridge, bridge + maxn, INT_MAX);
  for (int i = 0; i < N; ++i) {
    add(a[i], 1);
    int smaller = sum(a[i] - 1);
    int L = 1, R = N;
    if (a[i] == N) continue;
    if (i - smaller == 0) continue;
    while (L < R) {
      int M = (L + R) >> 1;
      if (sum(M) - sum(a[i]) >= ((i - smaller - 1) >> 1) + 1) R = M;
      else L = M + 1;
    }
    bridge[a[i]] = min(bridge[a[i]], L);
  }
  memset(BIT, 0, sizeof(BIT));
  for (int i = 0; i < N; ++i) {
    add(b[i], 1);
    int smaller = sum(b[i] - 1);
    if (b[i] == N) continue;
    if (i - smaller == 0) continue;
    int L = 1, R = N;
    while (L < R) {
      int M = (L + R) >> 1;
      if (sum(M) - sum(b[i]) >= ((i - smaller - 1) >> 1) + 1) R = M;
      else L = M + 1;
    }
    bridge[b[i]] = min(bridge[b[i]], L);
  }
  for (int i = 0; i < N; ++i) {
    if (bridge[a[i]] == INT_MAX) continue;
    sz[a[i]]++; sz[bridge[a[i]]]++;
  }
  for (int i = 1; i <= N; ++i) Max = max(Max, sz[i]);
  cout << Max << '\n';
}

void add(int x, int v) {
  while (x <= N) {
    BIT[x] += v;
    x += lowbit(x);
  }
}

int sum(int x) {
  int ret = 0;
  while (x) {
    ret += BIT[x];
    x -= lowbit(x);
  }
  return ret;
}
