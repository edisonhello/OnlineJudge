#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Node {
  int num, id;
  bool operator<(const Node& node) const {
    return num < node.num;
  }
};

int n, a[205], tot, st, cnt;
vector<Node> d;
bool v[205];

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
  tot = n;
  while (tot) {
    d.clear();
    d.push_back((Node){ INT_MIN, -1 });
    for (int i = 0; i < n; ++i) {
      if (!v[i]) {
        if (a[i] > d[i].num) d.push_back((Node){ a[i], i });
        else *lower_bound(d.begin(), d.end(), (Node){ a[i], i }) = (Node){ a[i], i };
      }
    }
    for (auto i : d) if (i.id >= 0) v[i.id] = true;
    tot -= (d.size() - 1);
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}
