#include <stack>
#include <string>
#include <iostream>
using namespace std;

string s;
int t, cnt;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> s;
    stack<char> ss;
    cnt = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == 'p') ss.push(s[i]);
      else if (s[i] == 'q') {
        if (ss.size()) cnt++, ss.pop();
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
