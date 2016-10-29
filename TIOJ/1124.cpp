#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <tuple>
#include <iomanip>
using namespace std;

char c1, c2;
int k;
double tot1, tot2;
vector<tuple<int, double, int>> G[26];
bool v[26], p1, p2;
void init();
void DFS(int, double, bool);

int main() {
  init();
  while (cin >> c1 >> c2 >> k) {
    tot1 = 0.0; tot2 = 0.0;
    p1 = false; p2 = false;
    DFS(c1 - 'A', 1.0, false);
    if (p1 && p2) cout << fixed << setprecision(8) << tot2 / tot1 << endl;
    else cout << "No solution\n";
  }
}

void init() {
  G[0].push_back(make_tuple(1, 0.3, 1)); G[0].push_back(make_tuple(2, 0.67, 2)); G[0].push_back(make_tuple(3, 0.5, 3));
  G[1].push_back(make_tuple(5, 0.33, 4));
  G[2].push_back(make_tuple(3, 0.42, 5)); G[2].push_back(make_tuple(6, 0.1, 6));
  G[3].push_back(make_tuple(5, 0.54, 7)); G[3].push_back(make_tuple(9, 0.28, 8));
  G[4].push_back(make_tuple(7, 0.5, 9));
  G[5].push_back(make_tuple(4, 0.28, 10)); G[5].push_back(make_tuple(8, 0.2, 11));
  G[6].push_back(make_tuple(8, 0.23, 12)); G[6].push_back(make_tuple(9, 0.36, 13));
  G[7].push_back(make_tuple(11, 0.4, 14));
  G[8].push_back(make_tuple(11, 0.41, 15));
  G[9].push_back(make_tuple(11, 0.37, 16)); G[9].push_back(make_tuple(13, 0.47, 17));
  G[11].push_back(make_tuple(13, 0.5, 18));
}

void DFS(int x, double nw, bool p) {
  if (x == c2 - 'A') {
    tot1 += nw; p1 = true;
    if (p) tot2 += nw, p2 = true;
    return;
  }
  for (auto i : G[x]) {
    if (!v[get<0>(i)]) {
      if (get<2>(i) == k) DFS(get<0>(i), nw * get<1>(i), true);
      else DFS(get<0>(i), nw * get<1>(i), p);
    }
  }
}
