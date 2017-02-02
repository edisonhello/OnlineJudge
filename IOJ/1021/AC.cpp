#include <bits/stdc++.h>
using namespace std;

struct Line {
  int a, b;
};

const int maxn = 1000000 + 5;
int N, S, St[maxn], Sf[maxn], dp[maxn], T, F;
deque<Line> dq;

bool check(const Line&, const Line&, int);
bool better(const Line&, const Line&, const Line&);

int main() {
  freopen("in24.txt", "r", stdin); freopen("out24.txt", "w", stdout);
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> S;
  for (int i = 1; i <= N; ++i) cin >> T >> F, St[i] = St[i - 1] + T, Sf[i] = Sf[i - 1] + F;
  memset(dp, 0, sizeof(dp));
  dq.push_back((Line){ -1 * St[N], Sf[N] * St[N] });
  for (int i = N; i >= 1; --i) {
    while (dq.size() >= 2 && check(dq[0], dq[1], Sf[i - 1])) dq.pop_front();
    dp[i] = (S - St[i - 1]) * (Sf[N] - Sf[i - 1]) + dq.front().a * Sf[i - 1] + dq.front().b;
    int A = -1 * St[i - 1], B = Sf[N] * St[i - 1] + dp[i];
    while (dq.size() >= 2 && better(dq[dq.size() - 2], dq[dq.size() - 1], (Line){ A, B })) dq.pop_back();
    dq.push_back((Line){ A, B });
  }
  cout << dp[1] << '\n';
  return 0;
}

bool check(const Line& l1, const Line& l2, int x) {
  return l1.a * x + l1.b >= l2.a * x + l2.b;
}

bool better(const Line& l1, const Line& l2, const Line& l3) {
  return (double)(l2.b - l1.b) / (double)(l1.a - l2.a) < (double)(l3.b - l2.b) / (double)(l2.a - l3.a);
}
