#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int n, f, r;
double cake[10000];
const double pi = 3.1416;

bool bs(double x) {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt += (int)cake[i] / x;
	}
	return cnt >= f;
}

double L, R, M;

int main() {
	cout.precision(6);
	int num;
	cin >> num;
	for (int i = 0; i < num; ++i) {
		cin >> n;
		double mx = 0;
		for (int j = 0; j < n; ++j) {
			cin >> r;
			cake[j] = r * r * pi * 1;
			mx = max(mx, cake[j]);
		}
		cin >> f;
		L = 0;
		R = mx;
		while (L <= R) {
			M = (L + R) / 2;
			if (bs(M)) L = M;
			else R = M - 1;
			if (L == (L + R) / 2) break;
		}
		cout << R << endl;
	}
	return 0;
}