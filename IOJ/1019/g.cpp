#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 100000;
const int MAX = 100000;
int x, a;

int main() {
  srand(time(NULL));
  freopen("in.txt", "w", stdout);
  cout << N << ' ' << 0 << '\n';
  for (int i = 0; i < N; ++i) cout << rand() % MAX << ' ';
}
