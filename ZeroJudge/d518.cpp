#include <iostream>
#include <string>
using namespace std;

struct Trie {
  Trie *ch[26];
  int cnt, id;
  Trie(): cnt(0), id(0) {
    for (int i = 0; i < 26; ++i) ch[i] = NULL;
  }

  void insert(const string& s, int i, int id) {
    if (i >= s.length()) return;
    if (!ch[s[i] - 'a']) ch[s[i] - 'a'] = new Trie();
    ch[s[i] - 'a']->cnt++;
    if (i == s.length() - 1) ch[s[i] - 'a']->id = id;
    ch[s[i] - 'a']->insert(s, i + 1, id);
  }

  int find(const string& s, int i) {
    if (i >= s.length()) return 0;
    if (i == s.length() - 1 && ch[s[i] - 'a']) return ch[s[i] - 'a']->id;
    if (ch[s[i] - 'a'] && ch[s[i] - 'a']->cnt) return ch[s[i] - 'a']->find(s, i + 1);
    return 0;
  }
} *trie;

string s;
int id, N;

void clear(Trie*&);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> N) {
    id = 0;
    clear(trie);
    trie = new Trie();
    while (N--) {
      cin >> s;
      int f = trie->find(s, 0);
      if (f) cout << "Old! " << f << '\n';
      else cout << "New! " << ++id << '\n', trie->insert(s, 0, id);
    }
  }
  return 0;
}

void clear(Trie*& trie) {
  if (!trie) return;
  for (int i = 0; i < 26; ++i) clear(trie->ch[i]);
  delete trie;
}
