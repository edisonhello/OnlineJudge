#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 10 + 5;
int T, H, S, x, y, z, kase, big, tot, h;
long double Max;
string s;
set<vector<int>> st;

tuple<int, int, int> tran(string);
void rec(vector<int>);
int Sum(vector<int>);
void Out(vector<int>);
int p(int x);
int perm(vector<int>);

signed main() {
  freopen("fighting_the_zombie.txt", "r", stdin);
  freopen("outC.txt", "w", stdout);
  cin >> T;
  while (T--) {
    cin >> H >> S;
    Max = 0.0;
    for (int i = 0; i < S; ++i) {
      cin >> s;
      tie(x, y, z) = tran(s);
      // cout << "x: " << x << " y: " << y << " z: " << z << '\n';
      h = H - z;
      vector<int> d;
      for (int j = 0; j < x; ++j) d.push_back(1);
      tot = 0; big = 0;
      st.clear();
      rec(d);
      // cout << "big: " << big << '\n';
      Max = max(Max, (long double)big / (long double)tot);
    }
    cout << "Case #" << ++kase << ": " << fixed << setprecision(8) << Max << '\n';
  }
  return 0;
}

tuple<int, int, int> tran(string s) {
  int x = 0, y = 0, z = 0;
  stringstream ss;
  int d;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'd') {
      ss.clear(); ss.str(""); ss << s.substr(0, i); ss >> x;
      d = i + 1;
    }
    if (s[i] == '-' || s[i] == '+') {
      ss.clear(); ss.str(""); ss << s.substr(d, i - d); ss >> y;
      ss.clear(); ss.str(""); ss << s.substr(i + 1, s.length() - i - 1); ss >> z;
      if (z && s[i] == '-') z = -z;
    }
  }
  if (!z) {
    ss.clear(); ss.str(""); ss << s.substr(d, s.length() - d); ss >> y;
  }
  return make_tuple(x, y, z);
}

void rec(vector<int> v) {
  sort(v.begin(), v.end());
  if (st.count(v)) return;
  st.insert(v);
  // Out(v);
  tot += perm(v);
  if (Sum(v) >= h) big += perm(v);
  vector<int> d = v;
  for (int i = 0; i < d.size(); ++i) {
    if (d[i] < y) d[i]++, rec(d), d[i]--;
  }
}

int Sum(vector<int> v) {
  int ret = 0;
  for (int i : v) ret += i;
  return ret;
}

void Out(vector<int> v) {
  for (int i : v) cout << i << ' ';
  cout << '\n';
}

int p(int x) {
  int ret = 1;
  for (int i = 1; i <= x; ++i) ret *= i;
  return ret;
}

int perm(vector<int> v) {
  int cnt[25] = {0};
  for (int i : v) cnt[i]++;
  int ret = p(v.size());
  for (int i = 1; i <= y; ++i) if (cnt[i]) ret /= p(cnt[i]);
  return ret;
}
