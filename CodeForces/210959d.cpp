#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5;
vector<int> G[maxn];
int A[maxn], N, zero, cycle, z;
bool b[maxn], v[maxn];

void DFS(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
    G[i].push_back(A[i]);
    if (!A[i]) zero++;
    if (!z && !A[i]) z = i;
    b[A[i]] = true;
  }
  if (zero >= 2 && zero & 1) { cout << "2\n"; return 0; }
  if (zero >= 2) { cout << "1\n"; return 0; }
  for (int i = 1; i <= N; ++i) if (!b[i]) {
    G[z].push_back(i);
    A[z] = i;
  }
  for (int i = 1; i <= N; ++i) if (!v[i]) DFS(i, i);
  // cout << "cycle: " << cycle << '\n';
  if ((N - cycle) & 1) cout << "1\n";
  else cout << "2\n";
  return 0;
}

void DFS(int x, int st) {
  v[x] = true;
  for (int u : G[x]) {
    if (u == st) { cycle++; return; }
    if (!v[u]) DFS(u, st);
  }
}
