#include<bits/stdc++.h>
using namespace std;


int B[1111];

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

int a[1111];
int main(){
	while(cin>>n,n){
		/*int ans=0;
		memset(B,0,sizeof(B));
		for(int i=0;i<n;++i){
			int t; cin>>t;
			ans=max(ans,qry(t-1));
			add(t,1);
		}*/
		for (int i = 0; i < n; ++i)cin>>a[i];
		vector<int> vec; vec.push_back(a[0]);
		for (int i= 1;i<n;++i){
			if (a[i]>vec.back()) vec.push_back(a[i]);
			else *lower_bound(vec.begin(),vec.end(),a[i]) = a[i];
		} 
		cout<<vec.size()<<endl;
	}
	
}
