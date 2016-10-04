#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

string s;

struct pf {
  int start, end, len;
  pf(int start, int end, int len): start(start), end(end), len(len) {}
  pf() {}
};

int cnt[26];
vector<pf> postfix;
void CountingSort(int);
void RadixSort();
void debug();
int cmp(const pf&, int);

int main() {
  cin >> s;
  int len = s.length();
  for (int i = 0; i < s.length(); ++i) {
    postfix.push_back(pf(i, s.length() - 1, len));
    len--;
  }
  RadixSort();
  for (int i = 0; i < postfix.size(); ++i) {
    cout << s.length() - postfix[i].len << endl;
  }
  return 0;
}

void debug() {
  for (int i = 0; i < 26; ++i) cout << (char)(i + 'a') << ": " << cnt[i] << endl;
}

void CountingSort(int pos) {
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < postfix.size(); ++i) {
    if (s.length() - pos > postfix[i].len) continue;
    cnt[s[postfix[i].end--] - 'a']++;
  }
  for (int i = 1; i < 26; ++i) cnt[i] += cnt[i - 1];
  // debug();
  stable_sort(postfix.begin(), postfix.end(), [pos](const pf& a, const pf& b) -> bool{return cmp(a, pos) < cmp(b, pos);});
}

int cmp(const pf& a, int pos) {
  if (s.length() - pos > a.len) return 27;
  return cnt[s[a.end + 1] - 'a'];
}

void RadixSort() {
  for (int j = 0; j < s.length(); ++j) CountingSort(j);
}
