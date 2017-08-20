#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> G[555];
bool gf0[555],v[555],ans[555][555];

void test0(int now){
	if(gf0[now])return;
	gf0[now]=1;
	for(int i=0;i<G[now].size();++i)test0(G[now][i]);
}
void dfs(int now,int kill){
	if(now==kill)return;
	if(v[now])return;
	v[now]=1;
	for(int i=0;i<G[now].size();++i)dfs(G[now][i],kill);
}

int main(){
	while(cin>>n, n){ cin>>m;
	    for(int i=0;i<n;++i)G[i].clear();
	    memset(gf0,0,sizeof(gf0));
	    memset(ans,0,sizeof(ans));
		while(m--){
			int u,v; cin>>u>>v;
			G[u].push_back(v);
		}
		test0(0);
		for(int i=0;i<n;++i){
			memset(v,0,sizeof(v));
			dfs(0,i);
			for(int j=0;j<n;++j)ans[i][j]=(gf0[j]&&(!v[j]));
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(ans[i][j])cout<<"Y";
				else cout<<"N";
			} cout<<endl;
		}
	}
}
