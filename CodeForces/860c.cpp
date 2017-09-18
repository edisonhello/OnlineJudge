#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
bool v[maxn];
int fid[maxn];

struct file {
    string name;
    int type;
} f[maxn];

string parse(int n) {
    string ret;
    stringstream ss; ss << n; ss >> ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int e = 0;
    for (int i = 0; i < n; ++i) {
        cin >> f[i].name >> f[i].type;
        if (f[i].type == 1) ++e;
    }
    queue<int> a, b, aa, bb;
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = 0; j < f[i].name.size(); ++j) if (f[i].name[j] < '0' || f[i].name[j] > '9') ok = false;
        if (f[i].name[0] == '0') ok = false;
        if (!ok) {
            if (f[i].type == 1) a.push(i);
            else b.push(i);
            continue;
        }
        stringstream ss; ss << f[i].name; int id; ss >> id;
        if (id > n) {
            if (f[i].type == 1) a.push(i);
            else b.push(i);
            continue;
        }
        if (id <= e) {
            v[id] = true; fid[i] = id;
            if (f[i].type == 0) bb.push(i);
        } else if (id <= n) {
            v[id] = true; fid[i] = id;
            if (f[i].type == 1) aa.push(i);
        }
    }
    set<int> aaa, bbb;
    for (int i = 1; i <= e; ++i) if (!v[i]) aaa.insert(i);
    for (int i = e + 1; i <= n; ++i) if (!v[i]) bbb.insert(i);
    vector<pair<string, string>> ans;
    while (aa.size()) {
        int now = aa.front(); aa.pop();
        // cout << "aa: " << now << endl;
        if (aaa.size()) {
            ans.push_back(make_pair(f[now].name, parse(*aaa.begin())));
            aaa.erase(aaa.begin());
            bbb.insert(fid[now]);
        } else {
            aa.push(now);
            break;
        }
    }
    while (bb.size()) {
        int now = bb.front(); bb.pop();
        // cout << "bb: " << now << endl;
        if (bbb.size()) {
            ans.push_back(make_pair(f[now].name, parse(*bbb.begin())));
            bbb.erase(bbb.begin());
            aaa.insert(fid[now]);
        } else {
            bb.push(now);
            break;
        }
    }
    while (a.size()) {
        int now = a.front(); a.pop();
        // cout << "a: " << now << endl;
        if (aaa.size()) {
            ans.push_back(make_pair(f[now].name, parse(*aaa.begin())));
            aaa.erase(aaa.begin());
        } else {
            a.push(now);
            break;
        }
    }
    while (b.size()) {
        int now = b.front(); b.pop();
        // cout << "b: " << now << endl;
        if (bbb.size()) {
            ans.push_back(make_pair(f[now].name, parse(*bbb.begin())));
            bbb.erase(bbb.begin());
        } else {
            b.push(now);
            break;
        }
    }
    while (aa.size()) {
        int now = aa.front(); aa.pop();
        // cout << "aa: " << now << endl;
        if (aaa.size()) {
            ans.push_back(make_pair(f[now].name, parse(*aaa.begin())));
            aaa.erase(aaa.begin());
            bbb.insert(fid[now]);
            continue;
        }
        assert(bb.size() > 0);
        int bnow = bb.front(); bb.pop();
        // cout << "bb: " << bnow << endl;
        ans.push_back(make_pair(f[now].name, "bc4iaa"));
        ans.push_back(make_pair(f[bnow].name, f[now].name));
        ans.push_back(make_pair("bc4iaa", f[bnow].name));
    }
    while (bb.size()) {
        int now = bb.front(); bb.pop();
        // cout << "aa: " << now << endl;
        if (bbb.size()) {
            ans.push_back(make_pair(f[now].name, parse(*bbb.begin())));
            bbb.erase(bbb.begin());
            aaa.insert(fid[now]);
            continue;
        }
        assert(aa.size() > 0);
        int anow = aa.front(); aa.pop();
        // cout << "bb: " << bnow << endl;
        ans.push_back(make_pair(f[now].name, "bc4iaa"));
        ans.push_back(make_pair(f[anow].name, f[now].name));
        ans.push_back(make_pair("bc4iaa", f[anow].name));
    }
    while (a.size()) {
        int now = a.front(); a.pop();
        // cout << "a: " << now << endl;
        if (aaa.size()) {
            ans.push_back(make_pair(f[now].name, parse(*aaa.begin())));
            aaa.erase(aaa.begin());
        } else {
            a.push(now);
            break;
        }
    }
    while (b.size()) {
        int now = b.front(); b.pop();
        // cout << "b: " << now << endl;
        if (bbb.size()) {
            ans.push_back(make_pair(f[now].name, parse(*bbb.begin())));
            bbb.erase(bbb.begin());
        } else {
            b.push(now);
            break;
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans) {
        cout << "move " << i.first << ' ' << i.second << endl;
    }
}
