#include <cstdio>

const int _maxn = 100000 + 5;
int findSample(int, int[], int[], int[]);
int _N, _host[_maxn], _protocal[_maxn], _confidence[_maxn];

int main() {
  scanf("%d", &_N);
  for (int i = 1; i < _N; ++i) scanf("%d %d", _host + i, _protocal + i);
  for (int i = 0; i < _N; ++i) scanf("%d", _confidence + i);
  printf("%d\n", findSample(_N, _confidence, _host, _protocal));
}
