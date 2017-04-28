#include <bits/stdc++.h>
using namespace std;

void solve(string preOrder, string inOrder);
vector<int> G[20];
string preOrder, inOrder;
void pre(int, int);
void in(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  vector<int> ran;
  for (int i = 0; i < 15; ++i) ran.push_back(i);
  random_shuffle(ran.begin(), ran.end());
  int root = rand() % 15;
  pre(root, -1);
  in(root, -1);
  solve(preOrder, inOrder);
  cout << endl;
  return 0;
}

int index(string s, char c) {
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == c) {
      return i;
    }
  }
  return -1;
}

void solve(string preOrder, string inOrder) {
  if (inOrder.size() > 0) {
    int mid = index(inOrder, preOrder[0]);
    solve(preOrder.substr(1, mid + 1), inOrder.substr(0, mid));
    solve(preOrder.substr(mid + 1, preOrder.size()), inOrder.substr(mid + 1, inOrder.size()));
    cout << inOrder[mid];
  }
}

void pre(int x, int fa) {
  preOrder += (char)(x + 'A');

}
