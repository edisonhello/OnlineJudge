#include <bits/stdc++.h>
using namespace std;

const int maxn = 50;
bool dp[3][maxn][maxn], v[3][maxn][maxn];
string s;

char jizz(char a, char b){
	if (a=='a'){
		if (b=='a')return 'b';
		if (b=='b')return 'b';
		if (b=='c') return 'a';
	}
	if (a=='b'){
		if (b=='a')return 'c';
		if (b=='b') return 'b';
		if (b=='c')return 'a';
	}
	if (a == 'c') {
		if (b=='a')return 'a';
		if (b=='b')return 'c';
		if (b=='c') return 'c';
	}
}

bool f(int c, int l, int r) {
	//cout <<l<<' '<<r<<endl;
	if (v[c][l][r])return dp[c][l][r];
	if (l==r&&s[l]==c+'a')return true;
	char dd = s[l];
	for (int k = l+1; k <= r;++k){
		dd=jizz(dd,s[k]);
	}
	if (dd==c)dp[c][l][r]=true;
	for (int k = l; k < r;++k) {
		for (char d='a';d<='c';++d){
			for (char e = 'a';e <= 'c'; ++e) if (jizz(d,e)==(c+'a')) {
				dp[c][l][r]|=(f(d-'a',l,k)&&f(e-'a',k+1,r));
			}
		}
	}
	v[c][l][r] = true;
	return dp[c][l][r];
}
int main() {
	while (cin >> s) {
		if (s=="0")break;
		memset(dp, false, sizeof(dp)); memset(v,false,sizeof(v));
		//cout<<"jizz"<<endl;
		for (int i = 0; i < s.length() - 1;++i) {
			char as=jizz(s[i],s[i+1]);
			//cout<<as<<endl;
			dp[as -'a'][i][i+1]=true;
			v[as - 'a'][i][i+1] = true;
			for (char j='a';j<='c';++j){
				if (j==as)continue;
				dp[j-'a'][i][i+1]=false;
				v[j-'a'][i][i+1]=true;
			}
		}
		// for (int i = 3; i <= s.length(); +
		bool ans = f(0, 0, s.length() - 1);
		if (ans) cout << "yes"<<endl;
		else cout<<"no"<<endl;
 	}
 	return 0;
}
