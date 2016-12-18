#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <climits>
#include <stack>
#include <cmath>
#define int long long
using namespace std;

int X[1005], Y[1005], T, N, L, U, K, W[1005][1005], _i, _j, Lx[1005], Ly[1005], match[1005], mx;
bool jizz[1005][1005];
__int128 ans;
const int INF = 10000000000000;
bool s[1005], t[1005];
bool DFS(int);
void update();
vector<pair<int, int>> ban;
void output(__int128);

signed main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> N >> L >> U >> K;
    memset(W, 0, sizeof(W));
    ban.clear();
    while (K--) {
      cin >> _i >> _j;
      ban.push_back({_i, _j});
    }
    for (int i = 1; i <= N; ++i) cin >> X[i];
    for (int i = 1; i <= N; ++i) cin >> Y[i];
    mx = 0;
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        if (X[i] + Y[j] < L) W[i][j] = 0;
        else if (X[i] + Y[j] <= U) W[i][j] = X[i] + Y[j] - L;
        else W[i][j] = U - L;
        if (W[i][j] > mx) mx = W[i][j];
      }
    }
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) W[i][j] = mx - W[i][j];
    }
    memset(jizz, false, sizeof(jizz));
    for (auto i : ban) W[i.first][i.second] = -1, jizz[i.first][i.second] = true;
    memset(s, false, sizeof(s)); memset(t, false, sizeof(t));
    memset(Ly, 0, sizeof(Ly)); memset(Lx, 0, sizeof(Lx));
    memset(match, 0, sizeof(match));
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) Lx[i] = max(Lx[i], W[i][j]);
    for (int i = 1; i <= N; ++i) {
      while (true) {
        memset(s, false, sizeof(s)); memset(t, false, sizeof(t));
        if (DFS(i)) break;
        else update();
      }
    }
    bool imp = false;
    ans = 0;
    for (int i = 1; i <= N; ++i) {
      if (jizz[match[i]][i]) { imp = true; break; }
      int add = mx - W[match[i]][i];
      ans += add;
    }
    if (imp) cout << "no\n";
    else output(ans);
  }
  return 0;
}

bool DFS(int i) {
  s[i] = true;
  for (int j = 1; j <= N; ++j) {
    if (Lx[i] + Ly[j] == W[i][j] && !t[j]) {
      t[j] = true;
      if (!match[j] || DFS(match[j])) {
        match[j] = i;
        return true;
      }
    }
  }
  return false;
}

void update() {
  int a = INF;
  for (int i = 1; i <= N; ++i) if (s[i]) {
    for (int j = 1; j <= N; ++j) if (!t[j]) {
      a = min(a, Lx[i] + Ly[j] - W[i][j]);
    }
  }
  for (int i = 1; i <= N; ++i) {
    if (s[i]) Lx[i] -= a;
    if (t[i]) Ly[i] += a;
  }
}

void output(__int128 ans) {
  stack<int> ret;
  int k = 1;
  while (ans) {
    ret.push((int)(ans % 10));
    ans -= ans % 10;
    ans /= 10;
  }
  while (ret.size()) cout << ret.top(), ret.pop();
  cout << '\n';
}
