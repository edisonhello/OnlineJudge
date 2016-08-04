#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

void swap(char* a, char* b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(string s, int L, int R) {
	int i, j;
	if (L < R) {
		i = L; j = R + 1;
		while (true) {
			while (i < R && static_cast<int>(s[++i]) < static_cast<int>(s[L]));
			while (j > L && static_cast<int>(s[--j]) > static_cast<int>(s[L]));
			if (i >= j) {
				break;
			}
			swap(&s[i], &s[j]);	
		}
	}
	swap(&s[L], &s[j]);
	sort(s, L, j - 1);
	sort(s, j + 1, R);
}

int freq(string s, int& begin) {
	char c = s[begin];
	int cnt = 0;
	while (s[begin] == c) {
		begin++; cnt++;
	}
	return cnt;
}

int main() {
	string s;
	while (getline(cin, s)) {
		sort(s, 0, s.length() - 1);
		int begin = 0;
		while (begin < s.length()) {
			cout << freq(s, begin);
		}
		cout << '\n';
	}
	return 0;
}