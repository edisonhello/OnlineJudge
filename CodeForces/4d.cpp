#include <iostream>
#include <algorithm>
using namespace std;

struct Env {
  int w;
  int h;
  bool operator<(const Env& e) const {
    if (e.w < w && e.h < h) return true;
    if (e.w < w) return true;
    if (e.h < h) return true;
    else return false;
  }
  friend ostream& operator<<(ostream& out, const Env& e) {
    out << e.w << ' ' << e.h << '\n';
    return out;
  }
};

bool cmp(Env e1, Env e2) {
  return !(e1 < e2);
}

int main() {
  int n, w, h;
  cin >> n >> w >> h;
  Env env[5000];
  for (int i = 0; i < n; ++i) {
    cin >> env[i].w >> env[i].h;
  }
  sort(env, env + n, cmp);
  int dp[5000];
  if (w >= env[0].w || h >= env[0].h) {
    cout << 0 << endl;
    return 0;
  }
  dp[0] = 1;
  for (int i = 1; i < n; ++i) {
    
  }
  return 0;
}
