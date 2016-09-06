#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#define pii pair<int, int>
using namespace std;
vector<pii> vec;
inline int rit() {
  int t = 0, k = 1;
  char c;
  do {
    c = getchar();
    if (c == '-') k = -1;
  } while (c < '0' || c > '9');
  do {
    t = t * 10 + (c - '0');
    c = getchar();
  } while (c >= '0' && c <= '9');
  return t * k;
}
int find(pii p) {
  int left = 0;
  int right = vec.size() - 1;
  int mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (vec[mid] < p) {
      left = mid + 1;
    } else if (vec[mid] > p) {
      right = mid - 1;
    } else {
      return mid;
    }
  }
  return -1;
}
int main() {
  int n, m, q;
  int a, b, c, d;
  n = rit();
  m = rit();
  q = rit();
  for (int i = 0; i < m; ++i) {
    a = rit();
    b = rit();
    vec.push_back(pii(a, b));
    vec.push_back(pii(b, a));
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < q; ++i) {
    c = rit();
    d = rit();
    // cout << find(pii(c, d)) << endl;
    if (find(pii(c, d)) < 0) {
      printf("no\n");
    } else {
      printf("yes\n");
    }
  }
  return 0;
}
