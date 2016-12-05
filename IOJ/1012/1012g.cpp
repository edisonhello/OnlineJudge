#include <iostream>
#include <ctime>
#include <cstdlib>
#include <set>
// #include <unordered_set>
using namespace std;

typedef unsigned long long ull;

struct jizz {
  long long x, y, z;
  bool operator<(const jizz& j) const {
    return x < j.x;
  }
};

set<jizz> st;

const int N = 100000;
const ull MOD = 1000000001;
long long x, y, z;
// bool v[MOD * 2 + 5][MOD * 2 + 5][MOD * 2 + 5];
int mx, my, mz;

int main() {
  srand(time(NULL));
  freopen("in.txt", "w", stdout);
  cout << N << endl;
  for (int i = 0; i < N; ++i) {
    x = rand() * rand() % MOD; y = rand() * rand() % MOD; z = rand() * rand() % MOD;
    mx = rand() % 2, my = rand() % 2, mz = rand() % 2;
    if (mx) x = -x;
    if (my) y = -y;
    if (mz) z = -z;
    while (st.count({ x, y, z })) {
      x = rand() % MOD; y = rand() % MOD; z = rand() % MOD;
      mx = rand() % 2, my = rand() % 2, mz = rand() % 2;
      if (mx) x = -x;
      if (my) y = -y;
      if (mz) z = -z;
    }
    st.insert({ x, y, z });
    cout << x << ' ' << y << ' ' << z << endl;
    // v[x + MOD][y + MOD][z + MOD] = true;
  }
  return 0;
}
