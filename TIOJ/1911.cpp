#include <iostream>
#include <queue>
#include <map>
#define endl '\n'
using namespace std;

map<int, int> mp;
priority_queue<int, vector<int>, less<int>> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;

int a;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while (cin >> a, a) {
        if (a == -2) {
            if (pq1.size()) {
                while (pq1.size() && !mp[pq1.top()]) pq1.pop();
                if (pq1.size()) {
                    mp[pq1.top()]--;
                    cout << pq1.top() << ' ';
                    pq1.pop();
                }
            }
        } else if (a == -1) {
            if (pq2.size()) {
                while (pq2.size() && !mp[pq2.top()]) pq2.pop();
                if (pq2.size()) {
                    mp[pq2.top()]--;
                    cout << pq2.top() << ' ';
                    pq2.pop();
                }
            }
        } else {
            mp[a]++;
            pq1.push(a);
            pq2.push(a);
        }
    }
    return 0;
}
