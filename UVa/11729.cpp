#include <iostream>
#include <algorithm>

struct S {
  int b, j;
} s[1005];

int N, st, ed, kase;

int main() {
  std::cin.tie(0); std::ios_base::sync_with_stdio(false);
  while (std::cin >> N, N) {
    for (int i = 0; i < N; ++i) std::cin >> s[i].b >> s[i].j;
    std::sort(s, s + N, [](const S& a, const S& b) -> bool {
      return a.j > b.j;
    });
    st = 0; ed = 0;
    for (int i = 0; i < N; ++i) {
      st += s[i].b;
      ed = std::max(ed, st + s[i].j);
    }
    std::cout << "Case " << ++kase << ": " << ed << '\n';
  }
  return 0;
}
