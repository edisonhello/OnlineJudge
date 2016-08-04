#include <iostream>
#include <cmath>
using namespace std;

const int pi = acos(1);
double abs(double x) {
	return x >= 0 ? x : -x;
}

int main() {
	double x, y, r;
	cin >> x >> y >> r;
	if (y < -r) {cout << '0' << endl; return 0;}

}
