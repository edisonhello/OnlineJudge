#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
vector<int> G[maxn];
int N, len[maxn], dp[maxn];

void DFS(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    int a, b; cin >> a >> b;
    G[a].push_back(b); G[b].push_back(a);
  }
  DFS(1, 0);
  return 0;
}

void DFS(int x, int fa) {
  for (int i = )
}
