#include <iostream>
#include <cstring>
#include <cmath>
#define MAX 1299709
using namespace std;

void build(bool* prime, int* primes) {
	memset(prime, true, sizeof(prime));
	prime[1] = false;
	int i;
	int index = 0;
	for (i = 2; i <= (int)sqrt(MAX); ++i) {
		if (prime[i]) {
			for (int j = i * i; j <= MAX; j += i) {
				prime[j] = false;
			}
			primes[index++] = i;
		}
	}
}

int main() {
	bool prime[MAX];
	int primes[10000];
	build(prime, primes);
	for (int i = 0; i < 10000; ++i) {
		cout << primes[i] << ' ';
	}

	return 0;
}
// int main() {
// 	build();
// 	int n;
// 	while (cin >> n) {
// 		if (n == 0) {
// 			break;
// 		}
// 		int mid = 9999 / 2;
// 		int left = 0;
// 		int right = 10000 - 1;
// 		int prevL = left, prevR = right;
// 		while (primes[mid] != n) {
// 			if (left >= right) {
// 				break;
// 			}
// 			if (mid > n) {
// 				prevR = right;
// 				right = mid - 1;
// 			}
// 			else if (mid < n) {
// 				prevL = left;
// 				left = mid + 1;
// 			}
// 			mid = (left + right) / 2;
// 		}
// 		cout << primes[prevR] - primes[prevL] << endl;
// 	}
// 	return 0;
// }
