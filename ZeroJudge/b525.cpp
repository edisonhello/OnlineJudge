#include <iostream>
#include <vector>
#define MOD 100000007
using namespace std;

struct tb {
	long long int f;
	long long int m;
};

int main() {
	long long int m, f, k;
	while (cin >> m >> f >> k) {
		tb cur;
		cur.m = m;
		cur.f = f;
		cur.m %= MOD;
		cur.f %= MOD;
		tb prev;
		for (long long int i = 1; i <= k; ++i) {
			prev = cur;
			cur.m = prev.f;
			cur.f = prev.f + prev.m;
			cur.m %= MOD;
			cur.f %= MOD;
		}
		cout << (cur.m + cur.f) % MOD << endl;
	}
	return 0;
}