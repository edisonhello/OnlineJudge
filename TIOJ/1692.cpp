#include "lib1692.h"
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

struct Edge {
  int st, ed;
};

int V, E, V1, V2, tot, start, cnt, sz[1005], leave[50005];
Edge edge[50005];
vector<int> ans;
bool v[50005];
vector<pair<int, int>> G[1005];
void DFS(int);

int main() {
  Init();
  GetVE(V, E);
  for (int i = 1; i <= E; ++i) {
    Get(V1, V2);
    G[V1].push_back({ V2, i });
    G[V2].push_back({ V1, i });
    sz[V1]++; sz[V2]++;
    edge[i] = (Edge){ V1, V2 };
  }
  while (true) {
    if (tot >= E) break;
    for (int i = 1; i <= V; ++i) {
      if (sz[i] & 1) {
          start = i;
          break;
      }
    }
    cnt = 0; ans.clear();
    DFS(start);
    tot += cnt - 1;
    ReportVst(start);
    for (int i = 0; i < ans.size(); ++i) {
      ReportE(ans[i]);
      sz[edge[ans[i]].st]--;
      sz[edge[ans[i]].ed]--;
    }
    ReportVed(leave[0]);
  }
  Final();
  return 0;
}

void DFS(int x) {
  //cout << x << endl;
  for (auto i : G[x]) {
    if (!v[i.second]) {
        v[i.second] = true;
        ans.push_back(i.second);
        DFS(i.first);
    }
  }
  leave[cnt++] = x;
}
