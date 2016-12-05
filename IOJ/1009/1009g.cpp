#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

const int N = 1000, M = 300000, K = 1000;
int st, ed, A, B;
bool v[N + 5][N + 5];

int main() {
  freopen("in.txt", "w", stdout);
  cout << N << ' ' << M << endl;
  for (int i = 0; i < M; ++i) {
    st = rand() % N + 1; ed = rand() % N + 1;
    while (st == ed || v[st][ed]) st = rand() % N + 1; ed = rand() % N + 1;
    v[st][ed] = true;
    cout << st << ' ' << ed << endl;
  }
  A = rand() % N + 1; B = rand() % N + 1;
  while (A == B) A = rand() % N + 1; B = rand() % N + 1;
  cout << A << ' ' << B << ' ' << K << endl;
  return 0;
}
