#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <algorithm>
// #include <map>
using namespace std;

const int N = 10000;
const int M = 10000;
int t, a, b, c, d, K;
int cnt[N + 5][N + 5];
bool v[N + 5];
int A[N + 5];

int main() {
  freopen("in.txt", "w", stdout);
  srand(time(NULL));
  cout << N << ' ' << M << endl;
  for (int i = 0; i < N; ++i) A[i] = i;
  for (int i = 0; i < M; ++i) {
    t = rand() % 3;
    cout << t << ' ';
    if (t == 0) {
      a = rand() % N; b = rand() % N;
      cout << a << ' ' << b << endl;
      cnt[a][b]++; cnt[b][a]++;
    }
    if (t == 1) {
      c = rand() % N; d = rand() % N;
      int jizz = 0;
      while ((!cnt[c][d] || !cnt[d][c]) && jizz < 100) {
        c = rand() % N; d = rand() % N;
        jizz++;
      }
      if (jizz == 100) {i--; continue; }
      // while (!cnt[c][d] || !cnt[d][c]) {
      //   c = rand() % N; d = rand() % N;
      // }
      cout << c << ' ' << d << endl;
      cnt[c][d]--; cnt[d][c]--;
    }
    if (t == 2) {
      K = rand() % N + 1;
      random_shuffle(A, A + N);
      for (int j = 0; j < K; ++j) cout << A[j] << ' ';
      cout << endl;
    }
  }
  return 0;
}
