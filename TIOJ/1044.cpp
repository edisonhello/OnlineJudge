#include "lib1044.h"
int main() {
	long long int n, l, r;
	int g;
	l = 0;
	r = 1000000000;
	long long int m = (l + r) / 2;
	Initialize();
	while (l != r - 1) {
		g = Guess(m);
		if (g == 0) {
			l = m;
		} else {
			r = m;
		}
		m = (l + r) / 2;
	}
	Report(r);
	return 0;
}