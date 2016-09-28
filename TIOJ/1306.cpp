#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int kmp(const string&, const string&);
int F[10010], n, q, tt;
char c;
string t, p;

inline int rit() {
	tt = 0;
	do {
		c = getchar_unlocked();
	} while (c < '0' || c > '9');
	do {
		tt = tt * 10 + c - '0';
		c = getchar_unlocked();
	} while (c >= '0' && c <= '9');
	return tt;
}

int main() {
  n = rit();
  while (n--) {
    cin >> t;
    q = rit();
    while (q--) {
      cin >> p;
      printf("%d\n", kmp(t, p));
    }
  }
  return 0;
}

int kmp(const string& A, const string& B) {
  F[0] = -1; F[1] = 0;
  int cnt = 0;
  for (int i = 1, j = 0; i < B.size() - 1; F[++i] = ++j) {
    while (j != -1 && B[i] != B[j]) j = F[j];
  }
  for (int i = 0, j = 0; i - j + B.size() <= A.size(); i++, j++) {
    while (j != -1 && A[i] != B[j]) j = F[j];
    if (j == B.size() - 1) {cnt++; i = i - F[j] - 1; j = -1;}
  }
  return cnt;
}
