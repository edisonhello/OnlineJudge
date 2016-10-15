#include <iostream>
#include <set>
#include <map>
using namespace std;

void DFS(int[9][9]);
bool check(int[9][9]);
bool full(int[9][9]);
void output(int[9][9]);

int main() {
  int mp[9][9];
  for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) cin >> mp[i][j];
  DFS(mp);
  return 0;
}

void DFS(int jizz[9][9]) {
  if (!check(jizz)) return;
  if (full(jizz)) {output(jizz); return;}
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (jizz[i][j] == 0) {
        for (int k = 1; k <= 9; ++k) {
          if (k != jizz[i][j] ) {
            jizz[i][j] = k;
            DFS(jizz);
            jizz[i][j] = 0;
          }
        }
      }
    }
  }
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
  for (int i = 0; i < 9; i += 3) {
    for (int j = 0; j < 3; j += 3) {
      set<int> ss;
      for (int k = i; k < i + 3; ++k) {
        for (int kk = j; kk < j + 3; ++kk) {
          if (ss.find(jizz[k][kk]) == ss.end()) ss.insert(jizz[k][kk]);
          else if (jizz[k][kk] != 0) return false;
        }
      }
    }
  }
  return true;
}

bool full(int jizz[9][9]) {
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (jizz[i][j] == 0) return false;
    }
  }
  return true;
}

void output(int jizz[9][9]) {
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      cout << jizz[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}
