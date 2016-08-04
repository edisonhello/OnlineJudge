#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int num;
		scanf("%d", &num);
		char k[num];
		int data[26] = {0};
		scanf("%s", &k);
		for (int j = 0; j < num; ++j) {
			data[k[j] - 'a'];
		}
		int max = 0;
		int Imax;
		for (int j = 0; j < 26; ++j) {
			if (data[j] > max) {max = data[j]; Imax = j;}
		}
		printf("%c")
	}
	return 0;
}