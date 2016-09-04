#include <iostream>
#include <map>
using namespace std;

int f(long long int);

int main() {
  int n;
  // int t[100000];
  int t;
  map<int, long long int> nmap;
  long long int cnt = 0;
  cin >> n;
  long long int zero = 0;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (t == 0) {
      zero++;
      continue;
    }
    if (nmap.find(t) == nmap.end()) {
      nmap[t] = 0;
    }
    nmap[t]++;
  }
  for (map<int, long long int>::iterator it = nmap.begin(); it != nmap.end(); ++it) {
    int num = it->first;
    if (nmap.find(-num) == nmap.end()) {
      continue;
    }
    cnt += it->second * nmap[-num];
  }
  cnt /= 2;
  cnt += f(zero) / 2;
  cout << cnt << endl;
  // int n;
  // cin >> n;
  // cout << f(n) << endl;
  return 0;
}

int f(long long int n) {
  if (n > 1) {
    return f(n - 1) * n;
  } else {
    return 1;
  }
}
