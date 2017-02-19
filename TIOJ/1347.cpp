#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5;
const long long MAX = 1000000000000000000LL;
long long A[maxn], L[maxn];
__int128 dp[maxn];
int N, K, P, a, l;

inline __int128 f(int);
struct Line { __int128 a, b; };
deque<Line> dq;
bool check(const Line&, const Line&, long long);
bool over(const Line&, const Line&, const Line&);
inline long long power(long long, int, long long);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> K >> P;
  for (int i = 1; i <= N; ++i) cin >> a, A[i] = A[i - 1] + a;
  for (int i = 1; i <= N - 1; ++i) cin >> l, L[i] = L[i - 1] + l;
  if (N > 12000) {
    // assert(P == 2);
    dq.push_back((Line){ 0, 0 });
    for (int i = 1; i <= N; ++i) {
      while (dq.size() >= 2 && check(dq[0], dq[1], A[i] + L[i - 1])) dq.pop_front();
      dp[i] = f(i) + dq.front().a * (__int128)(A[i] + L[i - 1]) + dq.front().b;
      __int128 a = -2 * (__int128)(A[i] + L[i]);
      __int128 b = 2 * ((__int128)A[i] * (__int128)L[i] + (__int128)A[i] * (__int128)K + (__int128)L[i] * (__int128)K) + (__int128)A[i] * (__int128)A[i] + (__int128)L[i] * (__int128)L[i] + dp[i];
      while (dq.size() >= 2 && over(dq[dq.size() - 2], dq[dq.size() - 1], (Line){ a, b })) dq.pop_back();
      dq.push_back((Line){ a, b });
    }
    cout << (long long)dp[N] << '\n';
    return 0;
  }
  if (N <= 12000) {
    fill(dp, dp + maxn, MAX + 1);
    dp[0] = 0;
    for (int i = 1; i <= N; ++i) {
      for (int j = 0; j < i; ++j) {
        long long M = A[i] - A[j] + L[i - 1] - L[j];
        long long penalty = power(abs(M - K), P, MAX - dp[j]);
        if (penalty == -1) continue;
        dp[i] = min(dp[i], dp[j] + penalty);
      }
    }
    cout << (long long)dp[N] << '\n';
    return 0;
  }
}

inline __int128 f(int i) {
  __int128 ret = 0;
  ret += (__int128)A[i] * (__int128)A[i] + (__int128)L[i - 1] * (__int128)L[i - 1] + (__int128)K * (__int128)K;
  ret += 2 * ((__int128)A[i] * (__int128)L[i - 1] - (__int128)A[i] * (__int128)K - (__int128)L[i - 1] * (__int128)K);
  return ret;
}

bool check(const Line& l1, const Line& l2, long long x) {
  return l1.a * (__int128)x + l1.b >= l2.a * (__int128)x + l2.b;
}

bool over(const Line& l1, const Line& l2, const Line& l3) {
  return (long double)(l2.b - l1.b) / (long double)(l1.a - l2.a) > (long double)(l3.b - l2.b) / (long double)(l2.a - l3.a);
}

inline long long power(long long a, int n, long long ub) {
  if (ub < 0) return -1;
  __int128 A = a;
  __int128 ret = 1;
  for (int i = 0; i < n; ++i) {
    if (ret * A > ub) return -1;
    ret *= A;
  }
  return ret;
}
