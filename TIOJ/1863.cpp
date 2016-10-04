#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;

vector<pii> G[150];
pii cod[150]
int N, x, y;

int dis(pii p1, pii p2) {
  return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}
int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> x >> y;
    cod[i] = pii(x, y);
  }
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      G[i].push_back(pii(j, dis(cod[i], cod[j])));
      G[j].push_back(pii(i, dis(cod[i], cod[j])));
    }
  }
}
