#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

string s;
int N;
string x, y, a, b, p;

bool cmp1(const string& a, const string& b) {
  return a.length() == b.length() ? a < b : a.length() < b.length();
}

bool cmp2(const string& a, const string& b) {
  return a.length() == b.length() ? a > b : a.length() > b.length();
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  while (cin >> N) {
    stack<string> st;
    queue<string> q;
    priority_queue<string, vector<string>, function<bool(string, string)> > pq1(cmp1);
    priority_queue<string, vector<string>, function<bool(string, string)> > pq2(cmp2);
    for (int i = 0; i < N; ++i) {
      cin >> s;
      if (s == "ダメよ～ダメダメ") {
        cin >> x >> y;
        if (x == "1") st.push(y);
        if (x == "2") q.push(y);
        if (x == "3") pq1.push(y);
        if (x == "4") pq2.push(y);
      } else if (s == "しかしお兄ちゃんはわりと弱気だからなぁ……アタシの方からアプローチしないとダメかな") {
        cin >> a >> b;
        if (a == "1") {
          if (st.empty()) {}
          else {
            if (b == "1") {st.push(st.top()); st.pop();}
            if (b == "2") {q.push(st.top()); st.pop();}
            if (b == "3") {pq1.push(st.top()); st.pop();}
            if (b == "4") {pq2.push(st.top()); st.pop();}
          }
        } else if (a == "2") {
          if (q.empty()) {}
          else {
            if (b == "1") {st.push(q.front()); q.pop();}
            if (b == "2") {q.push(q.front()); q.pop();}
            if (b == "3") {pq1.push(q.front()); q.pop();}
            if (b == "4") {pq2.push(q.front()); q.pop();}
          }
        } else if (a == "3") {
          if (pq1.empty()) {}
          else {
            if (b == "1") {st.push(pq1.top()); pq1.pop();}
            if (b == "2") {q.push(pq1.top()); pq1.pop();}
            if (b == "3") {pq1.push(pq1.top()); pq1.pop();}
            if (b == "4") {pq2.push(pq1.top()); pq1.pop();}
          }
        } else if (a == "4") {
          if (pq2.empty()) {}
          else {
            if (b == "1") {st.push(pq2.top()); pq2.pop();}
            if (b == "2") {q.push(pq2.top()); pq2.pop();}
            if (b == "3") {pq1.push(pq2.top()); pq2.pop();}
            if (b == "4") {pq2.push(pq2.top()); pq2.pop();}
          }
        }
      } else {
        cin >> p;
        if (p == "1") {if (st.empty()) {cout << "イヤ...やめてよ...お兄ちゃん...壊れる\n";} else {cout << st.top() << endl; st.pop();}}
        if (p == "2") {if (q.empty()) {cout << "イヤ...やめてよ...お兄ちゃん...壊れる\n";} else {cout << q.front() << endl; q.pop();}}
        if (p == "3") {if (pq1.empty()) {cout << "イヤ...やめてよ...お兄ちゃん...壊れる\n";} else {cout << pq1.top() << endl; pq1.pop();}}
        if (p == "4") {if (pq2.empty()) {cout << "イヤ...やめてよ...お兄ちゃん...壊れる\n";} else {cout << pq2.top() << endl; pq2.pop();}}
      }
    }
  }
  return 0;
}
