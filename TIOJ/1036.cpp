#include <iostream>
#include <cstring>
#include <string>
#include <bitset>
using namespace std;

bitset<10000010> prime;
int cnt[10000010];
int m, n;

int main() {
	cin >> m;
	prime.set();
	prime[1] = false;
	for (int j = 2; j < 10000010; ++j) {
		cnt[j] = cnt[j - 1] + prime[j];
		if (prime[j]) {
			for (int i = j; i < 10000010; i += j) prime[i] = false;
		}
	}
	for (int i = 0; i < m; ++i) {
		cin >> n;
		cout << cnt[n] << endl;
	}
	return 0;
}
