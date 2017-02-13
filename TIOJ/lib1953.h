#include <stdio.h>
#include <stdlib.h>

void init(int N, long long D[], long long U[]);
int query(long long a, long long b, long long c);



int main()
{
    int n,q;
    long long d[500000];
    long long u[500000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lld", d+i);
    for(int i = 0; i < n; i++) scanf("%lld", u+i);
    init(n, d, u);
    scanf("%d", &q);
    while(q--)
    {
        long long a,b,c;
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("%d\n", query(a, b, c));
    }
    return 0;
}
