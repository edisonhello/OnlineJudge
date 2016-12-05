#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
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
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

int T, N, S[200005], H[200005], M, l, r, mid, now;
bool v[200005];
pair<int, int> ch[600005];
vector<pair<int, int>> ans;
int check();
void DFS(int);

int main() {
  rit(T);
  while (T--) {
    rit(N); for (int i = 0; i < N; ++i) rit(S[i]), H[S[i]] = i;
    rit(M); for (int i = 0; i < M; ++i) rit(ch[i].first, ch[i].second);
    l = -1; r = N * 3;
    while (l < r - 1) {
      mid = (l + r) >> 1;
      for (int i = 0; i < N; ++i) S[H[i]] = i;
      for (int i = 0; i < mid; ++i) swap(S[ch[i].first], S[ch[i].second]);
      if (check() <= mid) r = mid;
      else l = mid;
    }
    printf("%d\n", r); ans.clear();
    memset(v, false, sizeof(v));
    for (int i = 0; i < N; ++i) S[H[i]] = i;
    for (int i = 0; i < r; ++i) swap(S[ch[i].first], S[ch[i].second]);
    for (int i = 0; i < N; ++i) {
      if (!v[i]) {
        v[i] = true;
        now = i;
        while (!v[S[now]]) {
          ans.push_back(make_pair(S[now], S[S[now]]));
          now = S[now];
          v[now] = true;
        }
      }
    }
    if (ans.size() < r) ans.push_back(make_pair(0, 0));
    for (int i = 0; i < N; ++i) S[H[i]] = i;
    for (int i = 0; i < r; ++i) {
      swap(H[S[ch[i].first]], H[S[ch[i].second]]);
      swap(S[ch[i].first], S[ch[i].second]);
      printf("%d %d\n", H[ans[i].first], H[ans[i].second]);
      swap(H[ans[i].first], H[ans[i].second]);
      swap(S[H[ans[i].first]], S[H[ans[i].second]]);
    }
  }
  return 0;
}

int check() {
  int cycle = 0;
  memset(v, false, sizeof(v));
  for (int i = 0; i < N; ++i) {
    if (!v[i]) {
      cycle++;
      DFS(i);
    }
  }
  return N - cycle;
}

void DFS(int x) {
  v[x] = true;
  if (!v[S[x]]) DFS(S[x]);
}
