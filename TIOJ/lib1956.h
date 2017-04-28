#include <cstdio>

const int maxn = 200000 + 5;
int w[maxn];

int solve(int, int, int*, int, int*);

int main() {
  int n, l, u;
  scanf("%d %d %d", &n, &l, &u);
  for (int i = 0; i < n; ++i) scanf("%d", w + i);
  int *result = new int[n + 5];
  if (solve(l, u, w, n, result)) {
    puts("Found");
    for (int i = 0; ; ++i) {
      if (!result[i]) break;
      printf("%d ", result[i]);
    }
    puts("");
  } else puts("Not found");
  return 0;
}
