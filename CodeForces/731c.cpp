#include <iostream>
#include <vector>
using namespace std;

const int maxn = 200000 + 5;
vector<int> G[maxn];
int N, M, K, C[maxn], l, r;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> N >> M >> K;
  for (int i = 0; i < N; ++i) cin >> C[i];
  while (M--) {
    cin >> l >> r;
    G[l].push_back(r);
    G[r].push_back(l);
  }
}
