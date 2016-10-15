#include <iostream>
#include <bitset>
#include <utility>
#include <vector>
#include <cstdio>
using namespace std;

bitset<20000010> prime;
vector<pair<int, int> > v;
int s;

void build() {
  prime.set();
  prime[0] = false;
  prime[1] = false;
  for (int i = 2; i <= 20000000; ++i) {
    if (prime[i]) {
      for (int j = i * i; j <= 20000000; j += i) prime[j] = false;
      if (prime[i - 2]) v.push_back(pair<int, int>(i - 2, i));
    }
  }
}

int main() {
  build();
  cout << v.size() << endl;
  while (cin >> s) {
    printf("(%d, %d)\n", v[s - 1].first, v[s - 1].second);
  }
  return 0;
}
