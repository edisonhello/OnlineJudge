#include <iostream>
#include <vector>
using namespace std;

int n, p, q;
vector<int> ans;
void dfs(int, int);

int main() {
  cin >> n;
  while (n--) {
    ans.clear();
    cin >> p >> q;
    cout << p << "/" << q << " = ";
    dfs(p, q);
    cout << endl;
  }
  return 0;
}

void dfs(int p, int q) {
  if (p % q == 0) {cout << p / q; return;}
  cout << p / q;
  if (q % (p % q) == 0) {cout << "+1/" << q / (p % q); return;}
  cout << "+1/{";
  dfs(q, p % q);
  cout << "}";
}
