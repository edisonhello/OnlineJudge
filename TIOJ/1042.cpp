#include <iostream>
#include <vector>
#include <tuple>
#include <bitset>
#define TP tuple<int, int, int>
using namespace std;

int n;
vector<TP> edge;
int w;
int djs[101], cnt, ans;
bitset<101> v;
TP tmp;

int F(int x) {return djs[x] == x ? x : djs[x] = F(djs[x]);}

void U(int a, int b) {
	a = F(a), b = F(b);
	return djs[a] = b;
}

void Kruskal() {
	for (int i = 0; i < edge.size(); ++i) {
		tmp = edge[i];
		if (F(get<1>(tmp)) == F(get<2>(tmp))) continue;
		U(get<1>(tmp), get<2>(tmp));
		
	}
}

bool cmp(TP a, TP b) {
	return get<0>(a) == get<0>b ? a < b ? get<0>(a) > get<0>(b);
}

int main() {
	while (cin >> n, n) {
		edge.clear();
		for (int i = 0; i < n; ++i) {
			djs[i] = i;
			for (int j = 0; j < n; ++j) {
				cin >> w;
				edge.push_back(make_pair(w, i, j));
			}
		}
		v.reset();
		sort(edge.begin(), edge.end(), cmp);
		Kruskal();
	}
}
