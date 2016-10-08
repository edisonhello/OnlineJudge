#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int n, cnt;
void DFS(int);
list<int> li, ans;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;
  li.push_back(0); li.push_back(1);
  cnt = 0;
  DFS(2);
  cout << cnt << endl;
  if (cnt) {
    for (list<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
      cout << *it << ' ';
    }
    cout << endl;
  }
  return 0;
}

void DFS(int number) {
  if (number > n) {
    if (li > ans) ans = li;
    cnt++;
    return;
  }
  for (list<int>::iterator it = li.begin(); it != li.end(); ++it) {
    list<int>::iterator itt = it; itt++;
    if (itt == li.end()) return;
    if (number % (*it + *itt) == 0) {
      itt = li.insert(itt, number);
      DFS(number + 1);
      itt = li.erase(itt);
    }
  }
}
