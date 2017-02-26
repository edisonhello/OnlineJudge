#include <bits/stdc++.h>
using namespace std;

int n, r;
vector<long long> ans;
vector<int> v;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> r;
  for (int i = 0; i < n - r; ++i) v.push_back(0);
  for (int i = 0; i < r; ++i) v.push_back(1);
  do {
    vector<int> jizz;
    for (int i = 0; i < v.size(); ++i) if (v[i]) jizz.push_back(i);
    do {
      long long ret = 0;
      for (int i : jizz) ret = ret * 10 + i;
      ans.push_back(ret);
    } while (next_permutation(jizz.begin(), jizz.end()));
  } while (next_permutation(v.begin(), v.end()));
  sort(ans.begin(), ans.end(), [](const long long i, const long long j) -> bool { return i > j; });
  if (ans.size() < r + n) cout << ans[ans.size() - 1] << '\n';
  else cout << ans[r + n - 1] << '\n';
  return 0;
}
