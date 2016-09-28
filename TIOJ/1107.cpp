#include <cstdio>
#include <cmath>
using namespace std;

int N;
long long int lg;

int main() {
  while (scanf("%d", &N) != EOF && N != 0) {
    lg = floor(log10(pow(2, N) - N));
    printf("%.3fe+%01lld\n", (pow(2, N) - N) / pow(10, lg), lg);
  }
}
