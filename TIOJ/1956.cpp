#include <bits/stdc++.h>
#include "lib1956.h"
using namespace std;

int solve(int l, int u, int w[], int n, int result[]) {
  vector<pair<int, int>> vec(n);
  for (int i = 0; i < n; ++i) vec[i] = make_pair(w[i], i);
  sort(vec.begin(), vec.end());
  vector<pair<long long, int>> v;
  v.push_back(make_pair(0, -1));
  long long sum = 0;
  for (int i = 0; i < vec.size(); ++i) {
    sum += vec[i].first;
    auto it = lower_bound(v.begin(), v.end(), make_pair(sum - u, -1));
    if (sum - it->first >= l) {
      int ind = 0;
      for (int j = it->second + 1; j <= i; ++j) result[ind++] = vec[j].second;
      return ind;
    }
    v.push_back(make_pair(sum, i));
  }
  auto it = lower_bound(v.begin(), v.end(), make_pair(sum - u, -1));
  if (sum - it->first >= l) {
    int ind = 0;
    for (int j = it->second + 1; j < n; ++j) result[ind++] = vec[j].second;
    return ind;
  }
  return 0;
}
