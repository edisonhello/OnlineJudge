#include <iostream>
#include <cstring>
#include <algorithm>

const int INF = 1<<30;
int N, W[105][105], Lx[105], Ly[105], match[105], ans;
bool S[105], T[105];
bool DFS(int);
void update();

int main() {
  std::cin.tie(0); std::ios_base::sync_with_stdio(false);
  while (std::cin >> N, N) {
    memset(W, 0, sizeof(W));
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) std::cin >> W[i][j];
    memset(S, false, sizeof(S)); memset(T, false, sizeof(T));
    memset(Lx, 0, sizeof(Lx)); memset(Ly, 0, sizeof(Ly));
    memset(match, 0, sizeof(match));
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) Lx[i] = std::max(Lx[i], W[i][j]);
    for (int i = 1; i <= N; ++i) {
      while (true) {
        memset(S, false, sizeof(S)); memset(T, false, sizeof(T));
        if (DFS(i)) break;
        else update();
      }
    }
    ans = 0;
    for (int i = 1; i <= N; ++i) ans += W[i][match[i]] > 0 ? W[i][match[i]] : 0;
    std::cout << ans << '\n';
  }
  return 0;
}

bool DFS(int i) {
  S[i] = true;
  for (int j = 1; j <= N; ++j) {
    if (Lx[i] + Ly[j] == W[i][j] && !T[j]) {
      T[j] = true;
      if (!match[j] || DFS(match[j])) {
        match[j] = i;
        return true;
      }
    }
  }
  return false;
}


void update() {
  int a = INF;
  for (int i = 1; i <= N; ++i) if (S[i]) {
    for (int j = 1; j <= N; ++j) if (!T[j]) {
      a = std::min(a, Lx[i] + Ly[j] - W[i][j]);
    }
  }
  for (int i = 1; i <= N; ++i) {
    if (S[i]) Lx[i] -= a;
    if (T[i]) Ly[i] += a;
  }
}
