#include <iostream>
#include <cmath>
using namespace std;


// int dp[100000001];
long long int d;
char sol[100000000];

int s(long long int n) {
  for (int i = 0; i <= 100; ++i) {
    if (pow(2, i) <= n && pow(2, i) > n) {
      return i;
    }
  }
}

int main() {
  cin >> d;
  while (d > 0) {
    sol[s(d)] = '+';
    d -= s(d);
  }
}
