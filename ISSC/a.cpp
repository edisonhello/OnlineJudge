#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; while (cin >> n, n) {
        int tmp = n;
		int a = 0;
		for (int i = 0; ; ++i) {
			if ((1 << i) > n) break;
			if ((1 << i) & n) ++a;
		}
		int b = 0, nn = 0, t = 1;
		while (n) {
			 int k = n % 10;
			 nn += t * k;
			 n /= 10;	
			 t *= 16;
		}
		for (int i = 0; ; ++i) {
			if ((1 << i) > nn) break;
			if ((1 << i) & nn) ++b;
		}
		cout<< a << ' ' << b <<endl;
	}
}
