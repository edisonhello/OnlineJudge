#include <iostream>
#include <cstdio>
using namespace std;

int BIT[1030][1030];
int n, x, y, z, x1, y1, x2, y2, c;
void add(int, int, int);
int sum(int, int);
inline int lowbit(int x) { return x & -x; }

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n;
  while (cin >> c) {
    if (c == 1) {
      cin >> x >> y >> z;
      x++, y++;
      add(x, y, z);
    } else {
      cin >> x1 >> y1 >> x2 >> y2;
      x1++; y1++; x2++; y2++;
      cout << sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1) << endl;
    }
  }
  return 0;
}

void add(int x, int y, int z) {
  while (x <= n) {
    for (int i = y; i <= n; i += lowbit(i)) BIT[x][i] += z;
    x += lowbit(x);
  }
}

int sum(int x, int y) {
  int ret = 0;
  while (x) {
    for (int i = y; i; i -= lowbit(i)) ret += BIT[x][i];
    x -= lowbit(x);
  }
  return ret;
}
