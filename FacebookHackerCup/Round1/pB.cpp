#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 50 + 5;
int T, N, kase, Max, Maxx;
long long X[maxn], Y[maxn], R;
set<pair<long long, long long>> s;
vector<set<pair<long long, long long>>> vec;

void cnt(int, int);
int U(set<pair<long long, long long>>, set<pair<long long, long long>>);

signed main() {
  freopen("fighting_the_zombies.txt", "r", stdin);
  freopen("outB.txt", "w", stdout);
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> N >> R;
    s.clear(); vec.clear();
    Max = Maxx = 0;
    for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i], s.insert(make_pair(X[i], Y[i]));
    for (int i = 0; i < N; ++i) {
      cnt(X[i] - R, Y[i] - R);
      cnt(X[i] - R, Y[i]);
      cnt(X[i], Y[i]);
      cnt(X[i], Y[i] - R);
    }
    int ans = 0;
    for (int i = 0; i < vec.size(); ++i) {
      for (int j = i + 1; j < vec.size(); ++j) {
        ans = max(ans, U(vec[i], vec[j]));
      }
    }
    cout << "Case #" << ++kase << ": ";
    cout << ans << '\n';
  }
  return 0;
}

void cnt(int x, int y) {
  set<pair<long long, long long>> v;
  for (auto i : s) if (i.first >= x && i.first <= x + R && i.second >= y && i.second <= y + R) {
    v.insert(i);
  }
  vec.push_back(v);
}

int U(set<pair<long long, long long>> s1, set<pair<long long, long long>> s2) {
  int u = 0;
  for (auto i : s2) if (s1.find(i) != s1.end()) {
    u++;
  }
  return s1.size() + s2.size() - u;
}
