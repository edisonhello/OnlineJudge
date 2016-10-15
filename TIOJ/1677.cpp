#include <iostream>
#include <list>
using namespace std;

int m, n, k;

int main() {
  cin >> m;
  while (m--) {
    list<int> l;
    cin >> n >> k;
    l.push_back(0);
    for (int i = 0; i < n - 1; ++i) {
      for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        if (*it == 1) l.insert(it, 0);
        else *it = 1;
      }
    }
    if (k >= l.size()) cout << -1 << endl;
    else {
      list<int>::iterator it = l.begin();
      for (int i = 0; i < k - 1; ++i) it++;
      cout << *it << endl;
    }
  }
  return 0;
}
