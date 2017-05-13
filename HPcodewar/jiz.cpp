#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> v;
    v.push_back(6);
    int l, d, n; cin >> l >> d >> n;
    if(l<12)return cout<<0<<endl,0;
    while(n--){
        int t;cin>>t;
        v.push_back(t);
    }
    v.push_back(l-6);
    sort(v.begin(),v.end());
    int cnt=0;
    for(int i=1;i<v.size();++i){
        cnt+=(v[i]-v[i-1]-1)/d+1;
    }
    cout<<cnt<<endl;
}
