#include <cstdio>
#include <algorithm>
#include <queue>
#include <bitset>
#include <vector>
#include <utility>
#define getchar getchar_unlocked
#define int long long
using namespace std;

char __c;
bool flag;

template <typename T>
inline bool rit(T& x) {
  __c = 0, flag = false;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

const int MAX = 100000 + 5;
int N, M, B, C[MAX], L[MAX], root, tot, Max;

struct Heap {
  int id;
  bool operator<(const Heap& rhs) const {
    return C[id] < C[rhs.id];
  }
};

bitset<MAX> v;
vector<int> tree[MAX];
pair<priority_queue<Heap, vector<Heap>, less<Heap>>*, int> DFS(int);

signed main() {
  rit(N, M);
  for (int i = 1; i <= N; ++i) {
    rit(B, C[i], L[i]);
    if (B) tree[B].push_back(i);
    else root = i;
  }
  pair<priority_queue<Heap, vector<Heap>, less<Heap>>*, int> ans = DFS(root);
  priority_queue<Heap, vector<Heap>, less<Heap>>* pq = ans.first;
  tot = ans.second;
  while (tot > M) tot -= C[pq->top().id], pq->pop();
  Max = max(Max, (int)(L[root] * pq->size()));
  printf("%lld\n", Max);
  return 0;
}

pair<priority_queue<Heap, vector<Heap>, less<Heap>>*, int> DFS(int x) {
  priority_queue<Heap, vector<Heap>, less<Heap>>* ret = new priority_queue<Heap, vector<Heap>, less<Heap>>;
  ret->push((Heap){ x });
  v[x] = true;
  int cur = C[x];
  for (int u : tree[x]) {
    if (!v[u]) {
      pair<priority_queue<Heap, vector<Heap>, less<Heap>>*, int> jizz = DFS(u);
      priority_queue<Heap, vector<Heap>, less<Heap>>* res = jizz.first;
      if (res->size() < ret->size()) while (res->size()) ret->push(res->top()), res->pop();
      else {
        while (ret->size()) res->push(ret->top()), ret->pop();
        ret = res;
      }
      cur += jizz.second;
    }
  }
  while (cur > M) cur -= C[ret->top().id], ret->pop();
  Max = max(Max, (int)(L[x] * ret->size()));
  return make_pair(ret, cur);
}
