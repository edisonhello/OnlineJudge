#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

const int MAXN = 50000 + 5;
int N, s, t, bccno[MAXN], in[MAXN], bcc, dfs, Max, kase;
bool cut[MAXN];
long long ans1, ans2;
vector<int> G[MAXN], BCC[MAXN];
int DFS(int, int);

struct Edge {
  int st, ed;
};

stack<Edge> S;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> N, N) {
    for (int i = 0; i < MAXN; ++i) G[i].clear(), BCC[i].clear();
    Max = 0;
    for (int i = 0; i < N; ++i) {
      cin >> s >> t;
      G[s].push_back(t);
      G[t].push_back(s);
      Max = max({ Max, s, t });
    }
    memset(in, 0, sizeof(in)); memset(bccno, 0, sizeof(bccno));
    memset(cut, false, sizeof(cut));
    while (S.size()) S.pop();
    bcc = 0; dfs = 0;
    for (int i = 1; i <= Max; ++i) {
      if (!in[i]) DFS(i, -1);
    }
    ans1 = 0; ans2 = 1;
    for (int i = 1; i <= bcc; ++i) {
      int c = 0;
      for (int j : BCC[i]) if (cut[j]) c++;
      if (c == 1) ans1++, ans2 *= (long long)(BCC[i].size() - c);
    }
    if (bcc == 1) ans1 = 2, ans2 = (long long)BCC[1].size() * (long long)(BCC[1].size() - 1) / 2;
    cout << "Case " << ++kase << ": " << ans1 << ' ' << ans2 << '\n';
  }
  return 0;
}

int DFS(int x, int fa) {
  in[x] = ++dfs;
  int low = in[x];
  int child = 0;
  for (int u : G[x]) {
    Edge e = (Edge){ x, u };
    if (!in[u]) {
      S.push(e); child++;
      int l = DFS(u, x);
      low = min(low, l);
      if (l >= in[x]) {
        cut[x] = true;
        bcc++;
        while (true) {
          Edge eg = S.top(); S.pop();
          if (bccno[eg.st] != bcc) { BCC[bcc].push_back(eg.st); bccno[eg.st] = bcc; }
          if (bccno[eg.ed] != bcc) { BCC[bcc].push_back(eg.ed); bccno[eg.ed] = bcc; }
          if (eg.st == x && eg.ed == u) break;
        }
      }
    } else if (in[u] < in[x] && u != fa) {
      S.push(e);
      low = min(low, in[u]);
    }
  }
  if (fa < 0 && child == 1) cut[x] = true;
  return low;
}
