#include <iostream>
using namespace std;

int main() {
	int n, sm, x;
	while (cin >> n && n != 0) {
		sm = 0;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			sm += x - 1;
		}
		cout << (sm + 1)* 2 << endl;
	}
}
