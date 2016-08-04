#include <cstdio>
using namespace std;

int main() {
	int x;
	while (scanf("%d", &x) != EOF) {
		int d = 0;
		int k = 1;
		while (k <= x) {
			k *= 10;
			d++;
		}
		if (x == 1) d = 1;
		printf("%d\n", d);
	}
	return 0;
}