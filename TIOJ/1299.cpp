#include <iostream>
#include <cstring>
using namespace std;

int score(char c) {
	if (c > 90) {
		return c - 96;
	} else {
		return c - 64;
	}
}

char final(int score) {
	if (score <= 2) return 'D';
	else if (score <= 5) return 'C';
	else if (score <= 9) return 'B';
	else if (score <= 12) return 'A';
	else return 'S';
}

char name[10];

int main() {
	int sum;
	while (cin >> name) {
		sum = 0;
		for (int i = 0; i < strlen(name); ++i) {
			sum += score(name[i]);
		}
		sum = sum % 17;
		if (final(sum) == 'S') cout << "SA" << endl;
		else cout << final(sum) << endl;
	}
	return 0;
}