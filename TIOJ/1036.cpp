#include <iostream>
#include <cstring>
#include <string>
#define MAX 10000001
using namespace std;

bool prime[MAX];

void build() {
	memset(prime, true, MAX);
	prime[1] = false;
	for (int i = 2; i < MAX; ++i) {
		if (prime[i]) {
			for (int j = i * i; j < MAX; j += i) {
				prime[j] = false;
			}
		}
	} 
}

int main() {
	build();
	int m, n, cnt;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> n;
		cnt = 0;
		for (int j = 2; j < n; ++j) {
			if (prime[j]) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}