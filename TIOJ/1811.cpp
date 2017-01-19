#include <cstdio>
#include <deque>
#include <set>
#define getchar getchar_unlocked
using namespace std;

char __c;
bool flag;

inline int gtx() {
  const int N = 1048576;
  static char buffer[N];
  static char *p = buffer, *end = buffer;
  if (p == end) {
    if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
    p = buffer;
  }
  return *p++;
}

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

const int maxn = 100000 + 5, LOG = 17;
long long W[maxn], H[maxn], N, L, dp[maxn], sum;

deque<int> dq;
set<long long> s;

int main() {
  rit(N, L);
  for (int i = 1; i <= N; ++i) rit(H[i], W[i]);
  dq.push_back(0);
  for (int i = 1; i <= N; ++i) {
    while (dq.size() >= 2 && H[dq.back()] <= H[i]) {
      int b = dq.back(); dq.pop_back();
      s.erase(dp[dq.back()] + H[b]);
    }
    s.insert(dp[dq.back()] + H[i]);
    dq.push_back(i);
    sum += W[i];
    while (sum > L) {
      s.erase(dp[dq[0]] + H[dq[1]]);
      sum -= W[++dq.front()];
      if (dq[0] == dq[1]) dq.pop_front();
      else if (sum <= L) s.insert(dp[dq[0]] + H[dq[1]]);
    }
    dp[i] = *s.begin();
  }
  printf("%lld\n", dp[N]);
  return 0;
}
