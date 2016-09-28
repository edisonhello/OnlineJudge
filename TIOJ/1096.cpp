#include <iostream>
#include <cstdio>
using namespace std;

int map[100][100];

int main() {
  int n; int mn;
  while (scanf("%d", &n)) {
    if (n == 0) break;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        scanf("%d", &map[i][j]);

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
          if ((map[j][i] != 0 && map[i][k] != 0) && (map[j][k] == 0 || map[j][k] > map[j][i] + map[i][k])) map[j][k] = map[j][i] + map[i][k];
   mn = -1;
   for (int i = 0; i < n; i++)
      if(map[i][i] != 0 && (map[i][i] < mn || mn == -1 )) mn = map[i][i];

   printf("%d\n", mn);
  }
}
