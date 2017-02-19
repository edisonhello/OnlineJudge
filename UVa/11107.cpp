#include <bits/stdc++.h>
using namespace std;

const int sigma = 26;

struct Trie {
  int cnt;
  Trie *ch[sigma];
  Trie(): cnt(0) {
    for (int i = 0; i < 26; ++i) ch[i] = NULL;
  }
  void insert(const string& s, int ind) {
    if (ind == s.length() - 1) return;
    if (!ch[s[ind] - 'a']) ch[s[ind] - 'a'] = new Trie();
    ch[s[ind] - 'a']->cnt++;
    ch[s[ind] - 'a']->insert(s, ind + 1);
  }
} *rt;

string s;
int n;
bool ans;

void clear(Trie*&);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n, n) {
    clear(rt);
    for (int i = 0; i < n; ++i) cin >> s, rt->insert(s, 0);
    ans = false; rt->query()
  }
}

void clear(Trie*& t) {
  if (!t) return;
  for (int i = 0; i < sigma; ++i) clear(t->ch[i]);
  delete t; t = NULL;
}
