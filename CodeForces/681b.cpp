#include <iostream>
using namespace std;

const long long int HOUSE = 1234567;
const long long int CAR = 123456;
const long long int COMPUTER = 1234;

int main() {
	long long int n;	
	cin >> n;
	int maxH = n / HOUSE + 1;
	int maxC = n / CAR + 1;
	int maxCOM = n / COMPUTER + 1;
	for (long long int i = 0; i <= maxCOM; ++i) {
		for (long long int j = 0; j <= maxC; ++j) {
			for (long long int k = 0; k <= maxH; ++k) {
				if (HOUSE * k + CAR * j + COMPUTER * i == n) {
					cout << "YES" << endl;
					return 0;
				}
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}