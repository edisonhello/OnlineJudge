#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 200 + 5;
const int maxe = maxn * maxn / 2;

struct Edge {
  int id, st, ed;
} E[maxe];

int T, N, M, deg[maxn], In[maxn], Out[maxn], ans;
vector<Edge> G[maxn];
bool mod[maxe];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> N >> M;
    for (int i = 1; i <= M; ++i) G[i].clear();
    memset(In, 0, sizeof(In));
    memset(Out, 0, sizeof(Out));
    memset(deg, 0, sizeof(deg));
    memset(mod, false, sizeof(mod));
    for (int i = 0; i < M; ++i) {
      cin >> E[i].st >> E[i].ed;
      E[i].id = i;
      G[E[i].st].push_back(E[i]);
      G[E[i].ed].push_back(E[i]);
      deg[E[i].st]++;
      deg[E[i].ed]++;
    }
    for (int i = 1; i <= N; ++i) {
      if (deg[i] & 1) continue;
      if (!deg[i]) continue;
      int in = 0, out = 0;;
      for (auto e : G[i]) {
        if (mod[e.id]) continue;
        int con = e.st == i ? e.ed : e.st;
        if (deg[con] & 1) {
          if (Out[i] >= deg[i] / 2) {
            E[e.id].st = con; E[e.id].ed = i;
            Out[con]++; In[i]++;
          } else {
            E[e.id].st = i; E[e.id].ed = con;
            Out[i]++; In[con]++;
          }
        } else {
          if (In[con] >= deg[con] / 2 || Out[i] >= deg[i] / 2) {
            E[e.id].st = con; E[e.id].ed = i;
            Out[con]++; In[i]++;
          } else {
            E[e.id].st = i; E[e.id].ed = con;
            Out[i]++; In[con]++;
          }
        }
        mod[e.id] = true;
      }
    }
    for (int i = 0; i < M; ++i) if (!mod[i]) {
      mod[i] = true;
      Out[E[i].st]++;
      In[E[i].ed]++;
    }
    ans = 0;
    for (int i = 1; i <= N; ++i) if (In[i] == Out[i]) ans++;
    cout << ans << '\n';
    for (int i = 0; i < M; ++i) cout << E[i].st << ' ' << E[i].ed << '\n';
  }
  return 0;
}

/*

dp[i] = 

*/
