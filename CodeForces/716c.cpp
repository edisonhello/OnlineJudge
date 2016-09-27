#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;


int main() {
  int n;
  cin >> n;
  ll number = 2;
  for (int level = 1; level <= n; ++level) {
    // ll time = 0;
    ll i = level;
    while (true) {
      if (i * (level + 1) * i * (level + 1) >= number && (i * (level + 1) * i * (level + 1) - number) % level == 0) {
        cout << (i * (level + 1) * i * (level + 1) - number) / level << ",";
        number = i * (level + 1);
        break;
      } else i += level;
    }
  }
  return 0;
}
