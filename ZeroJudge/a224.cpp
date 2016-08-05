#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>
using namespace std;

int main() {
	string s;
	int t[26];
	while (cin >> s) {
		int len = 0;
		memset(t, 0, sizeof(t));
		for (int i = 0; i < s.length(); ++i) {
			if (isalpha(s[i])) {
				if (s[i] >= 97) {
					t[s[i] - 97]++;
				} else {
					t[s[i] - 65]++;
				}
				len++;
			}
		}
		int odd = 0;
		for (int i = 0; i < 26; ++i) {
			if (t[i] % 2 == 1) {
				odd++;
			}
		}
		if (len % 2 == 1) {
			if (odd == 1) {
				cout << "yes !" << endl;
			} else {
				cout << "no..." << endl;
			}
		} else {
			if (odd == 0) {
				cout << "yes !" << endl;
			} else {
				cout << "no..." << endl;
			}
		}
	}
	return 0;
}