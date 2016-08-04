#include <iostream>
using namespace std;

int num[100];
int n;

int find(int x) {
	for (int i = 0; i < n; ++i) {
		if (num[i] == x) return i;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	int min = find(1);
	// cout << "Min: " << min << endl;
	int max = find(n);
	// cout << "Max: " << max << endl;
	int dis;
	if (max > min) {
		dis = max - min;
		if (max < n - 1) dis++;
		if (min > 0) dis++;
	} else {
		dis = min - max;
		if (max > 0) dis++;
		if (min < n - 1) dis++;
	}
	cout << dis << endl;
	return 0;
}