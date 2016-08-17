#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int n, v;
  priority_queue<int, vector<int>, less<int> > q;
  cin >> n;
  bool player;
  int reserve[100000];
  for (int i = 0; i < n; ++i) {
    player = false; //false for player who go first, true for the opposite
    cin >> reserve[i];
    // q = priority_queue<int, vector<int>, less<int> >();
    for (int j = 0; j <= i; ++j) {
      q.push(reserve[j]);
    }
    // q.push(v);
    while (true) {
      int cur = q.top();
      q.pop();
      if (cur >= 2) {
        q.push(1);
        q.push(cur - 1);
        player = !player;
      } else {
        break;
      }
    }
    if (player) cout << '1' << endl;
    else cout << '2' << endl;
  }
  return 0;
}
