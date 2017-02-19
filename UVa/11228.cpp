#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int T, N, R, djs[2][maxn], comp, kase;
struct Edge { int from, to; double cost; };
struct Point { int x, y; } p[maxn];
double road, rail;
bool v[maxn];
vector<Edge> e;

void Init();
inline double dis(int, int);
int F(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  while (T--) {
    Init();
    cin >> N >> R;
    for (int i = 0; i < N; ++i) cin >> p[i].x >> p[i].y;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        double d = dis(i, j);
        if (d <= R) djs[0][F(i, 0)] = F(j, 0);
        e.push_back((Edge){ i, j, d });
      }
    }
    sort(e.begin(), e.end(), [](const Edge& a, const Edge& b) -> bool {
      return a.cost < b.cost;
    });
    for (Edge i : e) {
      if (F(i.from, 1) == F(i.to, 1)) continue;
      if (i.cost <= R) road += i.cost;
      else rail += i.cost;
      djs[1][F(i.from, 1)] = F(i.to, 1);
    }
    for (int i = 0; i < N; ++i) if (!v[F(i, 0)]) v[F(i, 0)] = true, ++comp;
    cout << "Case #" << ++kase << ": " << comp << ' ' << round(road) << ' ' << round(rail) << '\n';
  }
  return 0;
}

void Init() {
  e.clear();
  memset(p, 0, sizeof(p));
  memset(v, false, sizeof(v));
  for (int i = 0; i < maxn; ++i) djs[0][i] = i, djs[1][i] = i;
  road = 0.0; rail = 0.0; comp = 0;
}

inline double dis(int a, int b) {
  return sqrt((p[a].x - p[b].x) * (p[a].x - p[b].x) + (p[a].y - p[b].y) * (p[a].y - p[b].y));
}

int F(int x, int i) { return djs[i][x] == x ? x : djs[i][x] = F(djs[i][x], i); }
