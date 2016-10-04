#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

string str;
map<char, int> mp;
long long int cnt, d;
int n;
bool odd, p;

long long int f(int num) {
  if (num == 1 || num == 0) return 1;
  return num * f(num - 1);
}

int main() {
  int n;
  scanf("%d\n", &n);
  while (n--) {
    cin >> str;
    mp.clear();
    cnt = 0;
    for (int i = 0; i < str.length(); ++i) {
      if (mp.find(str[i]) == mp.end()) mp[str[i]] = 0;
      mp[str[i]]++;
    }
    odd = false;
    p = true;
    d = 1;
    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
      if (it->second % 2 == 1) {
        if (odd) {cout << 0 << endl; p = false; break;}
        else {
          cnt += (it->second / 2);
          d *= f(it->second / 2);
          odd = true;
        }
      } else {
        d *= f(it->second / 2);
        cnt += (it->second / 2);
      }
    }
    if (p) printf("%lld\n", f(cnt) / d);
  }
  return 0;
}
