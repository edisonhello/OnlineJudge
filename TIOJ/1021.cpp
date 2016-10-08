#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int cnt[10];
int n, k, cur;

int solve(int n) {
	if (cur == 0) {
		for (int i = 1; i < n; ++i) cnt[i]++;
		return n;
	}
	else {
		while (pow(10, cur) <= n) {
			for (int i = 0; i < 10; ++i) cnt[i] += ceil(pow(10, cur - 1));
			cur++;
		}
	}
	return pow(10, cur - 1) - 1;
}

int main() {
	while (scanf("%d %d", &n, &k) != EOF) {
		memset(cnt, 0, sizeof(cnt));
		cur = 1;
		while (n > 0) {
			n -= solve(n);
			cur--;
		}
		cout << cnt[k] << endl;
	}
	return 0;
}
