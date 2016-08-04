#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	int dis[50];
	while (cin >> n) {
		if (n == 0) break;
		queue<int> q;
		int idx = 0;
		for (int i = 1; i <= n; ++i) {
			q.push(i);
		}
		while (q.size() > 1) {
			dis[idx++] = q.front();
			q.pop();
			int x = q.front();
			q.pop();
			q.push(x);
		}
		cout << "Discarded cards: " << dis[0];
		for (int i = 1; i < idx; ++i) {
			cout << ", " << dis[i];
		}
		cout << endl;
		cout << "Remaining card: " << q.front() << endl;
	}
	return 0;
}