#include <iostream>
#include <string>
using namespace std;

string s;
int cnt;

int main() {
  while (cin >> s, (s != "0")) {
    cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (i < n - 1) {
        if (s[i] <= '2' && s[i + 1] <= '6') cnt++;
      }
    }

  }
}
