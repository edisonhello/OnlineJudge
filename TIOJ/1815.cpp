#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5, maxa = 50000 + 5;
struct Toy {
  int w, h;
  bool operator<(const Toy& t) const {
    return h < t.h;
  }
} toy[maxn];
int A, B, T, X[maxa], Y[maxa];
priority_queue<Toy, vector<Toy>, less<Toy>> pq;

bool check(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> A >> B >> T;
  for (int i = 0; i < A; ++i) cin >> X[i];
  for (int i = 0; i < B; ++i) cin >> Y[i];
  sort(X, X + A); sort(Y, Y + B);
  for (int i = 0; i < T; ++i) cin >> toy[i].w >> toy[i].h;
  for (int i = 0; i < T; ++i) {
    if (toy[i].w >= X[A - 1] && toy[i].h >= Y[B - 1]) return cout << "-1\n", 0;
  }
  sort(toy, toy + T, [](const Toy& a, const Toy& b) -> bool {
    return a.w < b.w;
  });
  int d = 1, m = T;
  while (d <= T) d <<= 1;
  while (d >>= 1) if (m >= d) if (check(m - d)) m -= d;
  cout << m << '\n';
  return 0;
}

bool check(int t) {
  while (pq.size()) pq.pop();
  int p = 0;
  for (int i = 0; i < A; ++i) {
    int it = lower_bound(toy, toy + T, X[i], [](const Toy& t, const int& n) -> bool {
      return t.w < n;
    }) - toy - 1;
    for (int j = p; j <= it; ++j) pq.push(toy[j]);
    p = it + 1;
    for (int j = 0; j < t && pq.size(); ++j) pq.pop();
  }
  for (int i = p; i < T; ++i) pq.push(toy[i]);
  for (int i = B - 1; i >= 0; --i) {
    for (int j = 0; j < t && pq.size(); ++j) {
      if (pq.top().h >= Y[i]) return false;
      pq.pop();
    }
  }
  return pq.size() == 0;
}
