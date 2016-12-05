#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;

// string s;

int rnk(char c) {
  if (c == '(') return 0;
  if (c == '+' || c == '-') return 1;
  if (c == '*' || c == '/') return 2;
  return 0;
}

stack<char> st;
char c;

int main() {
  while (~scanf("%c", &c)) {
    if (c == ')') {
      while (!st.empty() && st.top() != '(') printf("%c", st.top()), st.pop();
      st.pop();
    }
    else if (c == '(') st.push(c);
    else if (c == '+' || c == '-' || c == '*' || c == '/') {
      while (!st.empty() && rnk(st.top()) > rnk(c)) printf("%c", st.top()), st.pop();
      st.push(c);
    } else if (c != '\n' && c != '\r') {
      printf("%c", c);
    }
  }
  while (!st.empty()) printf("%c", st.top()), st.pop();
  puts("");
  return 0;
}
