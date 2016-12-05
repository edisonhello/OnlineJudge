#include <iostream>
#include <vector>
#include <algorithm>
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
    for (int i = 0; i < n; ++i) {
      if (!v[i]) { d.push_back((Node){ a[i], i }); break; }
    }
    for (int i = d.begin()->id + 1; i < n; ++i) {
      if (!v[i]) {
        if (a[i] > d.back().num) d.push_back((Node){ a[i], i });
        else *lower_bound(d.begin(), d.end(), (Node){ a[i], i }) = (Node){ a[i], i };
      }
    }
    tot -= d.size();
    for (int i = 0; i < d.size(); ++i) v[d[i].id] = true;
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}
