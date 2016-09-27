#include <iostream>
#include <cmath>
using namespace std;

int main() {
	unsigned double n, m;
	while (cin >> n) {
		m = n / 1.01;
		if (m < 0 || m > 1024) {
			cout << "stupid" << endl;
		} else {
			if (floor(m) * 1.01 >= n) cout << floor(m) << endl;
			else cout << ceil(m) << endl;
		}
	}
	return 0;
}
