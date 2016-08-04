#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
#define MAX 100000

int cnt = 0;
int a[MAX];

void merge(int l, int m, int r) {
	int i = l; int j = m + 1;
	int tmp[MAX];
	int k = 0;
	while (i <= m && j <= r) {
		if (a[i] <= a[j]) {
			tmp[k] = a[i];
			k++; i++;
		} else {
			tmp[k] = a[j];
			k++; j++;
			cnt += (m - l + 1);
		}
	}
	while (i <= m) {
		tmp[k] = a[i];
		k++; i++;
	}
	while (j <= r) {
		tmp[k] = a[j];
		k++; j++;
	}
	for (int idx = l; idx <= r; idx++) {
		a[idx] = tmp[idx - l];
	}
}

void mergeSort(int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		mergeSort(l, m);
		mergeSort(m + 1, r);
		merge(l, m, r);
	}
}

int main() {
	int n;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a[i]);
		}
		cnt = 0;
		mergeSort(0, n - 1);
		cout << cnt << endl;
	}
	return 0;
}
