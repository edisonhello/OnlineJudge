#include <iostream>
using namespace std;

int f(int b, int p, int m) {
	if (p == 0) return 1;
	else if (p == 1) return b;
	else if (p % 2 == 0) {
		int tmp = f(b, p / 2, m);
		return tmp * tmp % m;
	}
	else {
		return f(b, p - 1, m) * b % m;
	}
}

int main() {
	int b, p, m;
	while (cin >> b >> p >> m) {
		b = b % m;
		cout << f(b, p, m) % m << endl;
	}
	return 0;
}