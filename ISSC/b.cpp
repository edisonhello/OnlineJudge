#include<bits/stdc++.h>
using namespace std;
int d[23], pre[23];
int main()
{for(int i = 0; i <= 19; ++i)
 {int c = 1;
  for(int j = 0; j < i % 4 + 4; ++j)
  {c = c * i % 10;
  }
  d[i] = c;
 }
 for(int i = 1; i <= 19; ++i)
  pre[i] = (pre[i - 1] + d[i]) % 10;
 //for(int i = 1; i <= 19; ++i)
 // cout<<pre[i]<<' ';
 //cout<<'\n';
 string s; 
 
 while(cin >> s){int ans=0;
  if(s.length()==1&&s[0]=='0')break;
 int a, b;
 if(s.length() > 1)
  a = s[s.length() - 2] - '0';
 
 else a = 0;
 ans+=4*(a/2);
 a%=2;
 b = s[s.length() - 1] - '0';
 cout << (pre[a * 10 + b] +ans)%10<< '\n';
 //cout<<a*10+b<<'\n';
 }
}
