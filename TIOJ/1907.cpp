#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vec;

int bs(vector<pii>& vec, int l, int r, pii key) {
  while (r - 1 > l) {
    int m = l + (r - 1) / 2;
    if (vec[m].first >= key.first && vec[m].second >= key.second) r = m;
    else l = m;
  }
  return r;
}

inline int rit(){
    int t = 0, k = 1;
    char c;
    do {
        c = getchar();
        if (c == '-') k = -1;
    } while (c < '0' || c > '9');
    do {
        t = t * 10 + c - '0';
        c=getchar();
    } while(c >= '0' && c <= '9');
    return t * k;
};

int LIS(vector<pii>& vec) {
  if (vec.size() == 0) return 0;
  vector<pii> v;
  v.push_back(vec[0]);
  for (int i = 1; i < vec.size(); ++i) {
    if (vec[i].first > v.back().first && vec[i].second > v.back().second) {
      v.push_back(vec[i]);
    } else {
      *lower_bound(v.begin(), v.end(), vec[i]) = vec[i];
    }
  }
  return v.size();
}

int LIS2(vector<pii>& vec) {
  if (vec.size() == 0) return 0;
  vector<pii> v(vec.size());
  int len = 1;
  for (int i = 1; i < vec.size(); ++i) {
    if (vec[i].first < v[0].first && vec[i].second < v[0].second) {
      v[0] = vec[i];
    } else if (vec[i].first > v[len - 1].first && vec[i].second > v[len - 1].second) {
      v[len++] = vec[i];
    } else {
      v[bs(v, -1, len - 1, vec[i])] = vec[i];
    }
  }
  return len;
}

int main() {
    int n;
    int m;
    int w, h;
    n = rit();
    // int dp[20000];
    int dp[20000];
    while (n--) {
        vec.clear();
        m = rit();
        for (int i = 0; i < m; ++i) {
            w = rit();
            h = rit();
            vec.push_back(pii(w, h));
        }
        sort(vec.begin(), vec.end());
        int ans = LIS2(vec);
        cout << ans << endl;
    }
    return 0;
}
