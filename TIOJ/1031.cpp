#include <iostream>
#include <cmath>
#define MAX 10000000
using namespace std;

int bs(int n) {
	int r = 30;
	int l = 0;
	int m = (l + r) / 2;
	while (l < r) {
		if (pow(2, m) > n) r = m - 1;
		else if (pow(2, m) < n) l = m + 1;
		else return m;
		m = (l + r) / 2;
	}
	return r;
}

int s(int n) {
	for (int i = 0; i <= 30; ++i) {
		if (pow(2, i) <= n && pow(2, i + 1) > n) return i;
	}
}

int n, a;
long long int cnt;

int main() {
	while (cin >> a) {
		if (a == 0) break;
		cnt = pow(2, s(a));
		while (cin >> a) {
			if (a == 0) {cout << cnt << endl; break;}
			cnt += pow(2, s(a));
		}
	}
	return 0;
}
