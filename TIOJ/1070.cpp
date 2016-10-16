#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int F[101];
set<char> special;
string ss = "~!@#$%^&*()_+|`-=\\{}[]:\";\'<>\?,./ ";
string s1, s2;
bool cap, lowercase, number, jizz, cir;
bool kmp(const string&, const string&);

int main() {
  for (int i = 0; i < ss.length(); ++i) special.insert(ss[i]);
  while (getline(cin, s1)) {
    getline(cin, s2);
    cap = false; lowercase = false; number = false; jizz = false;
    if (s1 == "END" && s2 == "END") break;
    if (s1 != s2) {cout << "Password settings are not consistent.\n"; continue;}
    if (s1.length() < 8 || s1.length() > 12) {cout << "Password should contain 8 to 12 characters.\n"; continue;}
    for (int i = 0; i < s1.length(); ++i) {
      if (s1[i] >= 'A' && s1[i] <= 'Z') cap = true;
      if (s1[i] >= 'a' && s1[i] <= 'z') lowercase = true;
      if (s1[i] >= '0' && s1[i] <= '9') number = true;
      if (special.count(s1[i])) jizz = true;
    }
    if (!cap) {cout << "Password should contain at least one upper-case alphabetical character.\n"; continue;}
    if (!lowercase) {cout << "Password should contain at least one lower-case alphabetical character.\n"; continue;}
    if (!number) {cout << "Password should contain at least one number.\n"; continue;}
    if (!jizz) {cout << "Password should contain at least one special character.\n"; continue;}
    reverse(s2.begin(), s2.end());
    if (s1 == s2) {cout << "Symmetric password is not allowed.\n"; continue;}
    bool c = false;
    for (int i = 3; i <= 6 && !c; ++i) {
      cir = true;
      for (int j = 0, k = 0; j < s1.length(); ++j, ++k) {
        if (k >= i) k = 0;
        if (s1[j] != s1[k]) {cir = false; break;}
      }
      if (cir) {cout << "Circular password is not allowed.\n"; c = true;}
    }
    if (!c) cout << "Password is valid.\n";
  }
  return 0;
}

bool kmp(const string& A, const string& B) {
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
