#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, bool> m;

int main() {
	string s;
	while (getline(cin, s)) {
		if (m.find(s) == m.end()) {
			cout << "NO" << endl;
			m[s] = true;
		} else {
			cout << "YES" << endl;
		}
	}
	return 0;
}