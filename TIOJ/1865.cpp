#include "lib1865.h"

int n;
int main() {
  n = GetN();
  for (int i = 1; i < n; ++i) {
    for (int j = n - 1 - i; j < n - 1; ++j) {
      Magic_Operate(j);
    }
  }
  End();
}
