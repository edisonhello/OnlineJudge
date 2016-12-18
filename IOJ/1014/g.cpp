#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

long long N = 1000000000000000000;
long long M = 100;

int main() {
  srand(time(NULL));
  freopen("in.txt", "w", stdout);
  cout << N << ' ' << M << '\n';
  for (int i = 0; i < M; ++i) cout << rand() % 1000 + 1 << ' ';
  return 0;
}