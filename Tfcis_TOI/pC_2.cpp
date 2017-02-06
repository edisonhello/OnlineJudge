#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 5;
string s;
int tmp[2][maxn], K;
int c[maxn];
int sa[maxn];
void suffix_array();

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  getline(cin, s);
  cin >> K;
  suffix_array();
  for (int i = 0; i < s.length(); ++i) cout << sa[i] << endl;
  return 0;
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
