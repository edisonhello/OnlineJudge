#include <iostream>
#include <algorithm>
using namespace std;

int dp[101];

void build() {
	dp[1] = 1;
	for (int i = 2; i < 101; ++i) {
		dp[i] = dp[i - 1];
		for (int j = 1; j <= i; ++j) {
			dp[i] += 2 * (i - j) + 1;
		}
	}
}

int main() {
	build();
	int n;
	while (cin >> n) {
		if (n == 0) break;
		cout << dp[n] << endl;
	}
	return 0;
}