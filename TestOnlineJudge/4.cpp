#include <cstdio>
#include <cmath>

bool mark[10000001];

void erase(int x) {
	int sq = (int)sqrt(x);
	mark[1] = true;
	for (int i = 2; i <= sq; i++) {
		if (!mark[i]) {
			for (int j = i * i; j <= sq; j += i) {
				mark[j] = true;
			}
		}
	}
}

int main() {
	erase(10000001);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		if (mark[x]) printf("no\n");
		else printf("yes\n");
	}
	return 0;
}