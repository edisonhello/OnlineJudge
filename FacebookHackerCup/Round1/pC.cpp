#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 100 + 5, maxk = 5000 + 5;
int T, N, M, K, A, B, G, kase;
long long W[maxn][maxn];
pair<int, int> f[maxk];

long long dis(int, int, int, int);

signed main() {
  freopen("manic_moving.txt", "r", stdin);
  freopen("pBout.txt", "w", stdout);
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  while (T--) {
    for (int i = 0; i < maxn; ++i) fill(W[i], W[i] + maxn, INT_MAX);
    cin >> N >> M >> K;
    while (M--) {
      cin >> A >> B >> G; A--; B--;
      W[A][B] = min(W[A][B], (long long)G);
      W[B][A] = W[A][B];
    }
    for (int i = 0; i < N; ++i) W[i][i] = 0;
    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) W[i][j] = min(W[i][j], W[i][k] + W[k][j]);
      }
    }
    for (int i = 0; i < K; ++i) cin >> f[i].first >> f[i].second, f[i].first--, f[i].second--;
    cout << "Case #" << ++kase << ": ";
    if (K & 1) {
      long long d1 = 0, d2 = 0;
      bool keep = true;
      int last = 0;
      for (int i = 0; i < K - 1 && keep; i += 2) {
        if (W[last][f[i].first] == INT_MAX) { d1 = LLONG_MAX; keep = false; continue; }
        long long d = dis(f[i].first, f[i].second, f[i + 1].first, f[i + 1].second);
        if (d == LLONG_MAX) { d1 = LLONG_MAX; keep = false; continue; }
        d1 += W[last][f[i].first] + d;
        last = f[i + 1].second;
      }
      if (W[last][f[K - 1].first] == INT_MAX) d1 = LLONG_MAX, keep = false;
      else d1 += W[last][f[K - 1].first];
      if (W[f[K - 1].first][f[K - 1].second] == INT_MAX) d1 = LLONG_MAX, keep = false;
      else if (keep) d1 += W[f[K - 1].first][f[K - 1].second];
      keep = true;
      if (W[0][f[0].first] == INT_MAX) d2 = LLONG_MAX, keep = false;
      else d2 += W[0][f[0].first];
      if (W[f[0].first][f[0].second] == INT_MAX) d2 = LLONG_MAX, keep = false;
      else if (keep) d2 += W[f[0].first][f[0].second];
      last = f[0].second;
      for (int i = 1; i < K && keep; i += 2) {
        if (W[last][f[i].first] == INT_MAX) { d2 = LLONG_MAX; keep = false; continue; }
        long long d = dis(f[i].first, f[i].second, f[i + 1].first, f[i + 1].second);
        if (d == LLONG_MAX) { d2 = LLONG_MAX; keep = false; continue; }
        d2 += W[last][f[i].first] + d;
        last = f[i + 1].second;
      }
      if (d1 == LLONG_MAX && d2 == LLONG_MAX) cout << "-1\n";
      else cout << min(d1, d2) << '\n';
    } else {
      long long d1 = 0, d2 = 0;
      bool keep = true;
      int last = 0;
      for (int i = 0; i < K && keep; i += 2) {
        long long d = dis(f[i].first, f[i].second, f[i + 1].first, f[i + 1].second);
        if (W[last][f[i].first] == INT_MAX) { d1 = LLONG_MAX; keep = false; continue; }
        if (d == LLONG_MAX) { d1 = LLONG_MAX; keep = false; continue; }
        d1 += d + W[last][f[i].first];
        last = f[i + 1].second;
      }
      keep = true;
      if (W[0][f[0].first] == INT_MAX) d2 = LLONG_MAX, keep = false;
      else d2 += W[0][f[0].first];
      if (W[f[0].first][f[0].second] == INT_MAX) d2 = LLONG_MAX, keep = false;
      else if (keep) d2 += W[f[0].first][f[0].second];
      last = f[0].second;
      for (int i = 1; i < K - 1 && keep; i += 2) {
        if (W[last][f[i].first] == INT_MAX) { d2 = LLONG_MAX; keep = false; continue; }
        long long d = dis(f[i].first, f[i].second, f[i + 1].first, f[i + 1].second);
        if (d == LLONG_MAX) { d2 = LLONG_MAX; keep = false; continue; }
        d2 += W[last][f[i].first] + d;
        last = f[i + 1].second;
      }
      if (W[last][f[K - 1].first] == INT_MAX) d2 = LLONG_MAX, keep = false;
      else if (keep) d2 += W[last][f[K - 1].first];
      if (W[f[K - 1].first][f[K - 1].second] == INT_MAX) d2 = LLONG_MAX, keep = false;
      else if (keep) d2 += W[f[K - 1].first][f[K - 1].second];
      if (d1 == LLONG_MAX && d2 == LLONG_MAX) cout << "-1\n";
      else cout << min(d1, d2) << '\n';
    }
  }
  return 0;
}

long long dis(int s1, int d1, int s2, int d2) {
  bool b1 = false, b2 = false;
  if (W[s1][d1] == INT_MAX || W[d1][s2] == INT_MAX || W[s2][d2] == INT_MAX) b1 = true;
  if (W[s1][s2] == INT_MAX || W[s2][d1] == INT_MAX || W[d1][d2] == INT_MAX) b2 = true;
  if (b1 && b2) return LLONG_MAX;
  long long ret1 = b1 ? LLONG_MAX : W[s1][d1] + W[d1][s2] + W[s2][d2];
  long long ret2 = b2 ? LLONG_MAX : W[s1][s2] + W[s2][d1] + W[d1][d2];
  return min(ret1, ret2);
}
