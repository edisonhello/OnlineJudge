#include <iostream>
using namespace std;

class Foo {
private:
  int n;
  Foo(int _n): n(_n) {}
public:
  int GetN() { return n; }
};

int main() {
  int n; cin >> n;
  Foo bar = Foo(n);
  cout << bar.GetN() << endl;
  return 0;
}
