#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5;
int N, I, J;
set<int> G[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  cin >> I >> J;
  if (I == 1) {
    int t, a;
    for (int i = 1; i <= N; ++i) {
      stringstream ss;
      string s;
      getline(cin, s); ss << s;
      ss >> t;
      while (ss >> a) G[t].insert(a), G[a].insert(t);
    }
  }
  if (I == 2) {
    int a, b;
    for (int i = 0; i < N - 1; ++i) {
      cin >> a >> b;
      G[a].insert(b);
      G[b].insert(a);
    }
  }
  if (J == 1) {
    for (int i = 1; i <= N; ++i) {
      cout << i;
      for (int j : G[i]) cout << ' ' << j;
      cout << '\n';
    }
  }
  if (J == 2) {
    vector<pair<int,int>> e;
    for (int i = 1; i <= N; ++i) for (int j : G[i]) if (i < j) e.push_back(make_pair(i, j));
    sort(e.begin(), e.end());
    for (auto i : e) cout << i.first << ' ' << i.second << '\n';
  }
}
