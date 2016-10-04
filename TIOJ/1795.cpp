#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Jizz {
  int x, y, k;
};

vector<Jizz> vec(300010);

bool cmp1(const Jizz& a, const Jizz& b) {return a.k == b.k ? a.x == b.x ? a.y < b.y : a.x < b.x : a.k < b.k;}
bool cmp2(const Jizz& a, const Jizz& b) {return a.k == b.k ? a.x == b.x ? a.y < b.y : a.x < b.x : a.k > b.k;}

int djs[100010];

int F(int a) {
  if (djs[a] == a) return a;
  return djs[a] = F(djs[a]);
}

int n, m, k, ans, cnt, i, x, y, mn, mx, t;
char c;

inline int rit() {
  t = 0;
  do {
    c = getchar_unlocked();
  } while (c < '0' || c > '9');
  do {
    t = t * 10 + c - '0';
    c = getchar_unlocked();
  } while (c >= '0' && c <= '9');
  return t;
}

int Kruskal() {
  ans = 0, cnt = 1;
  for (i = 1; i <= n; ++i) djs[i] = i;
  for (i = 0; i < vec.size(); ++i) {
    x = F(vec[i].x); y = F(vec[i].y);
    if (x == y) continue;
    djs[x] = y; ans += vec[i].k;
    if (++cnt == n) return ans;
  }
}

int main() {
  n = rit(), m = rit(), k = rit();
  for (i = 0; i < m; ++i) vec[i].x = rit(), vec[i].y = rit(), vec[i].k = rit();
  sort(vec.begin(), vec.end(), cmp1);
  mn = Kruskal();
  sort(vec.begin(), vec.end(), cmp2);
  mx = Kruskal();
  if (k <= mx && k >= mn) printf("TAK\n");
  else printf("NIE\n");
  return 0;
}
