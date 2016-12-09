#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <fstream>
#define early(i) (i) * 2 + 1
#define late(i) (i) * 2

std::vector<int> G[4005];
int N, E[2005], L[2005], ub, lb, c, S[4005];
bool v[4005];
bool check(int);
bool DFS(int);

int main() {
  // std::cin.tie(0); std::ios_base::sync_with_stdio(false);
  // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
  while (std::cin >> N) {
    ub = lb = 0; memset(S, 0, sizeof(S));
    for (int i = 0; i < N; ++i) std::cin >> E[i] >> L[i], ub = std::max({ ub, E[i], L[i] });
    while (lb < ub) {
      int M = lb + ((ub - lb + 1) >> 1);
      if (check(M)) lb = M;
      else ub = M - 1;
    }
    std::cout << lb << '\n';
  }
  return 0;
}

bool check(int M) {
  memset(v, false, sizeof(v));
  for (int i = 0; i < 4005; ++i) G[i].clear();
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (std::abs(E[i] - E[j]) < M) G[early(i) ^ 1].push_back(early(j)), G[early(j) ^ 1].push_back(early(i));
      if (std::abs(E[i] - L[j]) < M) G[early(i) ^ 1].push_back(late(j)), G[late(j) ^ 1].push_back(early(i));
      if (std::abs(L[i] - E[j]) < M) G[late(i) ^ 1].push_back(early(j)), G[early(j) ^ 1].push_back(late(i));
      if (std::abs(L[i] - L[j]) < M) G[late(i) ^ 1].push_back(late(j)), G[late(j) ^ 1].push_back(late(i));
    }
  }
  for (int i = 0; i < N * 2; i += 2) {
    if (!v[i] && !v[i + 1]) {
      c = 0;
      if (!DFS(i)) {
        while (c) v[S[--c]] = false;
        if (!DFS(i + 1)) return false;
      }
    }
  }
  return true;
}

bool DFS(int x) {
  if (v[x ^ 1]) return false;
  if (v[x]) return true;
  v[x] = true;
  S[c++] = x;
  for (int u : G[x]) if (!DFS(u)) return false;
  return true;
}
