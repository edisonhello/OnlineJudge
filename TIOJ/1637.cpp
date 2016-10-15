#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int n, G;
long long cnt;
stack<pair<long long, int> > s;
pair<int, int> tmp;

int main() {
  cin >> n;
  s.push(make_pair(2147483648, -1));
  cnt = 0;
  for (int i = 0; i < n - 1; ++i) {
    cin >> G;
    while (s.top().first <= G) {
      tmp = s.top(), s.pop();
      cnt += 1ll * (G - tmp.first) * (tmp.second - s.top().second) * (n - i - 1);
    }
    cnt += 1ll * G * (n - i - 1);
    s.push(make_pair(G, i));
  }
  cout << cnt << endl;
  return 0;
}
