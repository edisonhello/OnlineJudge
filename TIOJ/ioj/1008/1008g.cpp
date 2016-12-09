#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 500;
const int K = 10000;
bool v[501][501];
int x, y;

int main() {
  srand(time(NULL));
  freopen("in.txt", "w", stdout);
  cout << N << ' ' << K << endl;
  for (int i = 0; i < K; ++i) {
    x = rand() % N + 1; y = rand() % N + 1;
    while (v[x][y]) x = rand() % N + 1; y = rand() % N + 1;
    cout << x << ' ' << y << endl;
    v[x][y] = true;
  }
  return 0;
}
