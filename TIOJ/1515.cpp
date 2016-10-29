#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int n, mx;
string s;
int tmp[2][200010];
int c[200010];
int sa[200010];
int lcpa[200010];
int rankk[200010];
void lcp_array();
int lcp_length(int, int);
void suffix_array();

int main() {
  cin >> n;
  cin >> s;
  suffix_array();
  lcp_array();
  cout << mx << endl;
}

void suffix_array() {
  int* rank = tmp[0];
  int* nRank = tmp[1];
  int A = 128;
  for (int i = 0; i < A; ++i) c[i] = 0;
  for (int i = 0; i < s.length(); ++i) c[rank[i] = s[i]]++;
  for (int i = 1; i < A; ++i) c[i] += c[i - 1];
  for (int i = s.length() - 1; i >= 0; --i) sa[--c[s[i]]] = i;

  for (int n = 1; n < s.length(); n *= 2) {
    for (int i = 0; i < A; ++i) c[i] = 0;
    for (int i = 0; i < s.length(); ++i) c[rank[i]]++;
    for (int i = 1; i < A; ++i) c[i] += c[i - 1];
    int* sa2 = nRank;
    int r = 0;
    for (int i = s.length() - n; i < s.length(); ++i) sa2[r++] = i;
    for (int i = 0; i < s.length(); ++i) if (sa[i] >= n) sa2[r++] = sa[i] - n;
    for (int i = s.length() - 1; i >= 0; --i) sa[--c[rank[sa2[i]]]] = sa2[i];
    nRank[sa[0]] = r = 0;
    for (int i = 1; i < s.length(); ++i) {
      if (!(rank[sa[i - 1]] == rank[sa[i]] && sa[i - 1] + n < s.length() && rank[sa[i - 1] + n] == rank[sa[i] + n])) r++;
      nRank[sa[i]] = r;
    }
    swap(rank, nRank);
    if (r == s.length() - 1) break;
    A = r + 1;
  }
}

void lcp_array() {
  for (int i = 0; i < n; ++i) rankk[sa[i]] = i;
  for (int i = 0, lcp = 0; i < n; ++i) {
    if (rankk[i] == 0) lcpa[0] = 0;
    else {
      int j = sa[rankk[i] - 1];
      if (lcp > 0) lcp--;
      while (s[i + lcp] == s[j + lcp]) lcp++;
      lcpa[rankk[i]] = lcp;
      mx = max(mx, lcp);
    }
  }
}
