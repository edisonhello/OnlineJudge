#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <cstdio>
#include <utility>
#include <cstring>
//#define TP tuple<int, int, int, vector<tuple<int, int, int> > >
using namespace std;

typedef tuple<int, int, int, vector<tuple<int, int, int> > > TP;
int x, y, z, jizz;
bool mp[51][51][51];
bool v[51][51][51];
void BFS();
TP tmp;
int dir[18] = {1, 0, 0, 0, 1, 0, 0, 0, 1, -1, 0, 0, 0, -1, 0, 0, 0, -1};

int main() {
  cin >> x >> y >> z;
  memset(v, 0, sizeof(v));
  memset(mp, 0, sizeof(mp));
  for (int i = 0; i < z; ++i) for (int j = 0; j < y; ++j) for (int k = 0; k < x; ++k) cin >> jizz, mp[i + 1][j + 1][k + 1] = (jizz == 1);
  BFS();
  return 0;
}

void BFS() {
  queue<TP> q;
  vector<tuple<int, int, int> > vv;
  q.push(TP(1, 1, 1, vv));
  v[1][1][1] = true;
  while (q.size()) {
    tmp = q.front(), q.pop();
    get<3>(tmp).push_back(tuple<int, int, int>(get<0>(tmp), get<1>(tmp), get<2>(tmp)));
    if (get<0>(tmp) == x && get<1>(tmp) == y && get<2>(tmp) == z) {
      printf("(1,1,1)");
      for (int i = 1; i < get<3>(tmp).size(); ++i) {
        printf("->(%d,%d,%d)", get<0>(get<3>(tmp)[i]), get<1>(get<3>(tmp)[i]), get<2>(get<3>(tmp)[i]));
      }
      printf("\n");
      return;
    }
    for (int i = 0; i < 6; ++i) {
      if (get<0>(tmp) + dir[i * 3] <= x && get<0>(tmp) + dir[i * 3] >= 1 && get<1>(tmp) + dir[i * 3 + 1] <= y && get<1>(tmp) + dir[i * 3 + 1] >= 1 && get<2>(tmp) + dir[i * 3 + 2] <= z && get<2>(tmp) + dir[i * 3 + 2] >= 1) {
        if (!mp[get<2>(tmp) + dir[i * 3 + 2]][get<1>(tmp) + dir[i * 3 + 1]][get<0>(tmp) + dir[i * 3]]) {
          if (!v[get<0>(tmp) + dir[i * 3]][get<1>(tmp) + dir[i * 3 + 1]][get<2>(tmp) + dir[i *3 + 2]]) {
            v[get<0>(tmp) + dir[i * 3]][get<1>(tmp) + dir[i * 3 + 1]][get<2>(tmp) + dir[i * 3 + 2]] = true;
            q.push(TP(get<0>(tmp) + dir[i * 3], get<1>(tmp) + dir[i * 3 + 1], get<2>(tmp) + dir[i * 3 + 2], get<3>(tmp)));
          }
        }
      }
    }
  }
  if (!v[x][y][z]) printf("no route\n");
}
