#include <iostream>
#include <algorithm>
using namespace std;

int merge(int*, int, int, int);
void mergeSort(int*, int, int);

int total = 0;

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	mergeSort(a, 0, n - 1);
	cout << total << endl;
}

int merge(int* a, int l, int m, int h) {
	int i = l, j = m + 1;
	int sum = 0;
	int tmp[h - l];
	int idx = 0;
	while (i <= m && j <= h) {
		if (a[i] < a[j]) {
			tmp[idx++] = a[i++];
		} else {
			sum += a[j] + a[i];
			tmp[idx++] = a[j++];
		}
	}
	while (i <= m) {
		tmp[idx++] = a[i++];
	}
	while (j <= h) {
		sum += a[j] + a[i];
		tmp[idx++] = a[j++];
	}
	for (int i = 0; i <= idx; ++i) {
		a[l + i] = tmp[i];
	}
	return sum;
}

void mergeSort(int* a, int l, int h) {
	if (h > l) {
		int m = (l + h) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, h);
		total += merge(a, l, m, h)`;
	}
}