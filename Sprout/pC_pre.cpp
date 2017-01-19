#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int maxn = 100000 + 5;
vector<int> G[maxn];
int A[maxn], X, Y, N, T[maxn];
long long Min;
bool v[maxn];
void DFS(int, long long, int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> A[i], T[A[i]] = i;
  cin >> X >> Y;
  for (int i = 1; i < N; ++i) G[i].push_back(i + 1), G[i + 1].push_back(i);
  G[1].push_back(N); G[N].push_back(1);
  Min = LLONG_MAX;
  DFS(X, 0, 0);
  cout << Min << '\n';
}

void DFS(int x, long long len, int p) {
  if (x == Y) { Min = min(Min, len); return; }
  v[x] = true;
  for (int u : G[x]) {
    if (v[u]) continue;
    int id = (x == N || u == N) && (x == 1 || u == 1) ? N : min(x, u);
    if (T[id] >= T[p]) DFS(u, len+T[id]-T[p], id);
    else DFS(u, len + T[id] + N - T[p], id);
  }
}
