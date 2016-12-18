#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000 + 5;
int pre[MAX], pos[MAX], a, b, N, M, BIT[MAX], k, c, clk;
vector<int> T[MAX];
void DFS(int);
int query(int);
void modify(int);

inline int lowbit(int i) { return i & -i; }

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    cin >> k;
    while (k--) cin >> c, T[i].push_back(c);
  }
  DFS(1);
  while (M--) {
    cin >> a >> b;
    if (a) cout << query(pre[b]) << '\n';
    else modify(pre[b]), modify(pos[b] + 1);
  }
  return 0;
}

void DFS(int x) {
  pre[x] = ++clk;
  for (int u : T[x]) DFS(u);
  pos[x] = clk;
}

int query(int x) {
  int ret = 0;
  while (x) {
    if (BIT[x]) ret = !ret;
    x -= lowbit(x);
  }
  return ret;
}

void modify (int x) {
  while (x <= N) {
    BIT[x] = !BIT[x];
    x += lowbit(x);
  }
}
