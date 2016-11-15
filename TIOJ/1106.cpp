#include <iostream>
#include <stack>
#include <string>
using namespace std;

string s;
stack<char> st;
int leaf, depth, degree, cnt;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> s) {
    leaf = depth = degree = 0;
    while (st.size()) st.pop();
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '(') st.push(s[i]);
      if (s[i] == ')') {
        cnt = 0;
        while (st.size() && st.top() != ')') st.pop(), cnt++;
        degree = max(degree, cnt); leaf += cnt;
        st.pop(); depth++;
      } else st.push(s[i]);
    }
    cnt = 0;
    while (st.size()) st.pop(), cnt++;
    degree = max(degree, cnt); leaf += cnt;
    // if (!)
    cout << leaf << ' ' << depth + 1 << ' ' << degree << endl;
  }
  return 0;
}
