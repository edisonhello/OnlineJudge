#include <cstdio>
#define getchar getchar_unlocked
using namespace std;

int map[100][100], __t, n, mn;
char __c;

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

int main() {
  while (scanf("%d", &n) != EOF) {
    if (n == 0) break;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) map[i][j] = rit();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if ((map[j][i] != 0 && map[i][k] != 0) && (map[j][k] == 0 || map[j][k] > map[j][i] + map[i][k])) map[j][k] = map[j][i] + map[i][k];
        }
      }
    }
   mn = -1;
   for (int i = 0; i < n; i++) if(map[i][i] != 0 && (map[i][i] < mn || mn == -1 )) mn = map[i][i];
   printf("%d\n", mn);
  }
  return 0;
}
