#include<bits/stdc++.h>
using namespace std;
#define ll long long
int old[66],nw[66];

int isnot(int a,int b){
	bool faf[5];
	memset(faf,0,sizeof(faf));
	faf[a]=1; faf[b]=1;
	if(!faf[1])return 1;
	if(!faf[2])return 2;
	if(!faf[3])return 3;
}

ll proc(int now,int from,int to){
	// cout<<now<<" "<<from<<" "<<to<<endl;
	if(now==0)return 0;
	if(from==to)return 0;
	ll rt=0;
	for(int i=now-1;i>0;--i){
		if(old[i]==from || old[i]==to){
			rt+=proc(i,old[i],isnot(from,to));
		}
	}
	old[now]=to;
	return ++rt;
}

int main(){
	int n; while(cin>>n, n){
		for(int i=1;i<=n;++i)cin>>old[i];
		for(int i=1;i<=n;++i)cin>>nw[i];
		ll ans=0;
		for(int i=n;i>0;--i){
			ans+=proc(i,old[i],nw[i]);
		} cout<<ans<<endl;
	}
}
