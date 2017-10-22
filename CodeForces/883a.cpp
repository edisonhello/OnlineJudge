#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll com[100005];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,a,d; int m; cin>>n>>m>>a>>d;
    for(int i=0;i<m;++i)cin>>com[i];
    ll nowtime=0,rdcom=-1;
    while(nowtime<=n*a || nowtime<=com[m-1]){
        ll next_fix=(nowtime/a+1)*a;
        ll next_cli=com[rdcom+1];
        if(next_fix<next_cli){
            ll next_time=next_cli;
            
        }
    }
}
