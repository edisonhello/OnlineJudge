#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		int* sound = new int[n];
		for (int i = 0; i < n; ++i) scanf("%d", &sound[i]);
		sort(sound, sound + n);
		int floor = 0;
		floor += sound[n - 1] * 2;
		for (int i = 0; i < n - 1; ++i) {
			floor += sound[i];
		}
		floor++;
		printf("%d\n", floor);
	}
	return 0;
}