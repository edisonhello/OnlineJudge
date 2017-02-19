#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;

struct Query {
  int L, R, i, block;
  bool operator<(const Query& q) const {
    return block == q.block ? R < q.R : block < q.block;
  }
} q[maxn];

int T, N, M, A[maxn], Mex, ans[maxn], cnt[maxn];

void Init();
void add(int);
void sub(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  while (T--) {
    Init();
    cin >> N >> M;
    int lim = 1 + (int)sqrt(N);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = 0; i < M; ++i) {
      cin >> q[i].L >> q[i].R;
      q[i].i = i; q[i].block = q[i].L / lim;
    }
    sort(q, q + M);
    for (int i = 0, L = 1, R = 0; i < M; ++i) {
      while (R < q[i].R) add(++R);
      while (R > q[i].R) sub(R--);
      while (L > q[i].L) add(--L);
      while (L < q[i].L) sub(L++);
      ans[q[i].i] = Mex;
    }
    for (int i = 0; i < M; ++i) cout << ans[i] << '\n';
  }
  return 0;
}

void Init() {
  memset(cnt, 0, sizeof(cnt));
  memset(ans, 0, sizeof(ans));
  Mex = 0;
}

void add(int x) {
  if (A[x] > 100000) return;
  cnt[A[x]]++;
  while (cnt[Mex]) ++Mex;
}

void sub(int x) {
  if (A[x] > 100000) return;
  cnt[A[x]]--;
  if (!cnt[A[x]] && A[x] < Mex) Mex = A[x];
}
