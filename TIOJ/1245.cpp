#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> G[62], mxpath;
bool v[62], p;
int N, a, b, mx, mxi, cnt[63], ans;
char st, ed;
int convert(char);
void DFS(int, int, vector<int>);
void dfs(int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> N, N) {
    for (int i = 0; i < N; ++i) G[i].clear();
    for (int i = 0; i < N - 1; ++i) {
      cin >> st >> ed;
      a = convert(st); b = convert(ed);
      G[a].push_back(b);
      G[b].push_back(a);
    }
    mx = 0;
    memset(v, false, sizeof(v));
    DFS(0, 0, vector<int>());
    memset(v, false, sizeof(v));
    mx = 0;
    DFS(mxi, 0, vector<int>());
    cout << mx + 1 << endl;
    memset(v, false, sizeof(v));
    for (int i : mxpath) v[i] = true;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < N; ++i) {
      if (!v[i]) ans = 0, dfs(i), cnt[ans]++;
    }
    p = false;
    for (int i = 1; i < 63; ++i) {
      if (cnt[i]) cout << "C" << i << ":" << cnt[i] << endl, p = true;
    }
    if (!p) cout << "No functional group\n";
  }
  return 0;
}

int convert(char c) {
  if (c >= 'A' && c <= 'Z') return c - 'A';
  if (c >= 'a' && c <= 'z') return c - 'a' + 26;
  if (c >= '0' && c <= '9') return c - '0' + 52;
}

void DFS(int x, int cur, vector<int> path) {
  path.push_back(x);
  v[x] = true;
  if (cur > mx) mx = cur, mxi = x, mxpath = path;
  for (int i : G[x]) {
    if (!v[i]) DFS(i, cur + 1, path);
  }
}

void dfs(int x) {
  v[x] = true; ans++;
  for (int i : G[x]) if (!v[i]) dfs(i);
}
//         H
//         |
// A-B-C-D-E-F-G
//         |
//         I-J
