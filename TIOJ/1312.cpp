#include <iostream>
using namespace std;

int djs[10000];

int F(int a){
  if (djs[a] == a)return a;
  else return djs[a] = F(djs[a]);
}

void U(int a, int b){
  a = F(a);
  b = F(b);
  if (b > a) swap(a, b);
  djs[a] = b;
}

int n, m, a, b, k;

int main() {
  while (cin >> n >> m) {
    for (int i = 0; i <= n; ++i) djs[i] = i;
    while (m--) {
      cin >> a >> b;
      U(a, b);
    }
    cin >> k;
    cout << F(k) << endl;
  }
  return 0;
}
