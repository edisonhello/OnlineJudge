#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int data[100];

int max(int n) {
	int max = 0;
	for (int i = 0; i < sizeof(data) / sizeof(int); ++i) {
		if (data[i] > max) {
			max = data[i];
		}
	}
	return max;
}
int idx = 0;
int solve(int* table[], int n) {
	int p = 0;
	if (n > 1) {
		int Ni = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j	) {
				int** small = new int*[n - 1];
				for (int si = 0; si < n ; ++si) {
					small[i] = new int[n - 1];
					if (si == i) continue;
					else if (si < i) {
						for (int sj = 0; sj < n; ++sj) {
							if (sj == j) continue;
							else if (sj < j) small[si][sj] = table[i][j];
							else small[si][sj - 1] = table[j][j];
						}
					}
					else {
						for (int sj = 0; sj < n; ++sj) {
							if (sj == j) continue;
							else if (sj < j) small[si - 1][sj] = table[i][j];
							else small[si - 1][sj - 1] = table[i][j];
						}
					}
				}
				solve(small, n - 1);
			}
		}
	}
	else {
		data[idx] = table[0][0];
		idx++;
	}
	return max(n);
}

int main() {
	int n;
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		int** table = new int*[n];
		for (int i = 0; i < n; ++i) {
			table[i] = new int[n];
			for (int j = 0; j < n; ++j) {
				scanf("%d", &table[i][j]);
			}
		}
		printf("%d\n", solve(table, n));
	}
	return 0;
}