#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#define int long long
using namespace std;

const int N = 2000;
const int MAX = 1e9;
int E, L;

signed main() {
  srand(time(NULL));
  freopen("in.txt", "w", stdout);
  cout << N << '\n';
  for (int i = 0; i < N; ++i) {
    E = (long long)rand() * (long long)rand() % MAX;
    L = E + (long long)rand() * (long long)rand() % (N - E + 1);
    cout << E << ' ' << L << '\n';
  }
  return 0;
}
