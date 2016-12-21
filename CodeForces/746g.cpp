#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200000 + 5;
int n, t, k, a[MAXN], id, leaf;
vector<int> T[MAXN], R[MAXN], L[MAXN];
void DFS1(int);
void DFS2(int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n >> t >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  id = 2;
  L[0].push_back(1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < a[i]; ++j) {
      L[i].push_back(id++);
    }
    int k = 0;
    for (int j = 0; j < L[i].size(); ++j) {
      T[L[i - 1][k]].push_back(L[i][j]);
      R[L[i][j]].push_back(L[i - 1][k]);
      k++;
      if (k == L[i - 1].size()) k = 0;
    }
  }
  DFS1(1);
  DFS2(1);
}

void DFS1(int x) {
  if (T[x].size() == 0) leaf++;
  for (int c : T[x]) DFS(c);
}

void DFS2(int x) {
  for (int c : T[x])
}
