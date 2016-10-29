#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const long long int Z = 1e9 + 7;

map<long long, long long> f;

long long F(long long n){
  if(f.count(n)) return f[n];
  long long k = n / 2;
  if(n % 2 == 0) return f[n] = (F(k) * F(k) % Z + F(k - 1) * F(k - 1) % Z) % Z;
  else return f[n] = (F(k) * F(k + 1) % Z + F(k - 1) * F(k) % Z) % Z;
}

long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a > b) return gcd(a % b, b);
  else return gcd(b % a, a);
}

int main() {
  f[1] = 1; f[2] = 2;
  long long int i, j;
  cin >> i >> j;
  long long g = gcd(i + 1, j + 1) - 1;
  f[0] = 1;
  f[1] = 1;
  f[2] = 2;
  cout << F(g) << endl;
  return 0;
}
