#include <iostream>
using namespace std;

int main() {
	long long int p[100000];
	long long int n, k, h;
	cin >> n >> h >> k;
	long long int cnt = 0;
	for (long long int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	long long int idx = 0;
	long long int cur = 0;
	while (idx < n) {
		while (cur + p[idx] <= h) {
			cur += p[idx];
			idx++;
		}
		if (cur < k) cur = k;
		cur -= k;
		cnt++;
	}
	while (cur > 0) {
		if (cur < k) cur = k;
		cur -= k;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}
