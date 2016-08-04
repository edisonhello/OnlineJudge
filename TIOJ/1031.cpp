#include <iostream>
#include <cstdio>
using namespace std;



/*void init() {
	int k = 1;
	int i = 0;
	while (k < 10000000) {
		two[i] = k;
		k *= 2;
		i++;
	}
}*/

int main() {
	int two[100];
	int k = 1;
	int idx = 0;
	while (k < 10000000) {
		two[idx] = k;
		k *= 2;
		idx++;
	}
	int bean;
	int zero = 0;
	int cnt = 0;
	bool go = true;
	while (go) {
		scanf("%d", &bean);
		if (bean == 0) {
			if (zero == 1) go = false;
			else {printf("%d\n", cnt); cnt = 0; zero = 1;}
		}
		else {
			zero = 0;
			int i = 0;
			while (two[i] <= bean) {
				i++;
			}
			cnt += two[i - 1];
		}
	}
	return 0;
}