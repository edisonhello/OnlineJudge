#include <iostream>
#include <string>
using namespace std;

int n;
string s, t;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n >> s;
  t = "";
  int i = 0;
  while (i < s.length()) {
    if (i + 2 < s.length()) {
      if (s.substr(i, 3) == "ogo") {
        int j = i + 2;
        bool jizz = true;
        bool g = false;
        while (j < s.length() && jizz) {
          if (g) jizz = s[j] == 'g';
          else jizz = s[j] == 'o';
          g = !g;
          j++;
        }
        if (s[j - 1] == 'g') j--;
        t += "***";
        i = j - 1;
      } else {
        t += s[i++];
      }
    } else {
      t += s[i];
      i++;
    }
  }
  cout << t << '\n';
  return 0;
}
