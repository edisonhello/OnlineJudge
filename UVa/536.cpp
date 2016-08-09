#include <iostream>
#include <string>
using namespace std;

void solve(string, string);

int main() {
	string preOrder, inOrder;
  while (cin >> preOrder >> inOrder) {
    solve(preOrder, inOrder);
    cout << endl;
  }
	return 0;
}

int index(string s, int x) {
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == x) return i;
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
