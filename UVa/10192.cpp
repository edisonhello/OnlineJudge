#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
string s, t;
int LCS[maxn][maxn], kase;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	while (getline(cin, s), s != "#") {
		getline(cin, t);
		memset(LCS, 0, sizeof(LCS));
		for (int i = 0; i < s.length(); ++i) {
			for (int j = 0; j < t.length(); ++j) {
				if (s[i] == t[j]) LCS[i + 1][j + 1] = LCS[i][j] + 1;
				else LCS[i + 1][j + 1] = max(LCS[i + 1][j], LCS[i][j + 1]);
			}
		}
		cout << "Case #" << ++kase << ": you can visit at most " << LCS[s.length()][t.length()] << " cities.\n";
	}
	return 0;
}
