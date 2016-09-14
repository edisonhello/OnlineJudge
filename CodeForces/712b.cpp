#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
  int L = 0, R = 0, U = 0, D = 0;
  string s;
  cin >> s;
  int cnt1 = 0; int cnt2 = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'L') L++;
    if (s[i] == 'R') R++;
    if (s[i] == 'U') U++;
    if (s[i] == 'D') D++;
  }
  if (L > R) {
    if ((L + R) % 2 == 1) {
      cnt1 += L - R;
      if (U > D) {
        D += 1;
        if (D == U) cnt1 += 1;
        else {
          if ((D + U) % 2 == 0) cnt1 += U - D;
          else {cnt1 = -1; goto jizz;}
        }
      } else {
        U += 1;
        if (D == U) cnt1 += 1;
        else {
          if ((D + U) % 2 == 0) cnt1 += D - U;
          else {cnt1 = -1; goto jizz;}
        }
      }
    } else {
      if (U > D) {
        if ((U + D) % 2 == 0) cnt1 += U - D;
        else {cnt1 = -1; goto jizz;}
      } else {
        if ((U + D) % 2 == 0) cnt1 += D - U;
        else {cnt1 = -1; goto jizz;}
      }
    }
  } else {
    if ((L + R) % 2 == 1) {
      cnt1 += R - L;
      if (U > D) {
        D += 1;
        if (D == U) cnt1 += 1;
        else {
          if ((D + U) % 2 == 0) cnt1 += U - D;
          else {cnt1 = -1; goto jizz;}
        }
      } else {
        U += 1;
        if (D == U) cnt1 += 1;
        else {
          if ((D + U) % 2 == 0) cnt1 += D - U;
          else {cnt1 = -1; goto jizz;}
        }
      }
    } else {
      if (U > D) {
        if ((U + D) % 2 == 0) cnt1 += U - D;
        else {cnt1 = -1; goto jizz;}
      } else {
        if ((U + D) % 2 == 0) cnt1 += D - U;
        else {cnt1 = -1; goto jizz;}
      }
    }
  }
  jizz:

  if (U > D) {
    if ((U + D) % 2 == 1) {
      cnt2 += U - D;
      if (L > R) {
        R += 1;
        if (L == R) cnt2 += 1;
        else {
          if ((L + R) % 2 == 0) cnt2 += L - R;
          else {cnt2 = -1; goto jizz2;}
        }
      } else {
        L += 1;
        if (L == R) cnt2 += 1;
        else {
          if ((R + L) % 2 == 0) cnt2 += R - L;
          else {cnt2 = -1; goto jizz2;}
        }
      }
    } else {
      if (L > R) {
        if ((L + R) % 2 == 0) cnt2 += L - R;
        else {cnt2 = -1; goto jizz2;}
      } else {
        if ((L + R) % 2 == 0) cnt2 += R - L;
        else {cnt2 = -1; goto jizz2;}
      }
    }
  } else {
    if ((U + D) % 2 == 1) {
      cnt2 += D - U;
      if (L > R) {
        R += 1;
        if (L == R) cnt2 += 1;
        else {
          if ((L + R) % 2 == 0) cnt2 += L - R;
          else {cnt2 = -1; goto jizz2;}
        }
      } else {
        L += 1;
        if (L == R) cnt2 += 1;
        else {
          if ((L + R) % 2 == 0) cnt2 += R - L;
          else {cnt2 = -1; goto jizz2;}
        }
      }
    } else {
      if (L > R) {
        if ((L + R) % 2 == 0) cnt2 += L - R;
        else {cnt2 = -1; goto jizz2;}
      } else {
        if ((L + R) % 2 == 0) cnt2 += R - L;
        else {cnt2 = -1; goto jizz2;}
      }
    }
  }
  jizz2:
  if (cnt1 == -1 && cnt2 == -1) printf("-1\n");
  else {
    if (cnt1 == -1) printf("%d\n", cnt2);
    else if (cnt2 == -1) printf("%d\n", cnt1);
    else {
      if (cnt1 > cnt2) printf("%d\n", cnt2);
      else printf("%d\n", cnt1);
    }
  }
  return 0;
}
