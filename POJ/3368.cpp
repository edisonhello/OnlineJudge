#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define norm(x) (x + maxn)
using namespace std;

const int maxn = 100000 + 5;

struct Query {
  int L, R, block, i;
  bool operator<(const Query& rhs) const {
    return block == rhs.block ? R < rhs.R : block < rhs.block;
  }
} q[maxn];

int N, Q, a[maxn], cnt[maxn << 1], lim, freq[maxn], most, ans[maxn];

void Init();
void add(int);
void sub(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> N, N) {
    cin >> Q;
    Init();
    lim = 1 + (int)sqrt(N);
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 0; i < Q; ++i) {
      cin >> q[i].L >> q[i].R;
      q[i].block = q[i].L / lim;
      q[i].i = i;
    }
    sort(q, q + Q);
    for (int i = 0, L = 1, R = 0; i < Q; ++i) {
      while (R < q[i].R) add(++R);
      while (R > q[i].R) sub(R--);
      while (L > q[i].L) add(--L);
      while (L < q[i].L) sub(L++);
      ans[q[i].i] = most;
    }
    for (int i = 0; i < Q; ++i) cout << ans[i] << '\n';
  }
  return 0;
}

void Init() {
  memset(cnt, 0, sizeof(cnt));
  memset(q, 0, sizeof(q));
  memset(freq, 0, sizeof(freq));
  most = 0;
}

void add(int x) {
  --freq[cnt[norm(a[x])]];
  ++cnt[norm(a[x])];
  --freq[cnt[norm(a[x])]];
  if (freq[most + 1]) ++most;
}

void sub(int x) {
  --freq[cnt[norm(a[x])]];
  --cnt[norm(a[x])];
  ++freq[cnt[norm(a[x])]];
  if (!freq[most]) --most;
}
