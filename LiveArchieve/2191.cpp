#include <iostream>
#include <string>
#include <cstring>
#define int long long

int BIT[200005], N, x, y, A[200005], kase;
std::string cmd;
void modify(int, int);
int query(int);
inline int lowbit(int x) { return x & -x; }

signed main() {
  std::cin.tie(0); std::ios_base::sync_with_stdio(false);
  while (std::cin >> N, N) {
    memset(BIT, 0, sizeof(BIT)); memset(A, 0, sizeof(A));
    for (int i = 1; i <= N; ++i) std::cin >> A[i], modify(i, A[i]);
    std::cout << "Case " << ++kase << ":\n";
    while (std::cin >> cmd) {
      if (cmd[0] == 'M') std::cin >> x >> y, std::cout << query(y) - query(x - 1) << '\n';
      if (cmd[0] == 'S') std::cin >> x >> y, modify(x, y - A[x]), A[x] = y;
      if (cmd[0] == 'E') break;
    }
    std::cout << '\n';
  }
  return 0;
}

void modify(int pos, int x) {
  for (; pos <= N; pos += lowbit(pos)) BIT[pos] += x;
}

int query(int x) {
  int ret = 0;
  for (; x; x -= lowbit(x)) ret += BIT[x];
  return ret;
}
