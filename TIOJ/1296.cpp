#include <iostream>
using namespace std;

long long int dp[20];

void build() {
	dp[1] = 1;
	for (int i = 2; i < 20; ++i) {
		dp[i] = dp[i - 1] * (4 * i - 2) / (i + 1);
	}
}

int main() {
	build();
	int n;
	while (cin >> n) {
		cout << dp[n] << endl;
	}
	return 0;
}