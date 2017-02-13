#include <iostream>
#include <cstring>
#define lowbit(x) (x & -x)
using namespace std;

const int maxn = 1000 + 5;
int T, BIT[maxn][maxn], N, Q, x, y, x1, y1, x2, y2;
char c;

void Init();
long long sum(int, int);
void add(int, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T;
  while (T--) {
    Init();
    cin >> N >> Q;
    while (Q--) {
      cin >> c;
      if (c == 'Q') cin >> x >> y, cout << sum(x, y) % 2 << '\n';
      if (c == 'C') {
        cin >> x1 >> y1 >> x2 >> y2;
        add(x1, y1, 1);
        add(x2 + 1, y1, -1);
        add(x1, y2 + 1, -1);
        add(x2 + 1, y2 + 1, 1);
      }
    }
    cout << '\n';
  }
  return 0;
}

void Init() {
  memset(BIT, 0, sizeof(BIT));
}

long long sum(int x, int y) {
  long long ret = 0;
  while (x) {
    for (int j = y; j; j -= lowbit(j)) ret += BIT[x][j];
    x -= lowbit(x);
  }
  return ret;
}

void add(int x, int y, int v) {
  while (x <= N) {
    for (int j = y; j <= N; j += lowbit(j)) BIT[x][j] += v;
    x += lowbit(x);
  }
}
