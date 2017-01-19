#include "lib1271.h"
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5;
int ci;
string cur;

struct Command {
  int type, par;
} cmd[maxn];

void Init() {
  cur = "";
  ci = 0;
}

void TypeLetter(char c) {
  cur += c;
  cmd[ci++] = (Command){ 1, c - 'a' };
}

void UndoCommands(int k) {
  for (int i = 0; i < k; ++i) {
    if (cmd[i].type == 1) {
      
    }
  }
}

char GetLetter(int p) {
  return cur[p];
}
