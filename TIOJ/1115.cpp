#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double x, y, r, theta, a1, jizz;
const double pi = acos(-1);

int main() {
	while (cin >> x >> y >> r) {
		if (y <= -r) { cout << "0.00\n"; continue; }
		if (y >= r) { cout << fixed << setprecision(2) << r * r * pi << endl; continue; }
		cout << fixed << setprecision(2) << r * r * (pi - acos(y / r)) + sqrt(r * r - y * y) * y << endl;
	}
	return 0;
}
