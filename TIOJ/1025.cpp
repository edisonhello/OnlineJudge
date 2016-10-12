#include <iostream>
#include <set>
#include <map>
using namespace std;

void DFS(int[9][9]);
bool check(int[9][9]);
bool full(int[9][9]);

int main() {
  int mp[9][9];
  for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) cin >> mp[i][j];
  DFS(mp);
  return 0;
}

void DFS(int jizz[9][9]) {
  if (!check(jizz)) return;
}

bool check(int jizz[9][9]) {
  for (int i = 0; i < 9; ++i) {
    set<int> ss;
    for (int j = 0; j < 9; ++j) {
      if (ss.find(jizz[i][j]) == ss.end()) ss.insert(jizz[i][j]);
      else if (jizz[i][j] != 0) return false;
    }
  }
  for (int i = 0; i < 9; ++i) {
    set<int> ss;
    for (int j = 0; j < 9; ++j) {
      if (ss.find(jizz[j][i]) == ss.end()) ss.insert(jizz[j][i]);
      else if (jizz[j][i] != 0) return false;
    }
  }
  for (int i)
}

bool full(int jizz[9][9]) {
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (jizz[i][j] == 0) return false;
    }
  }
  return true;
}
