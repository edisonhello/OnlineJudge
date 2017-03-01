#include <bits/stdc++.h>
using namespace std;

const int sigma = 62;

struct Trie {
  int cnt;
  Trie *ch[sigma];
  Trie() {
    for (int i = 0; i < sigma; ++i) ch[i] = NULL;
    cnt = 0;
  }
} *root;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  
}
