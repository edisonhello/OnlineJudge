#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
struct Seg { int L, R; } seg[maxn];
int N, K;
bool v[maxn];

bool check(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> K;
  for (int i = 0; i < N; ++i) cin >> seg[i].L >> seg[i].R;
  sort(seg, seg + N, [](const Seg& a, const Seg& b) -> bool {
    return a.L < b.L;
  });
  int d = 1, m = N;
  while (d <= N) d <<= 1;
  while (d >>= 1) if (m >= d) if (check(m - d)) m -= d;
  cout << m << '\n';
  return 0;
}

bool check(int x) {
  int ret = 0, cover = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> Max;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Min;
  memset(v, false, sizeof(v));
  for (int i = 0; i < N; ++i) {
    while (Min.size() && Min.top().first <= seg[i].L) {
      if (!v[Min.top().second]) --cover, v[Min.top().second] = true;
      Min.pop();
    }
    Max.push(make_pair(seg[i].R, i));
    Min.push(make_pair(seg[i].R, i));
    ++cover;
    if (cover > x) {
      while (v[Max.top().second]) Max.pop();
      v[Max.top().second] = true; Max.pop();
      --cover; ++ret;
    }
  }
  return ret <= K;
}
