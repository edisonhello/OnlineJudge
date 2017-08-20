#include<bits/stdc++.h>
using namespace std;

int a[33],ans[33];
int B[33];

#define lb(x) ((x)&(-(x)))

int n;
void add(int x,int v){
	while(x<=n){
		B[x]+=v;
		x+=lb(x);
	}
}
int qry(int x,int v=0){
	while(x>0){
		v+=B[x];
		x-=lb(x);
	} return v;
}
bool cmp(const pair<long double,int> &a,const pair<long double,int> &b){
	return a.second<b.second;
}
int level[33];
int main(){
	// freopen("Fin.txt","r",stdin);
	while(cin>>n,n){
	    memset(B,0,sizeof(B));
		char c; cin>>c;
		for(int i=1;i<=n;++i) cin>>a[i];
		if(c=='A'){
			for(int i=1;i<=n;++i){
				ans[i]=qry(a[i]);
				add(a[i]+1,1);
			}
			// cout<<"jizz"<<endl;
			for(int i=1;i<=n;++i){
				cout<<ans[i]<<" \n"[i==n];
			}
		}
		else{
	  		 vector<pair<long double,int> > aa;
	  		 aa.push_back(pair<long double,int>(0.0,0));
	  		 aa.push_back(pair<long double,int>(9999999.9,0));
	  		 for(int i=1;i<=n;++i){
			   		 //cout<<i<<" "<<(aa[a[i]].first+aa[a[i]+1].first)/2<<endl;
	  		 		 aa.push_back(pair<long double,int>((aa[a[i]].first+aa[a[i]+1].first)/2,i));
	  		 		 sort(aa.begin(),aa.end());
	 			}
				for(int i=1;i<=n;++i)level[aa[i].second]=i-1;
				for(int i=1;i<=n;++i){
					cout<<level[i]<<" \n"[i==n];
				}
		}
	}
}
