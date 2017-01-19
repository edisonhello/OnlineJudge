#include <iostream>
#include <vector>
#define lowbit(x) (x) & (-x)
using namespace std;

const int maxn = 1000000 + 5;
vector<int> T[maxn];
int N, Q, A, B, C, D, m, M[maxn], st[maxn], ed[maxn], dfs, t, BIT[maxn << 1];

void DFS(int, int);
void add(int, int);
int query(int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N >> Q;
  for (int i = 0; i < N - 1; ++i) {
    cin >> A >> B >> M[B];
    T[A].push_back(B);
    T[B].push_back(A);
  }
  DFS(0, -1);
  while (Q--) {
    cin >> t;
    if (!t) {
      cin >> D >> m;
      add(st[D] + 1, m - M[D]);
    } else {

    }
  }
}

void DFS(int x, int fa) {
  st[x] = ++dfs;
  for (int u : T[x]) if (u != fa) DFS(u, x);
  ed[x] = dfs;
}

void add(int x, int v) {
  while (x <= dfs) {
    BIT[x] += v;
    x += lowbit(x);
  }
}

int query(int x) {
  int ret = 0;
  while (x) {
    ret += BIT[x];
    x -= lowbit(x);
  }
  return ret;
}
