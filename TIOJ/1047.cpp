#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> postfix, op;
string s, jizz, opp;
char a, b;
int idx;
short prior();
void trans();

int main() {
  while (cin >> s) {
    if (s == "END") break;
    while (postfix.size()) postfix.pop();
    jizz = "";
    trans();
    while (op.size()) op.pop();
    opp = "";
    for (int i = 0; i < jizz.length(); ++i) {
      if (jizz[i] != '+' && jizz[i] != '*' && jizz[i] != '!') opp += jizz[i];
    }
    idx = 0;
    for (int i = 0; i < jizz.length(); ++i) {
      if (jizz[i] == '+') {
        // while (op.size() < 2) op.push(opp[idx++]);
        a = op.top(), op.pop();
        b = op.top(), op.pop();
        if (a == '0' && b == '0') op.push('0');
        else op.push('1');
      } else if (jizz[i] == '*') {
        // while (op.size() < 2) op.push(opp[idx++]);
        a = op.top(), op.pop();
        b = op.top(), op.pop();
        if (a == '1' && b == '1') op.push('1');
        else op.push('0');
      } else if (jizz[i] == '!') {
        // if (!op.size()) op.push(opp[idx++]);
        a = op.top(), op.pop();
        op.push(a == '1' ? '0' : '1');
      } else {
        op.push(opp[idx++]);
      }
    }
    // cout << jizz << endl;
    cout << op.top() << endl;
  }
  return 0;
}

short prior(char c) {
  if (c == '!') return 3;
  if (c == '*') return 2;
  if (c == '+') return 1;
  return 0;
}

void trans() {
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '+' || s[i] == '*' || s[i] == '!') {
      while (postfix.size() && prior(postfix.top()) > prior(s[i])) {
        jizz += postfix.top(), postfix.pop();
      }
      postfix.push(s[i]);
    } else {
      jizz += s[i];
    }
  }
  while (postfix.size()) jizz += postfix.top(), postfix.pop();
}
