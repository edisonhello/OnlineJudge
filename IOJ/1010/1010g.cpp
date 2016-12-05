#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

const int N = 500000, K = 1000000;
int D, X, Y;

int main() {
  freopen("in.txt", "w", stdout);
  cout << N << ' ' << K << endl;
  for (int i = 0; i < K; ++i) {
    D = rand() % 2 + 1; X = rand() % (N + 5) + 1; Y = rand() % (N + 5) + 1;
    cout << D << ' ' << X << ' ' << Y << endl;
  }
  return 0;
}
