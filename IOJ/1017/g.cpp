#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 1000000;

int main() {
  srand(time(NULL));
  freopen("in.txt", "w", stdout);
  cout << N << '\n';
  for (int i = 0; i < N; ++i) cout << rand() % 100 + 1 << ' ';
}
