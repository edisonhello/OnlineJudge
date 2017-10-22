#include <bits/stdc++.h>
#define tsum(t) (t ? t->sum : 0)
#define tsize(t) (t ? t->sz : 0)
using namespace std;

template<typename T>
void ppq(T pq){while(pq.size()){cout<<pq.top()<<" , ";pq.pop();}cout<<endl;}

const int maxn = 1e5 + 10;

bitset<maxn> v;
pair<int,int> itm[maxn];
bool cmp(const int &a,const int &b){return itm[a].second>itm[b].second;}
struct fenwick {
    deque<int> que[maxn];
    void add(int x, int v) {
        for (int i = x; i < maxn; i += i & -i) que[i].push_back(v);
    } 
    void qry(int x, priority_queue<int,vector<int>,decltype(&cmp)> &pq) {
        for (int i = x; i; i -= i & -i) {
            while (que[i].size() && v[que[i].front()]) que[i].pop_front();
            for (int j : que[i]) pq.push(j);
        }
    }
} bit;

queue<int> qs;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m; cin>>n>>m;
    while(n--){
        int t; cin>>t; qs.push(t);
    }
    for(int i=0;i<m;++i){
        cin>>itm[i].first;
    }
    for(int i=0;i<m;++i){
        cin>>itm[i].second;
    }
    sort(itm,itm+m,[](const pair<int,int> &a,const pair<int,int> &b){return a.second<b.second;});
    for(int i=0;i<m;++i){
        bit.add(itm[i].first,i);
        cout<<itm[i].first<<","<<itm[i].second<<endl;
    }
    int left=0,cnt=0;
    while(qs.size()){
        int t; t=qs.front(); qs.pop();
        priority_queue<int,vector<int>,decltype(&cmp)> pq(cmp);
        cout<<"t = "<<t<<endl;
        bit.qry(t,pq);
        t+=left;
        cout<<"pqsz = "<<pq.size()<<endl;
        ppq(pq);
        // if(pq.size())cout<<"tpid = "<<pq.top()<<endl;
        while(pq.size() && t>=itm[pq.top()].second){
            ++cnt;
            t-=itm[pq.top()].second;
            v[pq.top()]=1;
            cout<<"del "<<pq.top()<<endl;
            pq.pop();
        }
        left=t;
    }
    cout<<cnt<<endl;
}
