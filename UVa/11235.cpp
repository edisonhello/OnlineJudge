#include <bits/stdc++.h>
#define norm(x) (x + maxn)
using namespace std;

const int maxn = 100000 + 5;
int n, q, a[maxn], ans[maxn], cnt[maxn << 1], freq[maxn], most;

struct Query {
  int L, R, block, i;
  bool operator<(const Query& rhs) const {
    return block == rhs.block ? R < rhs.R : block < rhs.block;
  }
} query[maxn];

void add(int);
void sub(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n, n) {
    cin >> q;
    memset(cnt, 0, sizeof(cnt));
    memset(freq, 0, sizeof(freq));
    most = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int lim = 1 + (int)sqrt(n);
    for (int i = 0; i < q; ++i) {
      cin >> query[i].L >> query[i].R;
      query[i].block = query[i].L / lim;
      query[i].i = i;
    }
    sort(query, query + q);
    for (int i = 0, L = 1, R = 0; i < q; ++i) {
      while (R < query[i].R) add(++R);
      while (R > query[i].R) sub(R--);
      while (L > query[i].L) add(--L);
      while (L < query[i].L) sub(L++);
      ans[query[i].i] = most;
    }
    for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
  }
  return 0;
}

void add(int x) {
  freq[cnt[norm(a[x])]]--;
  cnt[norm(a[x])]++;
  freq[cnt[norm(a[x])]]++;
  while (freq[most + 1]) ++most;
}

void sub(int x) {
  freq[cnt[norm(a[x])]]--;
  cnt[norm(a[x])]--;
  freq[cnt[norm(a[x])]]++;
  while (!freq[most]) --most;
}
