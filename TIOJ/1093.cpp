#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>
#include <bitset>
#define PDD pair<double, double>
using namespace std;

PDD vec[1000010];
int n, m, mxs;
double x, y, mx;
PDD tmp;
bitset<1000010> v;
void DFS(int, int);

double dis(PDD a, PDD b) {
  return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main() {
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    for (int i = 0; i < m; ++i) {
      cin >> x >> y;
      vec[i] = PDD(x, y);
    }
    v.reset();
    mx = 0;
    v[0] = true;
    DFS(0, 0);
    // mx = 0;
    // v.reset();
    // v[mxs] = true;
    // DFS(mxs, 0);
    printf("%.3lf\n", mx / 2);
  }
  return 0;
}

void DFS(int prev, int start) {
  if (dis(vec[prev], vec[start]) > mx) mx = dis(vec[prev], vec[start]);
  for (int i = 0; i < m; ++i) {
    if (i == start) continue;
    if (!v[i]) {
      v[i] = true;
      DFS(start, i);
    }
  }
}
