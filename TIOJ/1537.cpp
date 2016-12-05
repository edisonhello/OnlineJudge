#include <iostream>
#include <vector>
using namespace std;

int N, L;
void solve(int, int, vector<int>);

int main() {
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> L;
    cout << "Plank " << i << ":\n";
    solve(0, 1, vector<int>());
  }
}

void solve(int cur, int prv, vector<int> ans) {
  if (cur > L) return;
  if (cur == L) {
    for (int i = 0; i < ans.size(); ++i) {
      cout << ans[i];
      if (i != ans.size() - 1) cout << ", ";
    }
    cout << endl;
    return;
  }
  for (int i = prv; i < L; ++i) {
    ans.push_back(i);
    solve(cur + i, i, ans);
    ans.pop_back();
  }
}
