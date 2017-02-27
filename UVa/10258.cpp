#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;

int T;
string s;
bool par[maxn];

struct Submission { int id, pid, t; char verdict; };
vector<Submission> sub;

struct User {
  int id, solve, pen[10], sum;
  bool ac[10];
  User() {
    memset(ac, false, sizeof(ac));
    memset(pen, 0, sizeof(pen));
    solve = 0; sum = 0;
  }
} user[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; getline(cin, s); getline(cin, s);
  while (T--) {
    sub.clear();
    memset(user, 0, sizeof(user));
    for (int i = 1; i <= 100; ++i) user[i].id = i;
    memset(par, false, sizeof(par));
    while (getline(cin, s), s != "") {
      stringstream ss(s);
      Submission tmp;
      ss >> tmp.id >> tmp.pid >> tmp.t >> tmp.verdict;
      sub.push_back(tmp);
    }
    for (Submission sb : sub) {
      par[sb.id] = true;
      if (sb.verdict == 'R' || sb.verdict == 'U' || sb.verdict == 'E') continue;
      if (sb.verdict == 'C' && !user[sb.id].ac[sb.pid]) ++user[sb.id].solve, user[sb.id].ac[sb.pid] = true, user[sb.id].pen[sb.pid] += sb.t;
      else if (sb.verdict == 'I' && !user[sb.id].ac[sb.pid]) user[sb.id].pen[sb.pid] += 20;
    }
    vector<User> v;
    for (int i = 1; i <= 100; ++i) if (par[i]) v.push_back(user[i]);
    for (User& u : v) {
      u.sum = 0;
      for (int i = 1; i <= 9; ++i) if (u.ac[i]) u.sum += u.pen[i];
    }
    sort(v.begin(), v.end(), [](const User& a, const User& b) -> bool {
      if (a.solve != b.solve) return a.solve > b.solve;
      if (a.sum != b.sum) return a.sum < b.sum;
      return a.id < b.id;
    });
    for (User u : v) cout << u.id << ' ' << u.solve << ' ' << u.sum << '\n';
    if (T) cout << '\n';
  }
  return 0;
}
