#include <iostream>
#include <algorithm>
using namespace std;

int p(char c) {
  if (c == 'S') return 3;
  if (c == 'H') return 2;
  if (c == 'D') return 1;
  if (c == 'C') return 0;
}

struct Card {
  int n;
  char c;
  bool operator < (const Card& c1) const {
    return n == c1.n ? p(c) < p(c1.c) : n < c1.n;
  }
};

Card card[52];
int n, m;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> card[i].c >> card[i].n;
  cin >> m;
  sort(card, card + n);
  cout << card[n - m].c << ' ' << card[n - m].n << endl;
  return 0;
}
