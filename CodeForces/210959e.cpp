#include <bits/stdc++.h>
using namespace std;

struct Trie {
  Trie *ch[26];
  int cnt;
  bool leaf;
  int dp;
  Trie(): cnt(0), leaf(false), dp(0) {
    for (int i = 0; i < 26; ++i) ch[i] = NULL;
  }
  void insert(const string& s, int i) {
    if (i == s.length()) leaf = true;
    if (i >= s.length()) return;
    if (!ch[s[i] - 'a']) ch[s[i] - 'a'] = new Trie();
    ch[s[i] - 'a']->cnt++;
    leaf = false;
    ch[s[i] - 'a']->insert(s, i + 1);
  }
} *root;

string s;
int n;
int dp(Trie*);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  root = new Trie();
  for (int i = 0; i < n; ++i) cin >> s, root->insert(s, 0);
  cout << dp(root) << '\n';
  return 0;
}

int dp(Trie* t) {
  if (t->dp) return t->dp;
  if (t->leaf) return t->dp = 2;
  int child = 0;
  for (int i = 0; i < 26; ++i) {
    if (t->ch[i] && t->ch[i]->cnt) child++;
    else continue;
    if (dp(t->ch[i]) == 2) return t->dp = 1;
  }
  return t->dp = (child & 1) ? 1 : 2;
}
