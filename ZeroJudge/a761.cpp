#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

struct Memory {
  bool mapped;
  int region;
};

Memory m[2147483647];

void init() {
  for (int i = 0; i < 2147483647; ++i) {
    m[i].mapped = false;
  }
}

int main() {
  int n;
  cin >> n;
  string cmd;
  int a, b, region, c, d;
  init();
  for (int i = 0; i < n; ++i) {
    cin >> cmd;
    if (cmd == "map") {
      cin >> region >> a >> b;
      bool success = true;
      int prev;
      for (int i = a; i <= b) {
        if (m[i].mapped) {
          success = false;
          for (int j = i; i >= a; i--) {
            m[j].mapped = false;
          }
          break;
        } else {
          m[i].mapped = true;
          m[i].region = region;
        }
      }
      if (success) printf("region %d created\n", region);
      else printf()
    } else if (cmd == "load") {
      cin >> c;
    } else {
      cin >> d;
    }
  }
}
