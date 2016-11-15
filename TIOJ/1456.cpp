#include <cstdio>
#include <vector>
#include <cstring>
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

vector<int> G[1005];
int in[1005], a, b, arr[1005], n, m;
bool p, v[1005];

int main() {
  while (rit(n, m)) {
    memset(in, 0, sizeof(in)); memset(v, false, sizeof(v));
    for (int i = 0; i <= n; ++i) G[i].clear();
    while (m--) {
      rit(a, b);
      G[a].push_back(b);
      in[b]++;
    }
    for (int i = 0; i < n; ++i) rit(arr[i]);
    p = true;
    for (int i = 0; i < n; ++i) {
      if (!in[arr[i]]) {
        for (auto x : G[arr[i]]) {
          if (!v[x]) in[x]--;
        }
        v[arr[i]] = true;
      } else {
        p = false;
        break;
      }
    }
    if (p) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
