#include <cstdio>
#include <utility>
using namespace std;

int N, A[1000000], Q;

class futa {
public:
  static int init() {
    scanf("%d", &N);
    return N;
  }

  static int* momo_gives_you_list_of_futa() {
    for (int i = 0; i < N; ++i) scanf("%d", A + i);
    return A;
  }

  static int momo_tells_you_q() {
    scanf("%d", &Q);
    return Q;
  }

  static pair<int,int> momo_asks() {
    int _i, _j;
    scanf("%d %d", &_i, &_j);
    return make_pair(_i, _j);
  }

  static void you_tell_momo(int d) {
    printf("%d\n", d);
  }
};
