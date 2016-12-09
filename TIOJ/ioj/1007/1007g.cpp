#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

const int N = 100, M = 100;
int v[N + 5][N + 5];

int main() {
  freopen("in.txt", "w", stdout);
  cout << N << ' ' << M << endl;
  while (M--) {
    c = rand() % 3;
    if (c == 0) {
      a = rand() % N; b = rand() % N;
      // while (a == b) b = rand() % N;
      if (a == b) b++;
      v[a][b]++; v[b][a]++;
      // vector.push_back({ a, b })
    }
    if (c == 1) {
      c = rand() % N; d = rand() % N;
      if ()
    }
  }
  return 0;
}
