#include <bits/stdc++.h>
using namespace std;

int n, x;

int main() {
  cin >> n >> x;
  int m = n % 6;
  int pos = 0;
  if ((n / 6) & 1) {
    for (int i = 2; i <= m + 1; ++i) {
      if (i & 1) {
        if (pos == 0) pos = 1;
        else if (pos == 1) pos = 0;
      } else {
        if (pos == 1) pos = 2;
        else if (pos == 2) pos = 1;
      }
    }
    if (pos == x) return cout << 0 << '\n', 0;
  } else {
    for (int i = 1; i <= m; ++i) {
      if (i & 1) {
        if (pos == 0) pos = 1;
        else if (pos == 1) pos = 0;
      } else {
        if (pos == 1) pos = 2;
        else if (pos == 2) pos = 1;
      }
    }
    if (pos == x) return cout << 0 << '\n', 0;
  }
  pos = 1;
  m = n % 6;
  if ((n / 6) & 1) {
    for (int i = 2; i <= m + 1; ++i) {
      if (i & 1) {
        if (pos == 0) pos = 1;
        else if (pos == 1) pos = 0;
      } else {
        if (pos == 1) pos = 2;
        else if (pos == 2) pos = 1;
      }
    }
    if (pos == x) return cout << 1 << '\n', 0;
  } else {
    for (int i = 1; i <= m; ++i) {
      if (i & 1) {
        if (pos == 0) pos = 1;
        else if (pos == 1) pos = 0;
      } else {
        if (pos == 1) pos = 2;
        else if (pos == 2) pos = 1;
      }
    }
    if (pos == x) return cout << 1 << '\n', 0;
  }
  pos = 2;
  m = n % 6;
  if ((n / 6) & 1) {
    for (int i = 2; i <= m + 1; ++i) {
      if (i & 1) {
        if (pos == 0) pos = 1;
        else if (pos == 1) pos = 0;
      } else {
        if (pos == 1) pos = 2;
        else if (pos == 2) pos = 1;
      }
    }
    if (pos == x) return cout << 2 << '\n', 0;
  } else {
    for (int i = 1; i <= m; ++i) {
      if (i & 1) {
        if (pos == 0) pos = 1;
        else if (pos == 1) pos = 0;
      } else {
        if (pos == 1) pos = 2;
        else if (pos == 2) pos = 1;
      }
    }
    if (pos == x) return cout << 2 << '\n', 0;
  }
  return 0;
}
