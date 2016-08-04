#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int prob(int n) {
	int len = 0;
	while (n != 1) {
		if (n % 2 == 0) {
			n /= 2;
			len++;
		}
		else {
			n = n * 3 + 1;
			len++;
		}
	}
	return len + 1;
}

int main() {
	int x, y;
	while (scanf("%d %d", &x, &y)) {
		int max = 0;
		for (int i = x; i <= y; ++i) {
			if (max < prob(i)) max = prob(i);
		}
		printf("%d %d %d\n", x, y, max);
	}
	return 0;
}