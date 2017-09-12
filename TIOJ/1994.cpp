#include <bits/stdc++.h>
using namespace std;

const int maxn = 3000;
typedef vector<vector<int>> vi;

vector<vector<int>> r(const vector<vector<int>>& a) {
	vector<vector<int>> ret(a.size());
	for (int i = 0; i < a.size(); ++i) ret[i].resize(a.size());
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a.size(); ++j) {
			ret[i][j] = a[j][i]; 
		}
	}
	return ret;
}

vector<vector<int>> rr(const vector<vector<int>>& a) {
	vector<vector<int>> ret(a.size());
	for (int i = 0; i < a.size(); ++i) ret[i].resize(a.size());
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a.size(); ++j) {
			ret[i][j] = a[a.size()-j-1][a.size()-i-1]; 
		}
	}
	return ret;
}

vector<vector<int>> merge(const vi& a, const vi& b, const vi& c, const vi& d) {
	int k = 0;
	vector<vector<int>> ret(a.size() + a.size());
	for (int i = 0; i < a.size() + a.size();++i) ret[i].resize(a.size() + a.size());
	for (int i = 0; i < a.size(); ++i){
		for (int j = 0; j < a.size(); ++j) {
			ret[i][j] = a[i][j] + k;
		}
	}
	k += a.size() * a.size();
	for (int i = 0; i < a.size(); ++i){
		for (int j = 0; j < a.size(); ++j) {
			ret[i + a.size()][j] = b[i][j] + k;
		}
	}
	k += a.size() * a.size();
	for (int i = 0; i < a.size(); ++i){
		for (int j = 0; j < a.size(); ++j) {
			ret[i + a.size()][j + a.size()] = c[i][j] + k;
		}
	}
	k += a.size() * a.size();
	for (int i = 0; i < a.size(); ++i){
		for (int j = 0; j < a.size(); ++j) {
			ret[i][j + a.size()] = d[i][j] + k;
		}
	}
	return ret;
}

int main() {
	int n; cin >> n;
	if (n == 0) {
		cout << "0" << endl;
		return 0;
	}
	vector<vector<int>> a(2);
	a[0].push_back(0); a[0].push_back(3); a[1].push_back(1); a[1].push_back(2);
	for (int i = 1; i < n; ++i) {
		vector<vector<int>> lu = r(a), ru = rr(a), ld = a, ud = a;
		a = merge(lu, ld, ud, ru);
	} 
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a.size(); ++j) cout << a[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
