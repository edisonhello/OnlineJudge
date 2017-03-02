#include <bits/stdc++.h>
using namespace std;

vector<string> v;
string s = "ROYGBIPLW";
bool em[9][9];

void solve(vector<string>);
bool valid(const vector<string>&);
bool full(const vector<string>&);
void print(const vector<string>&);
bool Ban(const vector<string>&, int, int, char);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (int i = 0; i < 9; ++i) {
    string s; cin >> s;
    v.push_back(s);
  }
  for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) if (v[i][j] == '*') em[i][j] = true;
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (v[i][j] != '*') continue;
      bool ban[9]; memset(ban, false, sizeof(ban));
      for (int k = 0; k < 9; ++k) ban[k] = Ban(v, i, j, s[k]);
      int ans = -1, ok = 0;
      for (int k = 0; k < 9; ++k) if (!ban[k]) ++ok, ans = k;
      if (ok == 1) v[i][j] = s[ans];
    }
  }
  for (int i = 0; i < 9; ++i) {
    vector<int> emp;
    for (int j = 0; j < 9; ++j) if (v[i][j] == '*') emp.push_back(j);
    vector<int> ok[9];
    for (int k = 0; k < 9; ++k) for (int j : emp) if (!Ban(v, i, j, s[k])) ok[k].push_back(j);
    for (int k = 0; k < 9; ++k) if (ok[k].size() == 1) v[i][ok[k][0]] = s[k];
  }
  for (int i = 0; i < 9; ++i) {
    vector<int> emp;
    for (int j = 0; j < 9; ++j) if (v[j][i] == '*') emp.push_back(j);
    vector<int> ok[9];
    for (int k = 0; k < 9; ++k) for (int j : emp) if (!Ban(v, j, i, s[k])) ok[k].push_back(j);
    for (int k = 0; k < 9; ++k) if (ok[k].size() == 1) v[ok[k][0]][i] = s[k];
  }
  solve(v);
  return 0;
}

void solve(vector<string> v) {
  if (!valid(v)) return;
  if (full(v)) {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) if (em[i][j]) cout << v[i][j];
      cout << '\n';
    }
    exit(0);
  }
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (v[i][j] != '*') continue;
      bool ban[9], ok = false; memset(ban, false, sizeof(ban));
      for (int k = 0; k < 9; ++k) ban[k] = Ban(v, i, j, s[k]);
      for (int k = 0; k < 9; ++k) if (!ban[k]) ok = true, v[i][j] = s[k], solve(v), v[i][j] = '*';
      if (!ok) return;
    }
  }
}

bool valid(const vector<string>& v) {
  set<char> s;
  for (int i = 0; i < 9; ++i) {
    s.clear();
    for (int j = 0; j < 9; ++j) {
      if (v[i][j] == '*') continue;
      if (s.count(v[i][j])) return false;
      s.insert(v[i][j]);
    }
  }
  for (int i = 0; i < 9; ++i) {
    s.clear();
    for (int j = 0; j < 9; ++j) {
      if (v[j][i] == '*') continue;
      if (s.count(v[j][i])) return false;
      s.insert(v[j][i]);
    }
  }
  for (int i = 0; i < 9; i += 3) {
    for (int j = 0; j < 9; j += 3) {
      s.clear();
      for (int ii = i; ii < i + 3; ++ii) {
        for (int jj = j; jj < j + 3; ++jj) {
          if (v[ii][jj] == '*') continue;
          if (s.count(v[ii][jj])) return false;
          s.insert(v[ii][jj]);
        }
      }
    }
  }
  return true;
}

bool full(const vector<string>& v) {
  for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) if (v[i][j] == '*') return false;
  return true;
}

void print(const vector<string>& v) {
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) cout << v[i][j];
    cout << '\n';
  }
}

bool Ban(const vector<string>& v, int i, int j, char c) {
  for (int ind = 0; ind < 9; ++ind) if (ind != j) if (v[i][ind] == c) return true;
  for (int ind = 0; ind < 9; ++ind) if (ind != i) if (v[ind][j] == c) return true;
  for (int a = (i / 3) * 3; a < (i / 3) * 3 + 3; ++a) {
    for (int b = (j / 3) * 3; b < (j / 3) * 3 + 3; ++b) {
      if (a == i && b == j) continue;
      if (v[a][b] == c) return true;
    }
  }
  return false;
}
