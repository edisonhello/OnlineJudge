#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double n, m;
	while (cin >> n) {
		m = n - (int)n / 100;
		if (n < 0 || n > 1034 || m < 0 || m > 1024) {
			cout << "stupid" << endl;
		} else if (n == 0) {
			cout << "0" << endl;
		} else {

		}
	}
	return 0;
}
