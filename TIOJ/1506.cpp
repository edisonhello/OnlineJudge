#include <iostream>
#include <cstdio>
using namespace std;

float a1, a2, b1, b2;

int main() {
	cin >> a1 >> a2 >> b1 >> b2;
	float x = (b2 - b1) / (a1 - a2);
	float y = a1 * x + b1;
	printf("%.2f\n%.2f\n", x, y);
	return 0;
}