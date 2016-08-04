#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

void perm(int, int);

char step[7];
char s[7];

int main() {
	while (scanf("%s", &s) != EOF) {
		sort(s, s + strlen(s));
		perm(0, strlen(s));
		cout << endl;
	}
	return 0;
}

void perm(int cur, int n) {
	if (cur == n) {
		for (int i = 0; i < n; ++i) {
			cout << s[step[i]];
		}
		cout << endl;
	}
	for (int i = 0; i < n; ++i) {
		bool suc = true;
		for (int j = 0; j < cur; ++j) {
			if (step[j] == i) {
				suc = false;
				break;
			}
		}
		if (suc) {
			step[cur] = i;
			perm(cur + 1, n);
		}
	}
}