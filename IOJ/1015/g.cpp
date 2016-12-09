#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

const int N = 1000;
const int MAX = 10000;
int c, x;

int main() {
  srand(time(NULL));
  freopen("in.txt", "w", stdout);
  cout << N << endl;
  for (int i = 0; i < N; ++i) {
    c = rand() % 2; x = rand() % MAX;
    if (c) cout << x << ' ';
    else cout << -x << ' ';
    // cout << rand()
  }
  return 0;
}
