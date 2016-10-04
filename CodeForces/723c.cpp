#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

int n, m, a[2010], cnt, tot[2010];
int temp;
pair<int, int> band[2010];
int jizz = 1;
int mn, mni;
vector<int> song[2010];

int main() {
  cin >> n >> m;
  memset(tot, 0, sizeof(tot));
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] >= 1 && a[i] <= m) {
      tot[a[i]]++;
      song[a[i]].push_back(i);
    }
  }
  int idx = 0;
  for (int i = 1; i <= m; ++i) band[idx++] = pair<int, int>(song[i].size(), i);
  sort(band, band + m);
  // for (int i = 0; i < m; ++i) cout << band[i].second << ": " << band[i].first << endl;
  int target = n / m;
  idx = 0;
  cnt = 0;
  for (int i = 0; i < m; ++i) {
    while (band[i].first < target && idx < n) {
      if (a[idx] > m) {
        band[i].first++;
        a[idx] = band[i].second;
        cnt++;
      }
      idx++;
    }
  }
  for (int i = 0; i < m; ++i) {
    idx = 0;
    // cout << band[i].first << endl;
    while (band[i].first < target) {
      band[i].first++;
      a[song[band[m - i - 1].second][idx]] = band[i].second;
      band[m - i - 1].first--;
      idx++;
      cnt++;
    }
  }
  idx = 0;
  cout << target << ' ' << cnt << endl;
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';
  return 0;
}
