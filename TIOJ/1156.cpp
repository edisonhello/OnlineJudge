#include <iostream>
using namespace std;

int gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a > b) return gcd(a % b, b);
  else return gcd(b % a, a);
}

int N, g, x;

int main() {
  cin >> N;
  cin >> g;
  for (int i = 1; i < N; ++i) {
    cin >> x;
    g = gcd(g, x);
  }
  cout << g << endl;
}
