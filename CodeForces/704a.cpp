#include <iostream>
#include <vector>
using namespace std;

struct notf {
  int number;
  bool read;
};

vector<notf> arc[300000];

int main() {
  int n, q;
  cin >> n >> q;
  int type, arg;
  int max = 0;
  for (int i = 0; i < q; ++i) {
    cin >> type >> arg;
    if (type == 1) {
      notf n1;
      n1.number = i + 1;
      n1.read = false;
      arc[arg - 1].push_back(n1);
    } else if (type == 2) {
      for (int j = 0; j < arc[arg - 1].size(); ++j) {
        arc[arg - 1][j].read = true;
      }
    } else {
      if (arg > max) {
        max = arg;
      }
    }
    int ans = 0;
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < arc[j].size(); ++k) {
        if (arc[j][k].number > max && !arc[j][k].read) {
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
