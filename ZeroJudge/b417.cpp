#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
const int maxm = 1000000 + 5;
int S[maxn], N, M, most, individual, cnt[maxn], freq[maxn];
pair<int, int> ans[maxm];

struct Query {
  int L, R, block, i;
  bool operator<(const Query& q) const {
    return block == q.block ? R < q.R : block < q.block;
  }
} query[maxm];


void add(int);
void sub(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> M;
  int lim = 1 + (int)sqrt(N);
  for (int i = 1; i <= N; ++i) cin >> S[i];
  for (int i = 0; i < M; ++i) {
    cin >> query[i].L >> query[i].R;
    query[i].block = query[i].L / lim;
    query[i].i = i;
  }
  sort(query, query + M);
  for (int i = 0, L = 1, R = 0; i < M; ++i) {
    while (R < query[i].R) add(++R);
    while (R > query[i].R) sub(R--);
    while (L > query[i].L) add(--L);
    while (L < query[i].L) sub(L++);
    ans[query[i].i] = make_pair(most, freq[most]);
  }
  for (int i = 0; i < M; ++i) cout << ans[i].first << ' ' << ans[i].second << '\n';
  return 0;
}

void add(int bound) {
  freq[cnt[S[bound]]]--;
  cnt[S[bound]]++;
  freq[cnt[S[bound]]]++;
  while (freq[most + 1]) most++;
}

void sub(int bound) {
  freq[cnt[S[bound]]]--;
  cnt[S[bound]]--;
  freq[cnt[S[bound]]]++;
  while (!freq[most]) most--;
}
