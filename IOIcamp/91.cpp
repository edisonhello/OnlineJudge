#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int T, n, S[maxn];
long long k, dp[maxn];
struct Row { int p, L, R; };
deque<Row> dq;

void Init();
inline long long f(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    Init();
    cin >> n >> k;
    int x;
    for (int i = 1; i <= n; ++i) cin >> x, S[i] = S[i - 1] + x;
    dq.push_back((Row){ 0, 1, n });
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      while (dq.size() && dq.front().R < i) dq.pop_front();
      dp[i] = f(dq.front().p, i);
      // cout << "dp[" << i << "] = " << dp[i] << '\n';
      while (dq.size() && f(i, dq.back().R) <= f(dq.back().p, dq.back().R)) dq.pop_back();
      if (dq.empty()) { dq.push_back((Row){ i, i + 1, n }); continue; }
      int L = dq.back().L, R = dq.back().R;
      while (L < R) {
        int M = (L + R) >> 1;
        if (f(i, M) <= f(dq.back().p, M)) R = M;
        else L = M + 1;
      }
      dq.back().L = dq.back().R;
      dq.back().R = L;
      dq.push_back((Row){ i, L + 1, n });
    }
    cout << dp[n] << '\n';
  }
  return 0;
}

inline long long f(int L, int R) {
  return dp[L] + (long long)(S[R] - S[L]) * (long long)(S[R] - S[L]) * (long long)(S[R] - S[L]) + k;
}

void Init() {
  dq.clear();
  memset(dp, 0, sizeof(dp));
  memset(S, 0, sizeof(S));
}
