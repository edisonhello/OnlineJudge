#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int maxn = 512 + 5;
string mt[maxn];
int M, N, cnt;
bool v[maxn][maxn];
void DFS(int, int);
short di[8] = { 1, 0, -1, 0, 1, 1, -1, -1 }, dj[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> M >> N;
  for (int i = 0; i < M; ++i) cin >> mt[i];
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      if (!v[i][j] && mt[i][j] == '1') DFS(i, j), cnt++;
    }
  }
  if (cnt > 20) cout << 10 << '\n';
  else {
    if (cnt == 0) cout << 0 << '\n';
    else if (cnt <= 1) cout << 1 << '\n';
    else if (cnt <= 2) cout << 2 << '\n';
    else if (cnt <= 4) cout << 3 << '\n';
    else if (cnt <= 6) cout << 4 << '\n';
    else if (cnt <= 10) cout << 5 << '\n';
    else cout << ceil((double)cnt / 2) << '\n';
  }
  return 0;
}

void DFS(int i, int j) {
  v[i][j] = true;
  for (int x = 0; x < 8; ++x) {
    if (i + di[x] >= 0 && i + di[x] < M && j + dj[x] >= 0 && j + dj[x] < N && mt[i + di[x]][j + dj[x]] == '1') {
      if (!v[i + di[x]][j + dj[x]]) DFS(i + di[x], j + dj[x]);
    }
  }
}
