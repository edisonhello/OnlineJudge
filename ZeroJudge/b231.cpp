#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;

struct Book {
  int a, b;
  bool operator<(const Book& rhs) const {
    return a + b < rhs.a + rhs.b;
  }
} b[maxn];

int n;
priority_queue<int> pq;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> b[i].a >> b[i].b;
  sort(b, b + n);
  int p = 0;
  for (int i = n - 1; i >= 0; --i) pq.push(b[i].a + b[i].b + p), p += b[i].a;
  cout << pq.top() << '\n';
  return 0;
}
