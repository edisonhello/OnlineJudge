#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <climits>
#include <stack>
#include <cmath>
#define getchar getchar_unlocked
#define int long long
using namespace std;

char __c;
bool flag;

template <typename T>
inline bool rit(T& x) {
  __c = 0, flag = false;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

int X[1005], Y[1005], T, N, L, U, K, W[1005][1005], _i, _j, Lx[1005], Ly[1005], match[1005], mx;
bool jizz[1005][1005];
__int128 ans;
const int INF = (1LL<<60);
bool s[1005], t[1005];
bool DFS(int);
void update();
vector<pair<int, int>> ban;

ostream& operator<<(ostream& dest, __int128 value) {
  ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char* d = end(buffer);
    do {
      -- d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while ( tmp != 0 );
    if (value < 0) {
      -- d;
      *d = '-';
    }
    int len = end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) dest.setstate(ios_base::badbit);
  }
  return dest;
}

signed main() {
  rit(T);
  while (T--) {
    rit(N, L, U, K);
    memset(W, 0, sizeof(W));
    ban.clear();
    while (K--) {
      rit(_i, _j);
      ban.push_back({ _i, _j });
    }
    for (int i = 1; i <= N; ++i) rit(X[i]);
    for (int i = 1; i <= N; ++i) rit(Y[i]);
    mx = 0;
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        if (X[i] + Y[j] < L) W[i][j] = 0;
        else if (X[i] + Y[j] <= U) W[i][j] = X[i] + Y[j] - L;
        else W[i][j] = U - L;
        if (W[i][j] > mx) mx = W[i][j];
      }
    }
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) W[i][j] = mx - W[i][j];
    memset(jizz, false, sizeof(jizz));
    for (auto i : ban) W[i.first][i.second] = -INF, jizz[i.first][i.second] = true;
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
      __int128 add = mx - W[match[i]][i];
      ans += add;
    }
    if (imp) puts("no");
    else cout << ans << '\n';
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
