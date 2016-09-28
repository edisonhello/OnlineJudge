#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

map<char, int> mp;
vector<pair<char, int> > vec;
int n, k;
char c;

bool cmp(pair<char, int> p1, pair<char, int> p2) {
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second > p2.second;
}

int main() {
	cin >> n;
	while (n--) {
		cin >> k;
		vec.clear();
		mp.clear();
		for (int i = 0; i < k; ++i) {
			cin >> c;
			if (mp.find(c) == mp.end()) {
				mp[c] = 0;
			}
			mp[c]++;
		}

		for (map<char, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
			vec.push_back(pair<char, int>(it->first, it->second));
		}
		sort(vec.begin(), vec.end(), cmp);
		int mx = vec[0].second;
		// cout << "mx: " << mx << endl;
		for (int i = 0; i < vec.size(); ++i) {
			if (vec[i].second == mx) cout << vec[i].first;
			else break;
		}
		cout << endl;
	}
	return 0;
}
