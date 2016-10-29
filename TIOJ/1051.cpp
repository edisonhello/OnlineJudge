#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, S, xx1[520], xx2[520], LCS[520][520], mp[520][520];
vector<int> x1, x2;
vector<int> ans;
vector<int> LDS(int*);
void solve(int, int);

int main() {
  cin >> N;
  while (N--) {
    cin >> S;
    ans.clear(); x1.clear(); x2.clear();
    memset(LCS, 0, sizeof(LCS));
    for (int i = 0; i < S; ++i) cin >> xx1[i];
    for (int i = 0; i < S; ++i) cin >> xx2[i];
    x1 = LDS(xx1); x2 = LDS(xx2);
    cout << "LDS1: ";
    for (int i = 0; i < x1.size(); ++i) cout << x1[i] << ' ';
    cout << endl;
    cout << "LDS2: ";
    for (int i = 0; i < x2.size(); ++i) cout << x2[i] << ' ';
    cout << endl;
    for (int i = 0; i < x1.size(); ++i) {
      for (int j = 0; j < x2.size(); ++j) {
        if (x1[i] == x2[j]) LCS[i + 1][j + 1] = LCS[i][j] + 1, mp[i + 1][j + 1] = 3;
        else {
          if (LCS[i][j + 1] > LCS[i + 1][j]) LCS[i + 1][j + 1] = LCS[i][j + 1], mp[i + 1][j + 1] = 1;
          else LCS[i + 1][j + 1] = LCS[i + 1][j], mp[i + 1][j + 1] = 2;
        }
      }
    }
    solve(x1.size(), x2.size());
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
    cout << endl;
  }
  return 0;
}

vector<int> LDS(int* a) {
  vector<int> ret;
  ret.push_back(a[0]);
  for (int i = 1; i < S; ++i) {
    if (a[i] < ret.back()) ret.push_back(a[i]);
    else *lower_bound(ret.begin(), ret.end(), a[i]) = a[i];
  }
  return ret;
}

void solve(int l1, int l2) {
  if (l1 == 0 || l2 == 0) return;
  if (mp[l1][l2] == 3) ans.push_back(x1[l1 - 1]), solve(l1 - 1, l2 - 1);
  else if (mp[l1][l2] == 2) solve(l1, l2 - 1);
  else solve(l1 - 1, l2);
}
