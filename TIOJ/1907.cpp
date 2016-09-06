#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

struct doll  {
  int w, h;
  int deg;
  int l;
};

doll d[20001];
bool mat[20001][20001];

int cmp(doll d1, doll d2) {
  if (d1.w < d2.w && d1.h < d2.h) return 1;
  if (d1.w > d2.w && d1.h > d2.h) return -1;
  return 0;
}

int main() {
  int t, m;
  scanf("%d\n", &t);
  while (t--) {
    memset(mat, false, sizeof(mat));
    scanf("%d\n", &m);
    for (int i = 0; i < m; ++i) {
      scanf("%d %d", &d[i].h, &d[i].w);
      d[i].l = 1;
      d[i].deg = 0;
    }
    queue<int> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        if (cmp(d[i], d[j]) > 0) {
          mat[i][j] = true;
          d[j].deg++;
        } else {
          mat[i][j] = false;
        }
      }
      if (d[i].deg == 0) q.push(i);
    }

    int temp;
    while (!q.empty()) {
      temp = q.front();
      for (int i = 0; i < m; ++i) {
        if (!mat[temp][i]) continue;
        if (d[i].l < d[temp].l + 1) {
          d[i].l = d[temp].l + 1;
        }
        d[i].deg--;
        if (d[i].deg == 0) q.push(i);
      }
      q.pop();
    }
    int maxx = 0;
    for (int i = 0; i < m; ++i) {
      if (d[i].l > maxx) maxx = d[i].l;
    }
    cout << maxx << endl;
  }
  return 0;
}
