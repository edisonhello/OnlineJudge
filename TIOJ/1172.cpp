#include "lib1172.cpp"
#include <algorithm>
using namespace std;

void query(int n, int d[], int l, int ans[]) {
  vector<int> hand;
  for (int i = 0; i < n; ++i) {
    hand[i] = i;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (!comp(i, j)) swap(hand[i], hand[j]);
    }
  }
  for (int i = 0; i < l; ++i) {
    nth_element(hand.begin(), hand.begin() + d[i], hand.end());
    
  }
}
