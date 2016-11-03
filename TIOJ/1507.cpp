#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Big {
public:
  Big() { __d.push_back(0); }

  Big(string s) {
    for (int i = s.length() - 1; i >= 0; --i) {
      __d.push_back(s[i] - '0');
    }
  }

  Big(vector<int> d) {
    __d = d;
  }

  Big& operator=(const Big& b) {
    __d = b.__d;
    return *this;
  }

  Big operator+(const Big& b) const {
    vector<int> ret; int carry = 0;
    if (__d.size() > b.__d.size()) {
      for (int i = 0; i < b.__d.size(); ++i) {
        int cur = __d[i] + b.__d[i] + carry;
        if (cur > 9) cur -= 10, carry = 1;
        else carry = 0;
        ret.push_back(cur);
      }
      for (int i = b.__d.size(); i < __d.size(); ++i) {
        int cur = __d[i] + carry;
        if (cur > 9) cur -= 10, carry = 1;
        else carry = 0;
        ret.push_back(cur);
      }
      if (carry) ret.push_back(1);
      return Big(ret);
    } else {
      for (int i = 0; i < __d.size(); ++i) {
        int cur = __d[i] + b.__d[i] + carry;
        if (cur > 9) cur -= 10, carry = 1;
        else carry = 0;
        ret.push_back(cur);
      }
      for (int i = __d.size(); i < b.__d.size(); ++i) {
        int cur = b.__d[i] + carry;
        if (cur > 9) cur -= 10, carry = 1;
        else carry = 0;
        ret.push_back(cur);
      }
      if (carry) ret.push_back(1);
      return Big(ret);
    }
  }

  Big operator*(const int& n) const {
    vector<int> ret; int carry = 0;
    for (int i = 0; i < __d.size(); ++i) {
      int cur = __d[i] * n + carry;
      carry = cur / 10; cur %= 10;
      ret.push_back(cur);
    }
    if (carry) ret.push_back(carry);
    return Big(ret);
  }

  Big operator*(const Big& b) const {
    Big ret;
    // cout << ret << endl;
    int t = 1;
    for (int i = 0; i < b.__d.size(); ++i) {
      cout << "ret: " << ret << endl;
      Big tmp = (*this) * b.__d[i];
      cout << "jizz: " << (*this) * b.__d[i] << endl;
      // cout << "t: " << t << endl;
      cout << "ret+: " << ret + (*this) * b.__d[i] << endl;
      ret = ret + tmp * t;
      t *= 10;
    }
    return ret;
  }

  friend ostream& operator<<(ostream& out, const Big& b) {
    for (int i = b.__d.size() - 1; i >= 0; --i) out << b.__d[i];
    return out;
  }

private:
  vector<int> __d;
};

string s1, s2;
char c;
void test();

int main() {
  // test();
  cin >> s1 >> c >> s2;
  Big b1 = Big(s1), b2 = Big(s2);
  if (c == '+') cout << b1 + b2 << endl;
  if (c == '*') cout << b1 * b2 << endl;
  // if (c == '/') cout << b1 / b2 << endl;
  // Big test1("18783252"), test2("46378400");
  // cout << test1 + test2 << endl;
  return 0;
}

void test() {
  int n;
  while (cin >> s1 >> n) {
    Big b(s1);
    cout << "b: " << b << " b*n: " << b * n << endl;
  }
}
