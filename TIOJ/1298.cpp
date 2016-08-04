#include <iostream>
#include <cstdio>
using namespace std;

double abs(double x) {
	return x > 0 ? x : -x;
}

int main() {
	int n;
	cin >> n;
	double k;
	double w = 0;
	double sum = 0;
	double max = 0;
	double min = 201;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		if (k > 0) w++;
		k = abs(k);
		if (k > max) max = k;
		if (k < min) min = k;
		sum += k;
	}
	if (max > 0) w--;
	if (min > 0) w--;
	sum -= max;
	sum -= min;
	printf("Average time: %.3f sec(s).\n", sum / (n - 2));
	printf("Winning rate: %.3f %%.", w * 100 / (n - 2) );
	return 0;
}