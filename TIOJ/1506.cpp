#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
using namespace std;

int a1, a2, b1, b2;

int main() {
	cin >> a1 >> a2 >> b1 >> b2;
	double x = (double)(b1 - b2) / (double)(a2 - a1);
	// cout << fixed << setprecision(2) << x << endl;
	// cout << fixed << setprecision(2) << a1 * x + b1 << endl;
	printf("%.2lf\n%.2lf\n", (double)x, (double)(x * a1 + b1));
}
