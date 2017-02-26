#include <bits/stdc++.h>
using namespace std;

long long n, l, r, len, ll, rr, cur;
int cnt;
void dq1(long long);
void dq2(long long);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> l >> r;
  long long nn = n;
  len = 1;
  while (nn > 1) {
    nn /= 2;
    len *= 2;
  }
  len = len * 2 - 1;
  cout << "len: " << len << '\n';
  if (r <= len / 2 + 1) {
    dq1(n);
    cout << cnt << '\n';
    return 0;
  }
  ll = l;
  rr = len - r + 1;
  dq2(n);
  cout << cnt << '\n';
  return 0;
}

void dq1(long long n) {
  if (n <= 1) {
    ++cur;
    if (cur >= l && cur <= r) if (n) ++cnt;
    return;
  }
  dq1(n / 2);
  ++cur;
  if (cur >= l && cur <= r) if (n % 2) ++cnt;
  return;
}

void dq2(long long n) {
  if (n <= 1) {
    ++cur;
    if (cur >= ll) if (n) ++cnt;
    if (cur >= rr) if (n) ++cnt;
    return;
  }
  dq2(n / 2);
  ++cur;
  if (cur >= ll) if (n % 2) ++cnt;
  if (cur >= rr) if (n % 2) ++cnt;
  return;
}
