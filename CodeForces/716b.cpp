#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {
  string s;
  getline(cin, s);
  string nicestr;
  bool isNice = true;
  if(s.size() < 26) {
    isNice = false;
  } else {
    for (int i = 0; i < s.size() - 25; i++) {
      int cnt[26] = {0};
      vector<int> unknown;
      for(int j = i;j < i + 26;j++) {
        if(s[j] >= 'A' && s[j] <= 'Z') {
          if(cnt[s[j] - 65] > 0) {
            isNice = false;
            break;
          }
          else {
            cnt[s[j] - 65]++;
            isNice = true;
          }
        }
        else {
          unknown.push_back(j - i);
        }
      }
      if(isNice) {
        if(!unknown.empty()) {
          nicestr = s.substr(i,26);
          for(int j = 0;j < unknown.size();j++){
            for(int k = 0;k < 26;k++) {
              if(cnt[k] == 0) {
                cnt[k] = 1;
                //cout << unknown[j] << endl;
                nicestr[unknown[j]] = (char)(k + 65);
                break;
              }
            }
          }
        }
        for (int j = 0; j < 26; ++j) s[i + j] = nicestr[j];
        break;
      }
    }
  }
  for (int i = 0; i < s.size(); ++i) if (s[i] == '?') s[i] = 'A';
  if(isNice) cout << s << endl;
  else cout << -1 << endl;
}
