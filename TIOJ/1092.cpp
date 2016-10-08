#include <iostream>
#include <vector>
#include <cstring>
#include <bitset>
#include <cstdio>
#include <string>
#include <queue>
#define getchar getchar_unlocked
using namespace std;

int N, E, a, b, __t, tmp, in[10010], i;
char __c;
vector<int> G[10010];
string name;
bitset<10010> victory;
bool ans;

inline int rit() {
  __t = 0;
  do {
    __c = getchar();
  } while (__c < '0' || __c > '9');
  do {
    __t = __t * 10 + __c - '0';
    __c = getchar();
  } while (__c >= '0' && __c <= '9');
  return __t;
}

bool topo() {
  queue<int> q;
  q.push(N);
  victory.set();
  while (!q.empty()) {
    tmp = q.front(), q.pop();
    if (victory[tmp]) {
      for (i = 0; i < G[tmp].size(); ++i) {
        victory[G[tmp][i]] = false;
        in[G[tmp][i]]--;
        if (!in[G[tmp][i]]) q.push(G[tmp][i]);
      }
    } else {
      for (i = 0; i < G[tmp].size(); ++i) {
        in[G[tmp][i]]--;
        if (!in[G[tmp][i]]) q.push(G[tmp][i]);
      }
    }
  }
  return victory[1];
}

int main() {
  while (scanf("%d %d", &N, &E) != EOF) {
    if (N == 0 && E == 0) break;
    memset(in, 0, sizeof(in));
    for (i = 0; i <= N; ++i) G[i].clear();
    for (i = 0; i < E; ++i) {
      a = rit(), b = rit();
      G[b].push_back(a);
      in[a]++;
    }
    cin >> name;
    ans = topo();
    if (name == "Mimi") {
      if (ans) printf("Mimi\n");
      else printf("Moumou\n");
    } else {
      if (ans) printf("Moumou\n");
      else printf("Mimi\n");
    }
  }
  return 0;
}
