#include <iostream>
using namespace std;

int n, c;

void hanoi(int n, int start, int tmp, int end) {
  if (n > 0) {
    hanoi(n - 1, start, tmp, end);
    printf("#%d : move the dish from #%d to #%d\n", ++c, start, tmp);
    hanoi(n - 1, end, tmp, start);
    printf("#%d : move the dish from #%d to #%d\n", ++c, tmp, end);
    hanoi(n - 1, start, tmp, end);
  }
}

int main() {
  cin >> n;
  hanoi(n, 1, 2, 3);
  return 0;
}
