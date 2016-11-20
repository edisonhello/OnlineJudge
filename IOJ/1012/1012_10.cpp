#include <iostream>
using namespace std;

struct Point {
  long long x, y, z;
} p[100005];

unsigned long long dis(const Point& a, const Point& b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
}

int N;
unsigned long long mn;

int main() {
  cin >> N; mn = 18446744073709551615ull;
  for (int i = 0; i < N; ++i) cin >> p[i].x >> p[i].y >> p[i].z;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (dis(p[i], p[j]) < mn) mn = dis(p[i], p[j]);
    }
  }
  cout << mn << endl;
  return 0;
}
