#include <cstdio>
using namespace std;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void quickSort(int* array, int L, int R) {
	int i, j;
	if (L < R) {
		i = L; j = R + 1;
		while (true) {
			while (i < R && array[++i] < array[L]);
			while (j > L && array[--j] > array[L]);
			if (i >= j) break;
			swap(&array[i], &array[j]);
		}
		swap(&array[j], &array[L]);
		quickSort(array, L, j - 1);
		quickSort(array, j + 1, R);
	}
}

int main() {
	int* array;
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		array = new int[n];
		for (int i = 0; i < n; ++i) {
			scanf("%d", &array[i]);
		}
		quickSort(array, 0, n - 1);
		for (int i = 0; i < n; ++i) {
			if (i == n - 1) {
				printf("%d", array[i]);
			} else {
				printf("%d ", array[i]);
			}
		}
		printf("\n");
		delete array; 
	}
	return 0;
}