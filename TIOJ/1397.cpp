#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct S {
  char c;
  int pos;
  bool operator<(const S& s) const {
    return c > s.c;
  }
} s[100005];

int n, k, front;
string str;
bool v[100005];

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> n >> k) {
    memset(v, false, sizeof(v));
    cin >> str;
    for (int i = 0; i < n; ++i) s[i].c = str[i], s[i].pos = i;
    sort(s, s + n);
    front = 0;
    for (int i = 0; i < k; ++i) {
      if (str[front] == '0') v[front] = true, front++;
      else if (s[i].pos == front) front++;
      else if (!v[s[i].pos]) v[s[i].pos] = true;
    }
    for (int i = front; i < n; ++i) if (!v[i]) cout << str[i];
    cout << endl;
  }
  return 0;
}
