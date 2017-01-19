#include <bits/stdc++.h>
using namespace std;

unsigned long long a, b;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> a >> b) {
    cout << (unsigned long long)(log(b) / log(a)) << '\n';
  }
  return 0;
}
