#include <iostream>
#include <bitset>
using namespace std;

int djs[50010], n, m, a, b, cnt, Case;
bitset<50010> v;

int F(int x) {return x == djs[x] ? x : djs[x] = F(djs[x]);}

void U(int a, int b) {
  a = F(a), b = F(b);
  djs[a] = b;
}

int main() {
  cin.tie(0);
  Case = 1;
  ios_base::sync_with_stdio(false);
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    v.reset();
    for (int i = 0; i <= n; ++i) djs[i] = i;
    for (int i = 0; i < m; ++i) {
      cin >> a >> b;
      U(a, b);
    }
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
      if (!v[F(i)]) v[F(i)] = true, cnt++;
    }
    printf("Case %d: %d\n", Case++, cnt);
  }
  return 0;
}
