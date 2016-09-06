#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {
  int t;
  string a, b;
  scanf("%d\n", &t);
  while (t--) {
    getline(cin, a);
    getline(cin, b);
    bool keep = true;
    if (a.length() > b.length()) {
      printf("0\n");
      keep = false;
    } else if (a.length() < b.length() && keep) {
      printf("1\n");
      keep = false;
    }
    for (int i = 0; i < a.length() && keep; ++i) {
      if (a[i] > b[i]) {
        printf("0\n");
        keep = false;
      } else if (b[i] > a[i]) {
        printf("1\n");
        keep = false;
      }
    }
    if (keep) printf("0\n");
  }
  return 0;
}
