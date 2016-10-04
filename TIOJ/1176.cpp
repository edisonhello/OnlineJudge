#include <iostream>
#include <stack>
using namespace std;

stack<int> cw;
int N, c, cnt;
int cow[1000010];

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> cow[i];
  }
  for (int i = 0; i < N; ++i) {
    cnt = i == N - 1 ? 0 : 1;
    while (cw.size()) cw.pop();
    cw.push(cow[i]);
    for (int j = i + 1; j < N; ++j) {
      if (cow[j] <= cw.top()) cnt++;
      while (cw.size() && cow[j] > cw.top()) cw.pop();
      cw.push(cow[j]);
    }
    cout << cnt << endl;
  }
  return 0;
}
//
// void print() {
//   for ()
// }
