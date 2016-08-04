#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

struct work {
	int start;
	int end;
};

int convert(string s) {
	int h = (s[0] - '0') * 10 + s[1] - '0';
	int m = (s[3] - '0') * 10 + s[4] - '0';
	return h * 60 + m;
}

string reverse(int h, int m) {
	string s;
	s += (char(h / 10));
	s += (char(h % 10));
	s += (':');
	s += (char(m / 10));
	s += (char(m % 10));
	return s;
}

int main() {
	int n, s;
	string str;
	work app[100];
	while (cin >> s  ) {
		for (int j = 0; j < s; ++j) {
			getline(cin, str);
			app[j].start = convert(str.substr(0, 5));
			app[j].end = convert(str.substr(6, 5));
		}
		int max = app[0].start - 600;
		int maxindex = 0;
		for (int j = 1; j < s; ++j) {
			if (app[j].start - app[j - 1].end > max) { 
				max = app[j].start - app[j - 1].end;
				maxindex = j;
			}
		}
		if (1080 - app[s - 1].end > max) max = 1080 - app[s - 1].end;
		if (max < 60) {
			cout << "Day #" << n << ": the longest nap start at" << reverse(app[maxindex].start / 60, app[maxindex].start % 60) << " and will last for " << max << " minutes." << endl;
		}
	}
	return 0;
}