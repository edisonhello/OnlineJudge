#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
  long long int num;
  int r, c;
  Node(long long int num, int r, int c): num(num), r(r), c(c){}
  Node() {}
  bool operator < (const Node& n) const {
    return num < n.num;
  }
};
priority_queue<Node> pq;
int m, n;
bool b[1000][1000] = {false};
long long int mp[1000][1000];
long long int num;
Node ntmp;
int main() {
  cin >> m >> n;
  for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {cin >> num; mp[i][j] = num; pq.push(Node(num, i, j));}
  long long int cnt = 0;
  while (!pq.empty()) {
    ntmp = pq.top();
    cnt += ntmp.num;
    b[ntmp.r][ntmp.c] = true;
    if (ntmp.r + 1 < m && b[ntmp.r + 1][ntmp.c]) cnt += mp[ntmp.r + 1][ntmp.c];
    if (ntmp.r - 1 >= 0 && b[ntmp.r - 1][ntmp.c]) cnt += mp[ntmp.r - 1][ntmp.c];
    if (ntmp.c + 1 < n && b[ntmp.r][ntmp.c + 1]) cnt += mp[ntmp.r][ntmp.c + 1];
    if (ntmp.c - 1 >= 0 && b[ntmp.r][ntmp.c - 1]) cnt += mp[ntmp.r][ntmp.c - 1];

    pq.pop();
  }
  cout << cnt << endl;
  return 0;
}
