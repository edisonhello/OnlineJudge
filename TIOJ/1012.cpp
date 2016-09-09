#include <cstdio>
#include <stack>
using namespace std;

int t, n, m, A[1000], B[1000], i, ai = 0, bi = 0;
stack<int> S1, S2;

inline int rit() {
  t = 0;
  char c;
  do {
    c = getchar_unlocked();
    // if (c == '-') k = -1;
  } while (c < '0' || c > '9');
  do {
    t = t * 10 + c - '0';
    c = getchar_unlocked();
  } while (c >= '0' && c <= '9');
  return t;
}

int main() {
  n = rit(); m = rit();
  for (i = 0; i < n; ++i) {
    B[i] = rit();
    A[i] = i + 1;
  }
  while (bi < n) {
    if (S1.empty()) {
      // if (S2.empty() && ai < n) S1.push(A[ai++]);
      if (ai < n) S1.push(A[ai++]);
      else {
        if (!S2.empty()) {
          S1.push(S2.top());
          S2.pop();
        }
      }
    }
    else if (S1.top() == B[bi]) {
      S1.pop();
      bi++;
    } else if (S1.top() < B[bi]) {
      if (ai < n) S1.push(A[ai++]);
      else {
        if (!S2.empty()) {S1.push(S2.top()); S2.pop();}
        else {printf("no\n"); return 0;}
      }
    } else {
      if (S2.size() < m) {
        S2.push(S1.top());
        S1.pop();
      } else {
        printf("no\n");
        return 0;
      }
    }

  }
  printf("yes\n");
  return 0;
}
