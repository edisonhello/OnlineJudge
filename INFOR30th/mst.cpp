#include <bits/stdc++.h>
using namespace std;

const int N = 8, M = 20;
set<pair<int, int>> st;

int main() {
  srand(7122);
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (int i = 0; i < M; ++i) {
    int a = rand() % N, b = rand() % N;
    while (a == b || st.count(make_pair(a, b)) || st.count(make_pair(b, a))) a = rand() % N, b = rand() % N;
    cout << a << ' ' << b << ' ' << rand() % 10 + 1 << '\n';
    st.insert(make_pair(a, b));
  }
  return 0;
}
