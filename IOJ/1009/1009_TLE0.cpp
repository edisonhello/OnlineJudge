#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n,m,k,cnt,a,b;
bool isWent[110];
vector<int> vec[110];
string s;

void DFS(int start,int len) {
  //if(!isWent[start]) {
    if(start == b) {
      cnt++;
    }
    if(len == 0) return;
    //isWent[start] = true;
    for(int i = 0;i < vec[start].size();i++) {
      DFS(vec[start][i],len-1);
    }
    //isWent[start] = false;
  //}
}

int main() {
  cin >> n >> m;
  // for (int i = 0; i < n; ++i) {
  //   cin >> s;
  //   for (int j = 0; j < n; ++j) {
  //     if (s[j] == '1') vec[i + 1].push_back(j + 1);
  //   }
  // }
  while(m--) {
    int st,ed;
    cin >> st >> ed;
    vec[st].push_back(ed);
  }
  cin >> a >> b >> k;
  DFS(a,k);
  cout << cnt << endl;
}
