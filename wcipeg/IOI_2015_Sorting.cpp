#include <bits/stdc++.h>
using namespace std;

int T, N, S[200005], H[200005], M, l, r, mid, now;
bool v[200005];
pair<int, int> ch[600005];
vector<pair<int, int>> ans;
int check();
void DFS(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N; for (int i = 0; i < N; ++i) cin >> S[i], H[S[i]] = i;
  cin >> M; for (int i = 0; i < M; ++i) cin >> ch[i].first >> ch[i].second;
  l = -1; r = N * 3;
  while (l < r - 1) {
    mid = (l + r) >> 1;
    for (int i = 0; i < N; ++i) S[H[i]] = i;
    for (int i = 0; i < mid; ++i) swap(S[ch[i].first], S[ch[i].second]);
    if (check() <= mid) r = mid;
    else l = mid;
  }
  cout << r << '\n'; ans.clear();
  memset(v, false, sizeof(v));
  for (int i = 0; i < N; ++i) S[H[i]] = i;
  for (int i = 0; i < r; ++i) swap(S[ch[i].first], S[ch[i].second]);
  for (int i = 0; i < N; ++i) {
    if (!v[i]) {
      v[i] = true;
      now = i;
      while (!v[S[now]]) {
        ans.push_back(make_pair(S[now], S[S[now]]));
        now = S[now];
        v[now] = true;
      }
    }
  }
  if (ans.size() < r) ans.push_back(make_pair(0, 0));
  for (int i = 0; i < N; ++i) S[H[i]] = i;
  for (int i = 0; i < r; ++i) {
    swap(H[S[ch[i].first]], H[S[ch[i].second]]);
    swap(S[ch[i].first], S[ch[i].second]);
    cout << H[ans[i].first] << H[ans[i].second] << '\n';
    swap(H[ans[i].first], H[ans[i].second]);
    swap(S[H[ans[i].first]], S[H[ans[i].second]]);
  }
  return 0;
}

int check() {
  int cycle = 0;
  memset(v, false, sizeof(v));
  for (int i = 0; i < N; ++i) {
    if (!v[i]) {
      cycle++;
      DFS(i);
    }
  }
  return N - cycle;
}

void DFS(int x) {
  v[x] = true;
  if (!v[S[x]]) DFS(S[x]);
}
