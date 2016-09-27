#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int t, k, n, x, i;
char c;
vector<int> vec;

inline int rit() {
  t = 0; k = 1;
  do {
    c = getchar();
    if (c == '-') k = -1;
  } while (c < '0' || c > '9');
  do {
    t = t * 10 + c - '0';
    c = getchar();
  } while (c >= '0' && c <= '9');
  return t * k;
}

int main() {
  while (scanf("%d", &n) != EOF) {
    vec.clear();
    for (i = 0; i < n; ++i) {x = rit(); vec.push_back(x);}
    sort(vec.begin(), vec.end());
    for (i = 0; i < n; ++i) {printf("%d", vec[i]); if (i != n - 1) printf(" "); else printf("\n");}
  }
  return 0;
}
