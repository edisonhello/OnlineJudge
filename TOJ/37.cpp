#include <string>
#include <sstream>
#include <iostream>
using namespace std;

string s;
stringstream ss;
int ans, x;

int main() {
  while (getline(cin, s)) {
    ss.clear(); ans = 0; ss << s;
    while (ss >> x) ans++;
    cout << ans << endl;
  }
  return 0;
}
