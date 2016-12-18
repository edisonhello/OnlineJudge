#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct S {
  int x, t;
  bool operator<(const S& a) const {
    return x + t == a.x + a.t ? x < a.x : x + t < a.x + a.t;
  }
} s[100005];

const int INF = 1e9;
int N, T;
long long L, C, ans;
vector<S> LIS;

bool cmp(const S& a, const S& b) {
  return a.x + a.t <= b.x || a.x + a.t < b.x + b.t;
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> N >> L >> C;
    for (int i = 0; i < N; ++i) cin >> s[i].x >> s[i].t;
    sort(s, s + N);
    ans = 0;
    int ed = 0;
    for (int i = 0; i < N; ++i) {
      if (s[i].x >= ed) ans += (C - s[i].x - s[i].t), ed = s[i].x + s[i].t;
    }
    cout << ans << '\n';
  }
  return 0;
}
