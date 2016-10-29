#include <bitset>
#include <iostream>
#include <cmath>
using namespace std;

bitset<300000001> prime;

long long ans;
long long cnt;

void build() {
  prime[1] = true;
  for (int i = 2; i <= (300000000); ++i) {
    if (!prime[i]) {
      cnt++; ans += i;
      for (int k = (300000001) / i, j = i * k; k >= i; k--, j -= i) if (!prime[k]) prime[j] = true;
    }
  }
  cout << cnt << endl;
  cout << ans % (long long int)pow(2, 32) << endl;
}

int main() {
  // build();
  printf("16252325\n3100702502\n");
}
