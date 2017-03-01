#include <bits/stdc++.h>
using namespace std;

const int maxn = 1299710;
int n;
vector<int> prime;

void sieve();

int main() {
	sieve();
	while (cin >> n, n) {
		int a = *lower_bound(prime.begin(), prime.end(), n);
		auto b = lower_bound(prime.begin(), prime.end(), n);
		if (*b > n) --b;
		cout << a - *b << '\n';
	}
	return 0;
}

void sieve() {
	bool v[maxn];
	memset(v, false, sizeof(v));
	for (int i = 2; i < maxn; ++i) {
		if (!v[i]) prime.push_back(i);
		for (int j = 0; i * prime[j] < maxn; ++j) {
			v[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
