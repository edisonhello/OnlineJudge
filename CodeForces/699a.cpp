#include <iostream>
#include <string>
using namespace std;

struct partical {
	int position;
	int move;
};

int main() {
	partical p[200000];
	int n;
	cin >> n;
	string s;
	cin >> s;
	int max = 0;
	int pos;
	for (int i = 0; i < n; ++i) {
		cin >> pos;
		p[i].position = pos;
		if (i > 0 && p[i].position - p[i - 1].position > max) max = p[i].position - p[i - 1].position;
		p[i].move = s[i] == 'R' ? 1 : -1;
	}
	int t = 1;
	bool keep = true;
	while (keep) {
		p[0].position += p[0].move;
		for (int i = 1; i < n && keep; ++i) {
			p[i].position += p[i].move;
			if (p[i].position == p[i - 1].position || p[i].position == p[i + 1].position) {
				keep = false;
			}
			if (t > max) {
				cout << -1 << endl;
				return 0;
			}
		}
		t++;
	}
	cout << t << endl;
	return 0;
}
