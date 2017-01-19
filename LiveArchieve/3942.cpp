#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Trie {
  Trie *ch[26];
  int cnt, dep;
  Trie(int dep): cnt(0), dep(dep) {
    for (int i = 0; i < 26; ++i) ch[i] = NULL;
  }

  void insert(const string& s, int i) {
    if (i >= s.length()) return;
    if (!ch[s[i] - 'a']) ch[s[i] - 'a'] = new Trie(i + 1);
    if (i == s.length() - 1) ch[s[i] - 'a']->cnt++;
    ch[s[i] - 'a']->insert(s, i + 1);
  }

} *root;

const int maxlen = 100 + 5, MOD = 20071027;
string s, t;
int N, dpa[maxlen];

void clear(Trie*&);
int dp(Trie*, const string&, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> s) {
    clear(root);
    root = new Trie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> t, root->insert(t, 0);
    memset(dpa, 0, sizeof(dpa));
    cout << dp(root, s.substr(N - 1, 1), N - 1) % MOD << '\n';
  }
}

void clear(Trie*& trie) {
  if (!trie) return;
  for (int i = 0; i < 26; ++i) clear(trie->ch[i]);
  delete trie;
}

int dp(Trie* trie, const string& s, int n) {
  if (n < 0) return 0;
  if (dpa[n]) return dpa[n];
  if (trie->cnt)
}
