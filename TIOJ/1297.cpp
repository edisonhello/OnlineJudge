#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double n;
	while (cin >> n) {
		n /= 1.01;
		if (n < 0 || n > 1024) {
			cout << "stupid" << endl;
		} else {
			cout << int(n) + 1 << endl;	
		}
	}
	return 0;
}