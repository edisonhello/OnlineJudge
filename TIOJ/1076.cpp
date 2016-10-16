#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
using namespace std;

int n, m, cnt, F[10000010];
string s, f;
stringstream ss;
vector<string> v;
void query_both(const string&);
void query_tail(const string&);
void query_head(const string&);
vector<string> ret_query_both(const string&, vector<string>);
vector<string> ret_query_tail(const string&, vector<string>);
vector<string> ret_query_head(const string&, vector<string>);
bool kmp(const string&, const string&);
string trim(const string&);

int main() {
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) getline(cin, s), v.push_back(s);
  scanf("%d\n", &m);
  cnt = 1;
  for (int i = 0; i < m; ++i) {
    getline(cin, f);
    if (kmp(f, " ")) {
      ss.clear();
      string ff = f;
      ss << f;
      vector<string> vv = v;
      while (ss >> f) {
        // cout << f << endl;
        if (f[0] == '*' && f[f.length() - 1] == '*') vv = ret_query_both(f, vv);
        else if (f[0] == '*') vv = ret_query_tail(f, vv);
        else if (f[f.length() - 1] == '*') vv = ret_query_head(f, vv);
      }
      printf("Query %d: ", cnt++);
      cout << ff;
      printf(", %lu item(s) is found.\n", vv.size());
      for (int i = 0; i < vv.size(); ++i) cout << vv[i] << endl;
      cout << endl;
    } else if (f[0] == '*' && f[f.length() - 1] == '*') query_both(f);
    else if (f[0] == '*') query_tail(f);
    else if (f[f.length() - 1] == '*') query_head(f);
  }
  return 0;
}

void query_both(const string& s) {
  vector<string> ret;
  for (int i = 0; i < n; ++i) {
    if (kmp(v[i], trim(s))) ret.push_back(v[i]);
  }
  printf("Query %d: ", cnt++);
  cout << s;
  printf(", %lu item(s) is found.\n", ret.size());
  for (int i = 0; i < ret.size(); ++i) cout << ret[i] << endl;
  cout << endl;
}

vector<string> ret_query_both(const string& s, vector<string> vv) {
  vector<string> ret;
  for (int i = 0; i < vv.size(); ++i) {
    if (kmp(vv[i], trim(s))) ret.push_back(vv[i]);
  }
  return ret;
}

void query_tail(const string& s) {
  vector<string> ret;
  string query = s.substr(1, s.length() - 1);
  for (int i = 0; i < n; ++i) {
    if (v[i].length() >= query.length() && v[i].substr(v[i].length() - query.length(), query.length()) == query) ret.push_back(v[i]);
  }
  printf("Query %d: ", cnt++);
  cout << s;
  printf(", %lu item(s) is found.\n", ret.size());
  for (int i = 0; i < ret.size(); ++i) cout << ret[i] << endl;
  cout << endl;
}

vector<string> ret_query_tail(const string& s, vector<string> vv) {
  vector<string> ret;
  string query = s.substr(1, s.length() - 1);
  for (int i = 0; i < vv.size(); ++i) {
    if (vv[i].length() >= query.length() && vv[i].substr(vv[i].length() - query.length(), query.length()) == query) ret.push_back(vv[i]);
  }
  return ret;
}

void query_head(const string& s) {
  vector<string> ret;
  string query = s.substr(0, s.length() - 1);
  for (int i = 0; i < n; ++i) {
    if (v[i].length() >= query.length() && v[i].substr(0, query.length()) == query) ret.push_back(v[i]);
  }
  printf("Query %d: ", cnt++);
  cout << s;
  printf(", %lu item(s) is found.\n", ret.size());
  for (int i = 0; i < ret.size(); ++i) cout << ret[i] << endl;
  cout << endl;
}

vector<string> ret_query_head(const string& s, vector<string> vv) {
  vector<string> ret;
  string query = s.substr(1, s.length() - 1);
  for (int i = 0; i < vv.size(); ++i) {
    if (vv[i].length() >= query.length() && vv[i].substr(0, query.length()) == query) ret.push_back(vv[i]);
  }
  return ret;
}

bool kmp(const string& A, const string& B) {
  memset(F, 0, sizeof(F));
  F[0] = -1; F[1] = 0;
  int cnt = 0;
  for (int i = 1, j = 0; i < B.size() - 1; F[++i] = ++j) {
    while (j != -1 && B[i] != B[j]) j = F[j];
  }
  for (int i = 0, j = 0; i - j + B.size() <= A.size(); i++, j++) {
    while (j != -1 && A[i] != B[j]) j = F[j];
    if (j == B.size() - 1) return true;
  }
  return false;
}

string trim(const string& s) {
  string ret = "";
  for (int i = 1; i < s.length() - 1; ++i) ret += s[i];
  return ret;
}
