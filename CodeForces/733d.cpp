#include <bits/stdc++.h>
using namespace std;

int sz[3], N, Max, a, b;
map<pair<int, int>, pair<int, int>> m;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  a = b = 0;
  for (int i = 1; i <= N; ++i) {
    cin >> sz[0] >> sz[1] >> sz[2];
    sort(sz, sz + 3);
    if (sz[0] > Max) {
      a = i;
      b = 0;
      Max = sz[0];
      continue;
    }
    m[make_pair(sz[0], sz[1])] = max(m[make_pair(sz[0], sz[1])], make_pair(sz[2], i));
    m[make_pair(sz[0], sz[2])] = max(m[make_pair(sz[0], sz[2])], make_pair(sz[1], i));
    m[make_pair(sz[1], sz[2])] = max(m[make_pair(sz[1], sz[2])], make_pair(sz[0], i));
    auto Min = min({ m[make_pair(sz[1], sz[2])], m[make_pair(sz[0], sz[2])], m[make_pair(sz[0], sz[1])] });
    if (Min.first > Max) {
      Max = Min.first;
      a = Min.second;
      b = i;
    }
  }
  if (b) cout << "2 " << a << " " << b << '\n';
  else cout << "1 " << a << '\n';
  return 0;
}
