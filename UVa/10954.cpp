#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int n, x, cost;

	while (cin >> n) {
		if (n == 0) break;
		priority_queue<int, vector<int>, greater<int> > q;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			q.push(x);
		}
		cost = 0;
		while (q.size() > 1) {
			int a = q.top();
			q.pop();
			int b = q.top();
			q.pop();
			cost += a + b;
			q.push(a + b);
		}
		cout << cost << endl;
	}
	return 0;
}