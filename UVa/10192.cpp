#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

string s1, s2;
int lcs[101][101];
int c = 0;

int main() {
	while (cin >> s1) {
		if (s1 == "#") break;
		cin >> s2;
		memset(lcs, 0, sizeof(lcs));
		for (int i = 0; i < s1.length(); ++i) {
			for (int j = 0; j < s2.length(); ++j) {
				if (s1[i] == s2[j]) {
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
		printf("Case #%d: you can visit at most %d cities.\n", ++c, lcs[s1.length()][s2.length()]);
	}
	return 0;
}