#include <iostream>
#include <string>
using namespace std;

string in, out;

int main() {
  while (getline(cin, in)) {
    out = "";
    for (int i = 0; i < in.length(); ++i) {
      out += (char)(in[i] - 7);
    }
    cout << out << endl;
  }
  return 0;
}
