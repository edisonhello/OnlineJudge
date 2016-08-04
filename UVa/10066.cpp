#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int lcs[101][101];
int n1, n2;
int t1[101], t2[101];
int c = 0;

int main() {
	while (cin >> n1 >> n2) {
		if (n1 == 0 && n2 == 0) break;
		memset(lcs, 0, sizeof(lcs));
		for (int i = 0; i < n1; ++i) {
			cin >> t1[i];
		}
		for (int i = 0; i < n2; ++i) {
			cin >> t2[i];
		}
		for (int i = 0; i < n1; ++i) {
			for (int j = 0; j < n2; ++j) {
				if (t1[i] == t2[j]) {
					lcs[i + 1][j + 1] = lcs[i][j] + 1;
				} else {
					if (lcs[i + 1][j] > lcs[i][j + 1]) {
						lcs[i + 1][j + 1] = lcs[i + 1][j];
					} else {
						lcs[i + 1][j + 1] = lcs[i][j + 1];
					}
				}
			}
		}
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", ++c, lcs[n1][n2]);
	}
	return 0;
}