#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct W {
  short e, d;
  W(short e, short d): e(e), d(d) {}
  W() {}
  bool operator < (const W& w) const {
    return (d == w.d) ? (e < w.e) : (d < w.d);
  }
};

vector<W> vec;
short N, t, M, i, e, d, cur;
char c;
bool reach;
inline short rit();

int main() {
  N = rit();
  while (N--) {
    vec.clear();
    M = rit();
    vec.reserve(M);
    for (i = 0; i < M; ++i) {
      e = rit(), d = rit();
      vec.push_back(W(e, d));
    }
    sort(vec.begin(), vec.end());
    cur = 0;
    reach = true;
    for (i = 0; i < M; ++i) {
      if (vec[i].e + cur <= vec[i].d) {
        cur += vec[i].e;
      } else {
        reach = false;
        break;
      }
    }
    if (reach) printf("schedulable\n");
    else printf("unschedulable\n");
  }
  return 0;
}

inline short rit() {
  t = 0;
  do {
    c = getchar_unlocked();
  } while (c < '0' || c > '9');
  do {
    t = t * 10 + c - '0';
    c = getchar_unlocked();
  } while (c >= '0' && c <= '9');
  return t;
}
