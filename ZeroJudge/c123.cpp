#include <iostream>
#include <stack>
using namespace std;

int n, a[1005], b[1005], ai, bi;
bool p;

int main() {
  while (cin >> n, n) {
    while (cin >> b[0], b[0]) {
      a[0] = 1;
      for (int i = 1; i < n; ++i) {cin >> b[i]; a[i] = i + 1;}
      stack<int> s;
      ai = 0, bi = 0; p = true;
      while (bi < n) {
        if (s.empty()) s.push(a[ai++]);
        else if (s.top() < b[bi]) s.push(a[ai++]);
        else if (s.top() == b[bi]) s.pop(), bi++;
        else {p = false; break;}
      }
      if (p) cout << "Yes\n";
      else cout << "No\n";
    }
    cout << endl;
  }
  return 0;
}
