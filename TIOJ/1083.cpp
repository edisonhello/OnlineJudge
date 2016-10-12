#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, cnt;
vector<string> jizz;
string nw;
char pre;
void build();

int main() {
  build();
  while (cin >> n, n) {
    if (n == 1) printf("%d 0.000000\n", jizz[n - 1].length());
    else printf("%d %.6f\n", jizz[n - 1].length(), (double)jizz[n - 2].length() / (double)jizz[n - 1].length());
  }
  return 0;
}

void build() {
  jizz.push_back("1");
  for (int i = 1; i < 43; ++i) {
    nw = "";
    cnt = 1; pre = jizz[i - 1][0];
    // cout << jizz[i - 1] << endl;
    for (int j = 1; j < jizz[i - 1].length(); ++j) {
      if (jizz[i - 1][j] == pre) cnt++;
      else {
        nw += cnt + '0';
        nw += pre;
        pre = jizz[i - 1][j];
        cnt = 1;
      }
    }
    nw += cnt + '0';
    nw += pre;
    jizz.push_back(nw);
  }
}
