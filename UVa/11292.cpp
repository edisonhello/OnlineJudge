#include <iostream>
#include <algorithm>

int d[20005], k[20005], tot, it;

int main() {
  int N, M;
  std::cin.tie(0); std::ios_base::sync_with_stdio(false);
  while (std::cin >> N >> M, (N || M)) {
    tot = 0; it = 0;
    for (int i = 0; i < N; ++i) std::cin >> d[i];
    for (int i = 0; i < M; ++i) std::cin >> k[i];
    std::sort(d, d + N); std::sort(k, k + M);
    if (M < N) { std::cout << "Loowater is doomed!\n"; continue; }
    for (int i = 0; i < M && it < N; ++i) {
      if (k[i] >= d[it]) tot += k[i], it++;
    }
    if (it == N) std::cout << tot << '\n';
    else std::cout << "Loowater is doomed!\n";
  }
  return 0;
}
