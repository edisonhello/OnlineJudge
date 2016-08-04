#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> dp;

int f(int n) {
	dp.resize(n + 1);
	dp[0] = 0;
	int max = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i / 2] + i - 2 * (i / 2);
		if (dp[i] > max) max = dp[i];
	}
	return max;
} 

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", f(n));
	return 0;
}