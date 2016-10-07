#include "lib1164.h"
#include <algorithm>
#include <vector>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;

typedef pair<int, int> pii;
int city[1000010], mx, mxstart, ansMx, ansMn;
vector<pii> G[1000010];
void DFS(int,int);
void graph(MAP);
bitset<1000010> v;

int main() {
  int N = init();
  for (int i = 0; i < 1000010; ++i) city[i] = i;
  auto mm = minmax_element(city, city + N, query);
  MAP MX = getct(*mm.first);
  MAP MN = getct(*mm.second);
  graph(MX);
  v.reset();
  mx = 0;
  v[0] = true;
  DFS(0, 0);
  mx = 0;
  v.reset();
  v[mxstart] = true;
  DFS(mxstart, 0);
  ansMx = mx;

  for (int i = 0; i < 1000010; ++i) G[i].clear();

  graph(MN);
  v.reset();
  mx = 0;
  v[0] = true;
  DFS(0, 0);
  mx = 0;
  v.reset();
  v[mxstart] = true;
  DFS(mxstart, 0);
  ansMn = mx;
  answer(ansMx, ansMn);
  return 0;
}

void graph(MAP m) {
  for (int i = 0; i < m.k; ++i) {
    // cout<<m.x[i]<<" "<<m.y[i]<<" "<<m.len[i]<<endl;
    G[m.x[i]].push_back(pii(m.y[i], m.len[i]));
    G[m.y[i]].push_back(pii(m.x[i], m.len[i]));
  }
}

void DFS(int start, int cnt) {
  if (cnt > mx) {mx = cnt; mxstart = start;}
  for (int i = 0; i < G[start].size(); ++i) {
    if (!v[G[start][i].first]) {
      v[G[start][i].first] = true;
      DFS(G[start][i].first, cnt + G[start][i].second);
    }
  }
}
