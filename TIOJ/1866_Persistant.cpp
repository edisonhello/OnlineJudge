#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
vector<int> G[maxn];
int A[maxn], T, N, u, v, dfs, Max[maxn];

struct Trie {
  Trie* ch[2];
  int cnt;
  Trie(): cnt(0) {
    ch[0] = ch[1] = NULL;
  }
} *trie[maxn];

void clear(Trie*&);
void DFS(int, int, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < maxn; ++i) clear(trie[i]);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) {
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    dfs = 0; root[]
    DFS(1, 0, 0, 0);
    for (int i = 1; i <= N; ++i) cout << Max[i] << '\n';
  }
  return 0;
}

void clear(Trie*& t) {
  if (!t) return;
  clear(t->ch[0]); clear(t->ch[1]);
  delete t;
}

void DFS(int x, int fa, int Xor, int mx) {
  Max[x] = max(mx, )
}
