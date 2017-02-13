#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5;
int N;
long long dp[maxn], X[maxn], P, C[maxn], Sp[maxn], Xp[maxn];

struct Line {
  long long a, b;
};

deque<Line> dq;
bool check(const Line&, const Line&, int);
bool better(const Line&, const Line&, const Line&);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> X[i] >> P >> C[i];
    Sp[i] = Sp[i - 1] + P;
    Xp[i] = Xp[i - 1] + X[i] * P;
  }
  dq.push_back((Line){ 0, 0 });
  for (int i = 1; i <= N; ++i) {
    while (dq.size() >= 2 && check(dq[1], dq[0], X[i])) dq.pop_front();
    dp[i] = X[i] * Sp[i] - Xp[i] + C[i] + dq.front().a * X[i] + dq.front().b;
    long long A = -Sp[i], B = dp[i] + Xp[i];
    while (dq.size() >= 2 && better(dq[dq.size() - 2], dq[dq.size() - 1], (Line){ A, B })) dq.pop_back();
    dq.push_back((Line){ A, B });
  }
  cout << dp[N] << '\n';
  return 0;
}

bool check(const Line& l1, const Line& l2, int x) {
  return l1.a * x + l1.b <= l2.a * x + l2.b;
}

bool better(const Line& l1, const Line& l2, const Line& l3) {
  return (l2.b - l1.b) / (l1.a - l2.a) > (l3.b - l2.b) / (l2.a - l3.a);
}
