#include <iostream>
#include <string>
using namespace std;

string mp[3];
int O, X;

bool win(char c);

int main() {
  for (int i = 0; i < 3; ++i) cin >> mp[i];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (mp[i][j] == 'O') O++;
      else if (mp[i][j] == 'X') X++;
      else if (mp[i][j] != '.') {cout << "IMPOSSIBLE" << endl; return 0;}
    }
  }
  if (abs(O - X) > 1) {cout << "IMPOSSIBLE" << endl; return 0;}
  if (O > X) {
    if (win('X')) cout << "IMPOSSIBLE" << endl;
    else cout << "POSSIBLE" << endl;
  } else {
    if (win('O')) cout << "IMPOSSIBLE" << endl;
    else cout << "POSSIBLE" << endl;
  }
  return 0;
}

bool win(char c) {
  for (int i = 0; i < 3; ++i) {
    if (mp[i][0] == c && mp[i][1] == c && mp[i][2] == c) return true;
    if (mp[0][i] == c && mp[1][i] == c && mp[2][i] == c) return true;
  }
  if (mp[0][0] == c && mp[1][1] == c && mp[2][2] == c) return true;
  if (mp[0][2] == c && mp[1][1] == c && mp[2][0] == c) return true;
  return false;
}
