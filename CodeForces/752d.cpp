#include <iostream>
#include <queue>
using namespace std;

const int maxn = 100000 + 5;

struct S {
  string s;
  int v;
  bool operator<(const S& rhs) const {
    return v < rhs.v;
  }
} s[maxn];

int k, n;
priority_queue<S> pq;
string ret;

int main() {
  cin >> k >> n;
  for (int i = 0; i < k; ++i) cin >> s[i].s >> s[i].v;
  for (int i = 0; i < k; ++i) pq.push(s[i]);
  ret = "";
  while (pq.size()) {
    S a = pq.top(); pq.pop();
    S b = pq.top(); pq.pop();
    
  }
}
