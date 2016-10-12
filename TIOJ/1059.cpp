#include <iostream>
#include <cmath>
using namespace std;

double s, t, n, jizz, cur;

int main() {
  cin >> s >> t >> n;
  cur = 0;
  double target = s * t * 0.3;
  double money = 0;
  for (int i = 0; i < n; ++i) {
    cin >> jizz;
    cur += jizz;
  }
  if (cur > t * 0.2) {
    money += t * 0.2 * s * 0.7;
    cur -= t * 0.2;
  } else {
    money += cur * s * 0.7;
    cur = 0;
  }
  if (cur > t * 0.2) {
    money += t * 0.2 * s * 0.8;
    cur -= t * 0.2;
  } else {
    money += cur * s * 0.8;
    cur = 0;
  }
  if (cur > t * 0.2) {
    money += t * 0.2 * s * 0.9;
    cur -= t * 0.2;
  } else {
    money += cur * s * 0.9;
    cur = 0;
  }
  money += cur * s;
  cout << round(money - target) << endl;
  return 0;
}
