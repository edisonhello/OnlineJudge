#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

long long MAX = 1000000000000000000;

int main() {
  srand(time(NULL));
  freopen("in.txt", "w", stdout);
  cout << (long long)rand() * (long long)rand() * (long long)rand() % MAX + 1 << endl;
  return 0;
}
