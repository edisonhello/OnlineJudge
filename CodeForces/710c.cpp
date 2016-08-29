#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int odd[2000];
int even[2000];

int square[50][50];
int n;

void print();

int main() {
  cin >> n;
  int oi = 0, ei = 0;
  for (int i = 1; i <= n * n; ++i) {
    if (i % 2 == 0) even[ei++] = i;
    else odd[oi++] = i;
  }
  oi = 0;
  ei = 0;
  memset(square, 0, sizeof(square));
  for (int i = 0; i < n; ++i) {
    square[i][i] = odd[oi++];
  }
  for (int i = n - 1; i >= 0; --i) {
    if (!square[i][n - i - 1]) {
      square[i][n - i - 1] = odd[oi++];
    }
  }
  int edge = n;
  while (n > 1) {
    for (int i = 0; i < edge; i += 2) {
      if (!square[])
    }
  }
  print();
}

void print() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << setw(5) << square[i][j];
    }
    cout << endl;
  }
}
