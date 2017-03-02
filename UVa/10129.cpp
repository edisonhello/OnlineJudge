#include <bits/stdc++.h>
using namespace std;

const int sigma = 26;
int T, N, in[sigma], out[sigma];
bool apr[sigma], v[sigma];
vector<int> G[sigma];
vector<int> odd, valid;

void dfs(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    for (int i = 0; i < sigma; ++i) G[i].clear();
    memset(out, 0, sizeof(out));
    memset(in, 0, sizeof(in));
    memset(apr, false, sizeof(apr));
    memset(v, false, sizeof(v));
    odd.clear(); valid.clear();
    cin >> N;
    while (N--) {
      string s; cin >> s;
      apr[s[0] - 'a'] = true;
      apr[s[s.length() - 1] - 'a'] = true;
      G[s[0] - 'a'].push_back(s[s.length() - 1] - 'a');
      ++out[s[0] - 'a']; ++in[s[s.length() - 1] - 'a'];
    }
    for (int i = 0; i < sigma; ++i) {
      if (!apr[i]) continue;
      if ((in[i] + out[i]) & 1) odd.push_back(i);
      valid.push_back(i);
    }
    if (odd.empty()) {
      bool ans = false;
      for (int i = 0; i < sigma; ++i) if (in[i] != out[i]) { ans = true; cout << "The door cannot be opened.\n"; break; }
      if (ans) continue;
      dfs(valid[0]);
      for (int i : valid) if (!v[i]) { cout << "The door cannot be opened.\n", ans = true; break; }
      if (!ans) cout << "Ordering is possible.\n";
    } else if (odd.size() == 2) {
      bool ans = false;
      int st = -1, ed = -1;
      for (int i = 0; i < sigma && !ans; ++i) {
        if (out[i] == in[i] + 1) {
          if (st == -1) st = i;
          else cout << "The door cannot be opened.\n", ans = true;
        }
        if (!ans && in[i] == out[i] + 1) {
          if (ed == -1) ed = i;
          else cout << "The door cannot be opened.\n", ans = true;
        }
        if (!ans && (out[i] + in[i]) % 2 == 0 && out[i] != in[i]) cout << "The door cannot be opened.\n", ans = true;
        if (!ans && (out[i] + in[i]) % 2 == 1 && (out[i] > in[i] + 1 || out[i] + 1 < in[i])) cout << "The door cannot be opened.\n", ans = true;
      }
      if (ans) continue;
      dfs(st);
      for (int i : valid) if (!v[i]) { cout << "The door cannot be opened.\n", ans = true; break; }
      if (!ans) cout << "Ordering is possible.\n";
    } else cout << "The door cannot be opened.\n";
  }
  return 0;
}

void dfs(int x) {
  v[x] = true;
  for (int u : G[x]) if (!v[u]) dfs(u);
}
