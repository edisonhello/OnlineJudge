#include <algorithm>
#include <sstream>
#include <string>
#include <iostream>
#include <utility>
#include <cstdio>
//#include "lib1417.h"
using namespace std;

int T, n, s, t, sm;
long long aaa;
int a[100010];
pair<int, int> p;
string sss, ans;

int main() {
  cin >> T;
  while (T--) {
    cin >> n >> s >> t;
    for (int i = 0; i < n; ++i) cin >> a[i];
    nth_element(a, a + s - 1, a + n);
    nth_element(a + s - 1, a + t, a + n);
    aaa = 0;
    p.first = 0, p.second = 0;
    for (int i = s - 1; i < t; ++i) {
        aaa += a[i];
    }
    cout << aaa << endl;
  }
  return 0;
}
