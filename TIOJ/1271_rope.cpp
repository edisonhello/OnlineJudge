#include "lib1271.h"
#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

const int maxn =  1000000 + 5;
rope<char> *ver[maxn];
int vnow;

void Init() {
  // for (int i = 0; i < maxn; ++i) if (ver[i]) delete ver[i];
  ver[0] = new rope<char>();
  vnow = 0;
}

void TypeLetter(char c) {
  ++vnow;
  ver[vnow] = new rope<char>(*ver[vnow - 1]);
  ver[vnow]->push_back(c);
}

char GetLetter(int p) {
  return (*ver[vnow])[p];
}

void UndoCommands(int k) {
  ++vnow;
  ver[vnow] = new rope<char>(*ver[vnow - k - 1]);
}
