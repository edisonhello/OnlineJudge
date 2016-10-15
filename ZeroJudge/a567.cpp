#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define PII pair<int, int>
using namespace std;

vector<PII> v;
int n, d, p, cur, ans, mx;

bool cmp(PII a, PII b) {
  return a.first == b.first ? a.second > b.second : a.first < b.first;
}

int main() {
  while (cin >> n) {
    v.clear();
    mx = 0;
    for (int i = 0; i < n; ++i) {cin >> d >> p; mx = max(d, mx); v.push_back(PII(d, p));}
    sort(v.begin(), v.end(), cmp);
    // for (int i = 0; i < n; ++i) cout << v[i].first << ' ' << v[i].second << endl;
    cur = 1, ans = 0;
    for (int i = 0; i < n; ++i) {
      if (cur <= v[i].first) ans += v[i].second, cur++;
    }
    cout << ans << endl;
  }
  return 0;
}
