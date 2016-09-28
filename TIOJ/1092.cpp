#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

vector<int> G[10010];
int N, E, a, b;
int v[10010];
string s;

void DFS(int);

int main() {
  while (cin >> N >> E) {
    if (N == 0 && E == 0) break;
    for (int i = 0; i < E; ++i) {
      cin >> a >> b;
      G[a].push_back(b);
    }
    memset(v, 0, sizeof(v));
    cin >> s;
    if (s == "Mimi") v[1] = 1;
    else v[1] = 2;
    DFS(1);
    if (v[N - 1] == 1) cout << "Mimi" << endl;
    else cout << "Moumou" << endl;
  }
  return 0;
}

void DFS(int start) {
  for (int i = 0; i < G[start].size(); ++i) {
    if (!v[G[start][i]]) {
      if (v[start] == 1) v[G[start][i]] = 2;
      else v[G[start][i]] = 1;
      DFS(G[start][i]);
      break;
    }
  }
}
