#include <iostream>
#include <cstdio>
using namespace std;

int main() {
int t, a, b;
while (scanf("%d %d %d", &t, &a, &b)) {
switch(t) {
case 1: printf("%d\n", a + b); break;
case 2: printf("%d\n", a - b); break;
case 3: printf("%d\n", a * b); break;
case 4: printf("%d\n", a % b); break;
}
}
return 0;
}
