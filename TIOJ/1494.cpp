#include <iostream>
#include <algorithm>
using namespace std;

const long long int MOD = 1e9 + 7;

void power(long long int F[2][2], long long int n);

long long int fib(long long int n)
{
  long long int F[2][2] = {{1, 1}, {1, 0}};
  if(n == 0)
    return 0;
  power(F, n - 1);

  return F[0][0] % MOD;
}

void multiply(long long int F[2][2], int M[2][2])
{
  long long int x =  F[0][0] * M[0][0] + F[0][1] * M[1][0];
  long long int y =  F[0][0] * M[0][1] + F[0][1] * M[1][1];
  long long int z =  F[1][0] * M[0][0] + F[1][1] * M[1][0];
  long long int w =  F[1][0] * M[0][1] + F[1][1] * M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void power(long long int F[2][2], long long int n) {
 long long int i;
 int M[2][2] = {{1, 1}, {1, 0}};

 // n - 1 times multiply the matrix to {{1,0},{0,1}}
 for (i = 2; i <= n; i++)
   multiply(F, M);
}

long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a > b) return gcd(a % b, b);
  else return gcd(b % a, a);
}

int main() {
  long long int i, j;
  cin >> i >> j;
  cout << fib(gcd(i + 1, j + 1) ) << endl;
  return 0;
}
