#include <iostream>
using namespace std;

void star(int n) {
	int d = n - 2;
	int l = d * 2 + 3;
	while (d >= 0) {
		int o = (l - d * 2 - 3) / 2;
		for (int i = 0; i < o; ++i) {
			cout << ' ';
		}
		cout << '*';
		for (int i = 0; i < d; ++i) {
			cout << ' ';
		}
		cout << '*';
		for (int i = 0; i < d; ++i) {
			cout << ' ';
		}
		cout << '*';
		for (int i = 0; i < o; ++i) {
			cout << ' ';
		}
		cout << endl;
		d--;
	}
	for (int i = 0; i < l; ++i) {
		cout << '*';
	}
	cout << endl;
	d++;
	while (d <= n - 2) {
		int o = (l - d * 2 - 3) / 2;
		for (int i = 0; i < o; ++i) {
			cout << ' ';
		}
		cout << '*';
		for (int i = 0; i < d; ++i) {
			cout << ' ';
		}
		cout << '*';
		for (int i = 0; i < d; ++i) {
			cout << ' ';
		}
		cout << '*';
		for (int i = 0; i < o; ++i) {
			cout << ' ';
		}
		cout << endl;
		d++;
	}
}

int main() {
	int n;
	while (cin >> n) {
		if (n == 0) break;
		star(n);
	}
	return 0;
}