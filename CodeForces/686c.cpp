#include <iostream>
#include <cmath>
using namespace std;

int n, m;
int d[2], f[2];

int solve(int, int);

int main() {
  cin >> n >> m;
  d[0] = ceil(log10(n) / log10(7));
  d[1] = ceil(log10(m) / log10(7));
  f[0] = n % (int)(pow(7, d[0] - 1));
  f[1] = m % (int)(pow(7, d[1] - 1));
  
}
