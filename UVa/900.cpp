#include <iostream>
#include <algorithm>
using namespace std;

int dp[51];

void init() {
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < 51; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
}

int main() {
	init();
	int n;
	while (cin >> n) {
		if (n == 0) break;
		cout << dp[n] << endl;
	}
	return 0;
}