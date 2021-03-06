#include <cstdio>
#include <stack>
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

struct s {
  int id, h;
};

int N, leave[1000005], i;
s tmp;
stack<s> st;

int main() {
  rit(N);
  for (i = 0; i < N; ++i) {
    rit(tmp.h); tmp.id = i;
    while (st.size() && st.top().h < tmp.h) leave[st.top().id] = i, st.pop();
    st.push(tmp);
  }
  while (st.size()) leave[st.top().id] = N - 1, st.pop();
  for (i = 0; i < N; ++i) printf("%d\n", leave[i] - i);
  return 0;
}
