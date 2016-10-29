#include <iostream>
#include <vector>
#include <bitset>
#include <cstring>
using namespace std;

int n, m, Q, L, s, e, a, b, cnt;
vector<int> G[150];
// bitset<150> v;
int v[150], c[150];
void query(int, int);

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> Q >> L;
  for (int i = 0; i < m; ++i) {
    cin >> s >> e;
    c[e]++;
    G[s].push_back(e);
  }
  for (int i = 0; i < Q; ++i) {
    cin >> a >> b;
    // v.reset();
    memset(v, 0, sizeof(v));
    // v[a] = true;
    v[a]++;
    cnt = 0; query(a, 0);
    cout << cnt << endl;
  }
  return 0;
}

void query(int x, int nw) {
  cout << "x: " << x << " nw: " << nw << endl;
  if (nw == L && x == b) { cnt++; return; }
  if (nw > L) return;
  for (auto i : G[x]) {
    if (v[i] < c[i]) v[i]++, query(i, nw + 1);
  }
}
