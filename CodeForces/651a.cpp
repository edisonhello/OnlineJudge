#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a1, a2;
	cin >> a1 >> a2;
	int t = 0;
	while (true) {
		if (a1 > a2) {
			a1 -= 2;
			a2++;
		} else {
			a2 -= 2;
			a1++;
		}
		if (a1 <= 0 || a2 <= 0) break;
		
		t++;
	}
	cout << t << endl;
	return 0;
}

//4 4 -> 2 5 -> 3 3 -> 1 4 -> 2 2 -> 0 3