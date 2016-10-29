#include <cstdio>
#include <algorithm>
using namespace std;

struct Node {
  int num;
  int pos;

  bool operator<(const Node& node) const {
    return node.num < num;
  }
};

bool cmp(Node a, Node b) {
  return a.num < b.num;
}

int main() {
  int n, len, ans;
  scanf("%d", &n);
  Node a[1000000];
  for (int i = 0; i < n; ++i) {
    ans = 0;
    scanf("%d", &len);
    for (int j = 0; j < len; ++j) {
      scanf("%d", &a[j].num);
      a[j].pos = j;
    }
    sort(a, a + len, cmp);
    for (int j = 1; j < len - 1; ++j) {
      if (j == a[j].pos) ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
