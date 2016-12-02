#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 1000000, M = 100000;
int c, L, R, L1, R1, L2, R2;

int main() {
  srand(time(NULL));
  freopen("in.txt", "w", stdout);
  cout << N << ' ' << M << endl;
  for (int i = 0; i < M; ++i) {
    c = rand() % 2 + 1; cout << c << ' ';
    if (c == 1) {
      L = rand() % N + 1; R = rand() % (N - L + 1);
      cout << L << ' ' << L + R << endl;
    }
    if (c == 2) {
      L1 = rand() % N + 1; R1 = rand() % (N - L + 1);
      L2 = rand() % (N - L1 - R1 + 1); R2 = rand() % (N - L1 - R1 - L2 + 1);
      cout << L1 << ' ' << L1 + R1 << ' ' << L1 + R1 + L2 << ' ' << L1 + R1 + L2 + R2 << endl;
    }
  }
  return 0;
}
