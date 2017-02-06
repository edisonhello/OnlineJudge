#include <bits/stdc++.h>
#define fi first
#define se second
#define F(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
using namespace std;
typedef vector<int> vi;

struct treap {
	treap *lc, *rc;
	int size;
	int cnt[27];
	int tag;
	int val;
	treap (int _val, int _tag = -1) {
		val = _val;
		tag = _tag;
		size = 1;
		F (i, 26) cnt[i] = 0;
		lc = rc = NULL;
	}
};

#define sz(x) (x ? x -> size : 0)

void push(treap *t) {
	if(t -> tag + 1) {
		if(t -> lc) t -> lc -> tag = t -> lc -> val = t -> tag;
		if(t -> rc) t -> rc -> tag = t -> rc -> val = t -> tag;
		t -> tag = -1;
	}
}

void pull(treap *t) {
	t -> size = sz(t -> lc) + 1 + sz(t -> rc);
	F(i, 26) t -> cnt[i] = 0;
	if(t -> lc) {
		if(t -> lc -> tag + 1) t -> cnt[t -> lc -> tag] += sz(t -> lc);
		else F (i, 26) t -> cnt[i] += t -> lc -> cnt[i];
	}
	if(t -> rc) {
		if(t -> rc -> tag + 1) t -> cnt[t -> rc -> tag] += sz(t -> rc);
		else F (i, 26) t -> cnt[i] += t -> rc -> cnt[i];
	}
	t -> cnt[t -> val]++;
}

treap* merge(treap *a, treap *b) {
	treap *t;
	if (!a) return b; if(!b) return a;
	if (rand() % (sz(a) + sz(b)) < sz(a)) {
		t = a;
		push(t);
		t -> rc = merge(a -> rc, b);
	} else {
		t = b;
		push(t);
		t -> lc = merge(a, b -> lc);
	}
	pull(t);
	return t;
}

void split(treap *t, int k, treap *&a, treap *&b) {
	if (!t) { a = b = NULL; return; }
	push(t);
	if (k >= sz(t -> lc) + 1) {
		a = t;
		split(t -> rc, k - sz(t -> lc) - 1, a -> rc, b);
		pull(a);
	} else {
		b = t;
		split(t -> lc, k, a, b -> lc);
		pull(b);
	}
}

void print(treap *t) {
	if(!t) return;
	push(t);
	if(t -> lc) print(t -> lc);
	cout << (char)(t -> val + 'a');
	if(t -> rc) print(t -> rc);
	pull(t);
}

int main () {
	int n, m; cin >> n >> m;
	string s; cin >> s;
	treap *t = NULL;
	assert(s.length() == n);
	F (i, s.length()) t = merge(t, new treap(s[i] - 'a'));

	F (hgrkjhgkjhgt, m) {
		int i, j, k; cin >> i >> j >> k;
		treap *a, *b, *c, *d, *e;
		split(t, i - 1, a, b);
		split(b, j - i + 1, b, c);
		int sum = 0, count[26];
		F (i, 26) (count[i] = b -> cnt[i]);
		if (k) {
			if (b -> tag + 1) ;
			else F (p, 26) {
				if (!count[p]) continue;
				split(b, sum, d, b);
				split(b, count[p], b, e);
				b -> tag = b -> val = p;
				b = merge(d, merge(b, e));
				sum += count[p];
			}
		} else {
			if (b -> tag + 1) ;
			else for(int p = 25; p >= 0; --p) {
				if (!count[p]) continue;
				split(b, sum, d, b);
				split(b, count[p], b, e);
				b -> tag = b -> val = p;
				b = merge(d, merge(b, e));
				sum += count[p];
			}
		}
		t = merge(a, merge(b, c));
	}
	print(t); //cout << '\n';
	return 0;
}
