#include <deque>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

struct CR {
  int student;
  bool lock;
  vector<int> door;
};

int dfs(int, int);
CR c[100000];
int d;
int MAX = 0;

int main() {
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> c[i].student;
    c[i].lock = false;
  }
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    c[a].door.push_back(b);
    c[b].door.push_back(a);
  }
  cin >> d;
  int total = dfs(0, 0);
  cout << total << endl;
  return 0;
}

int dfs(int x, int level) {
  if (level > d) return 0;
  // printf("%d\n", x);
  if (c[x].lock) return 0;;
  int target;
  c[x].lock = true;
  int total = c[x].student;
  c[x].student = 0;
  for (int i = 0; i < c[x].door.size(); ++i) {
    // printf("%d\n", c[x].door[i]);
    target = c[x].door[i];
    total += dfs(target, level + 1);
  }
  c[x].lock = false;
  return total;
}
