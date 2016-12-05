#include <cstdio>
#include <unordered_map>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#define getchar getchar_unlocked
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
inline bool rit(T& x, Args& ...args) {return rit(x) && rit(args...);}

int N, M, t, a, b, c, d, K, A, V[1000010], r, tot;
unordered_map<int, pair<int, int>> mp[1000010];

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  rit(N, M);
  srand(7122);
  while (M--) {
    rit(t);
    if (t == 0) {
      rit(a, b);
      if (mp[a].find(b) == mp[a].end()) {
        r = rand();
        mp[a][b] = make_pair(r, 0); V[a] ^= r;
        mp[b][a] = make_pair(r, 0); V[b] ^= r;
      }
      mp[a][b].second++; mp[b][a].second++;
    }
    if (t == 1) {
      rit(c, d);
      mp[c][d].second--, mp[d][c].second--;
      if (mp[c][d].second == 0) {
        V[c] ^= mp[c][d].first;
        V[d] ^= mp[d][c].first;
        mp[c].erase(d); mp[d].erase(c);
      }
    }
    if (t == 2) {
      rit(K); tot = 0;
      for (int j = 0; j < K; ++j) {
        rit(A);
        tot ^= V[A];
      }
      if (tot == 0) printf("1\n");
      else printf("0\n");
    }
  }
  return 0;
}
