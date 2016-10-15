#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class BigNumber {
public:
  BigNumber(string s) {
    for (int i = 0; i < s.length(); ++i) {
      _d.push_back(s[i] - '0');
    }
  }

  BigNumber(vector<int> d) {
    _d = d;
  }

  BigNumber() {}

  int len() const {return _d.size();}

  BigNumber operator+(const BigNumber& b) {
    bool carry = false;
    vector<int> d;
    for (int i = 0; i < min(this->len(), b.len()); ++i) {
      int n = _d[i] + b._d[i];
      if (carry) n++;
      if (n >= 10) n -= 10, carry = true;
      else carry = false;
      d.push_back(n);
    }
    if (this->len() > b.len()) {
      for (int i = b.len(); i < this->len(); ++i) {
        int n = _d[i];
        if (carry) n++;
        if (n >= 10) n -= 10, carry = true;
        else carry = false;
        d.push_back(n);
      }
      if (carry) d.push_back(1);
    }
    else if (this->len() > b.len()) {
      for (int i = this->len(); i < b.len(); ++i) {
        int n = b._d[i];
        if (carry) n++;
        if (n >= 10) n -= 10, carry = true;
        else carry = false;
        d.push_back(n);
      }
      if (carry) d.push_back(1);
    }
    return BigNumber(d);
  }

  friend ostream& operator<<(ostream& out, BigNumber& b) {
    for (int i = b.len() - 1; i >= 0; --i) out << b._d[i];
    // out << endl;
    return out;
  }


private:
  vector<int> _d;
};

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  BigNumber b1 = BigNumber(s1);
  BigNumber b2 = BigNumber(s2);
  BigNumber b3 = b1 + b2;
  cout << b3 << endl;
  return 0;
}
