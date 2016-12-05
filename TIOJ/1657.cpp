#include <cstdio>
using namespace std;

int N, M;

int main() {
  while (~scanf("%d %d", &N, &M)) {
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= M; ++j) {
        printf("%d*%d=%d ", i, j, i * j);
      }
      printf("\n");
    }
  }
  return 0;
}
