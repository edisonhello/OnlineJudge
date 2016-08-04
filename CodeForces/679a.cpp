#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

bool prime[101];
vector<int> p;

void build() {
	memset(prime, true, sizeof(prime));
	prime[1] = false;
	for (int i = 2; i < 101; ++i) {
		if (prime[i]) {
			p.push_back(i);
			for (int j = i * i; j < 101; j += i) {
				prime[j] = false;
			}
		}
	}
}

int main() {
	int d = 0;
	int i = 0;
	string s;
	build();
	for (int i = 0; i < )
	return 0;
}