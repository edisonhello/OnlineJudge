#include <iostream>
using namespace std;

int main() {
	long long int n, sm, x, mx;
	while (cin >> n && n != 0) {
		sm = 0;
		mx = 0;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			sm += x;
			if (x > mx) mx = x;
		}
		cout << sm + mx + 1 << endl;
	}
}
