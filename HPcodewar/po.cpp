#include<iostream>
using namespace std;

int main(){
    int a,b,c;cin>>a>>b>>c;
    int cnt=0;
    int bb=b;
    while(a>=12){
        int nw=a/12;
        cnt+=nw;
        b-=nw;
        a%=12;
        a+=nw*2;
        cout<<a<<" "<<cnt<<endl;
    }
    cnt=min(cnt,bb);
    cout<<cnt<<" ";
    if(c*120>=cnt)cout<<cnt*1000<<endl;
    else cout<<c*120*1000+(cnt-c*120)*500<<endl;
}
