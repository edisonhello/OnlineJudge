#include <string>
#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int tot, o, x, draw;
string mp[3];
string s;
char c;
set<string> st;
void solve(string);
bool win(string, char);
bool full(string);
// string jizz(string[]);

int main() {
  cin >> s;
  tot = 0, o = 0, x = 0, draw = 0;
  solve(s);
  printf("%d %d %d %d\n", tot, o, x, draw);
  return 0;
}

bool win(string mp, char c) {
  for (int i = 0; i < 3; ++i) {
    if (mp[i * 3] == c && mp[i * 3 + 1] == c && mp[i * 3 + 2] == c) return true;
    if (mp[0 * 3 + i] == c && mp[1 * 3 + i] == c && mp[2 * 3 + i] == c) return true;
  }
  if (mp[0] == c && mp[4] == c && mp[8] == c) return true;
  if (mp[2] == c && mp[4] == c && mp[6] == c) return true;
  return false;
}

bool full(string mp) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (mp[i * 3 + j] == '-') return false;
    }
  }
  return true;
}

void solve(string mpp) {
  int O = 0; int X = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (mpp[i * 3 + j] == 'O') O++;
      if (mpp[i * 3 + j] == 'X') X++;
    }
  }
  if (win(mpp, 'O')) {
    if (st.find(mpp) == st.end()) {
      st.insert(mpp);
      o++, tot++;
    }
    return;
  }
  else if (win(mpp, 'X')) {
    if (st.find(mpp) == st.end()) {
      st.insert(mpp);
      x++, tot++;
    }
    return;
  }
  else if (full(mpp)) {
    if (st.find(mpp) == st.end()) {
      st.insert(mpp);
      draw++, tot++;
    }
    return;
  }
  else {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (mpp[i * 3 + j] == '-') {
          if (O > X) {
            mpp[i * 3 + j] = 'X';
            solve(mpp);
            mpp[i * 3 + j] = '-';
          } else if (O == X) {
            mpp[i * 3 + j] = 'O';
            solve(mpp);
            mpp[i * 3 + j] = '-';
          }
        }
      }
    }
  }
}
