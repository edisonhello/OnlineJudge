#include <cstdio>
#include <algorithm>
#include <deque>
#define getchar gtx
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

struct Line {
  long long a, b, x;
};

const int maxn = 500000 + 5;
deque<Line> dq;
int N, K;
long long c[maxn], C[maxn], dp[maxn];

bool check(Line, Line, long long);
bool better(Line, Line, Line);

int main() {
  rit(N, K);
  for (int i = N; i >= 1; --i) rit(c[i]);
  for (int i = 1; i <= N; ++i) C[i] = C[i - 1] + c[i];
  dq.push_back((Line){ 0, 0, 0 });
  for (long long i = 1; i <= N; ++i) {
    if (dq.size() && dq.front().x < i - K) dq.pop_front();
    while (dq.size() >= 2 && check(dq[0], dq[1], i)) dq.pop_front();
    dp[i] = dq.front().a * i + dq.front().b - i * i;
    long long A = 2 * i, B = dp[i] + C[i] - i * i;
    while (dq.size() >= 2 && better(dq[dq.size() - 2], dq[dq.size() - 1], (Line){ A, B, i })) dq.pop_back();
    dq.push_back((Line){ A, B, i });
  }
  printf("%lld\n", dp[N]);
  return 0;
}

bool check(Line l1, Line l2, long long x) {
  return l1.a * x + l1.b <= l2.a * x + l2.b;
}

bool better(Line l1, Line l2, Line l3) {
  return min(l1.x + K, (l2.b - l1.b) / (l1.a - l2.a)) > (l3.b - l2.b) / (l2.a - l3.a);
}
