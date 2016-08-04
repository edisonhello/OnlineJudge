#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char pre[53];
int root = 0;
char in[52];
string s;
void solve(int, int);

int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> m;
		cin >> pre;
		cin >> in;
		solve(0, m - 1);
		cout << endl;
	}
	return 0;
}

void solve(int left, int right) {
	if (left < right) {
		int mid;
		for (int i = left; i <= right; ++i) {
			if (in[i] == pre[left]) {
				mid = i;
			}
		}
		solve(left++, mid - 1);
		solve(mid + 1, right);
		cout << in[mid];	
	} else {
		cout << in[left];
	}
}