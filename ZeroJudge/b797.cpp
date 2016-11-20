#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

class BigNumber {
public:
  BigNumber() {}

  BigNumber(int value) {
    do {
      int digit = value % 10;
      m_digits.push_back(digit);
      value = value / 10;
    } while (value > 0);
  }

  BigNumber(const BigNumber& bn) {
    m_digits = bn.m_digits;
  }

  BigNumber(const string digits) {
    m_digits.resize(digits.length());
    int i = 0, j = 0;;
    while (char ch = digits[j++]) {
      m_digits[m_digits.size() - i - 1] = ch - '0';
      i++;
    }
  }

  BigNumber(const BigNumber& bn, int n) {
    if (bn.isZero() || n == 0) return;
    int start = max(bn.length() - n, 0);
    for (int i = start; i < bn.length(); i++) m_digits.push_back(bn.getDigit(i));
  }

  int length() const {
    return m_digits.size();
  }

  int getDigit(int i) const {
    if (i >= m_digits.size()) return 0;
    else return m_digits[i];
  }

  BigNumber& addMSB(int value) {
    m_digits.push_back(value);
    return *this;
  }

  BigNumber& shift(int digits) {
    for (int i = 0; i < digits; i++) m_digits.insert(m_digits.begin(), 0);
    return *this;
  }

  BigNumber add(int n) const {
    if (isZero()) return BigNumber(n);
    BigNumber result = *this;
    int carry = n;
    for (int i = 0; i < result.m_digits.size() && carry > 0; i++) {
      int value = result.m_digits[i] + carry;
      result.m_digits[i] = value % 10;
      carry = value / 10;
    }
    while (carry > 0) {
      result.addMSB(carry % 10);
      carry = carry / 10;
    }
    return result;
  }

  BigNumber multiply(int n) const {
    BigNumber result;
    if (isZero()) return BigNumber();
    int carry = 0;
    for (int i = 0; i < m_digits.size(); i++) {
      int mul = n * m_digits[i] + carry;
      result.addMSB(mul % 10);
      carry = mul / 10;
    }
    while (carry > 0) {
      result.addMSB(carry % 10);
      carry = carry / 10;
    }
    return result;
  }

  BigNumber subtract(const BigNumber& t) const {
    BigNumber result;
    int borrow = 0;
    for (int i = 0; i < length(); i++) {
      int value = getDigit(i) - borrow - t.getDigit(i);
      if (value >= 0) {
        result.addMSB(value);
        borrow = 0;
      }
      else {
        result.addMSB(10 + value);
        borrow = 1;
      }
    }
    return result.trim();
  }

  static BigNumber divide(const BigNumber& dividend, const BigNumber& divisor) {
    BigNumber result;
    if (dividend < divisor) return result;
    BigNumber m(dividend, divisor.length());
    int next = dividend.length() - divisor.length() - 1;
    do {
      BigNumber r;
      int q = divideOne(m, divisor, r);
      result = result.shift(1).add(q).trim();
      if (next >= 0) {
        m = r.shift(1).add(dividend.getDigit(next)).trim();
        next--;
      }
      else break;
    } while (true);
    return result.trim();
  }

  static int divideOne(const BigNumber& dividend, const BigNumber& divisor, BigNumber& r) {
    BigNumber t = divisor;
    int q = 1;
    while (t <= dividend) t = divisor * (++q);
    q--;
    if (q <= 0) r = dividend;
    else t = divisor * q, r = dividend - t;
    r.trim();
    return q;
  }


  static bool lessThen(const BigNumber& l, const BigNumber& r, bool orEqual) {
    if (l.length() < r.length()) return true;
    else if (l.length() > r.length()) return false;
    else {
      int i = l.length() - 1;
      while (l.getDigit(i) == r.getDigit(i) && i >= 0) i--;
      if (i < 0) return orEqual;
      else return l.getDigit(i) < r.getDigit(i);
    }
  }

  bool isZero() const {
    return m_digits.size() == 0 || (m_digits.size() == 1 && m_digits[0] == 0);
  }

  BigNumber& trim() {
    while (m_digits.size() > 0 && m_digits[m_digits.size() - 1] == 0) {
      vector<int>::iterator it = m_digits.begin();
      advance(it, m_digits.size()-1);
      m_digits.erase(it);
    }
    return *this;
  }

  string printAsString() const {
    if (isZero()) return "0";
    string ret = "";
    for (int i = m_digits.size() - 1; i >= 0; i--) ret += m_digits[i] + '0';
    return ret;
  }


  friend ostream& operator<<(ostream& os, const BigNumber& bn) {
    for (int i = bn.m_digits.size() - 1; i >= 0; --i) os << bn.m_digits[i];
    return os;
  }

  friend bool operator<(const BigNumber& l, const BigNumber& r) {
    return lessThen(l, r, false);
  }

  friend bool operator<=(const BigNumber& l, const BigNumber& r) {
    return lessThen(l, r, true);
  }

  // friend BigNumber operator+(const BigNumber& t, int value) {
  //     return t.add(value);
  // }

  bool operator<=(const string& s) const {
    return (*this) <= BigNumber(s);
  }

  bool operator>=(const string& s) const {
    return BigNumber(s) <= *this;
  }

  bool operator>(const string& s) const {
    return BigNumber(s) < *this;
  }

  friend BigNumber operator*(const BigNumber& t, int value) {
    return t.multiply(value);
  }

  friend BigNumber operator-(const BigNumber& l, const BigNumber& r) {
    return l.subtract(r);
  }

  friend BigNumber operator/(const BigNumber& l, const BigNumber& r) {
    return divide(l, r);
  }

  BigNumber operator+(const BigNumber& b) const {
  vector<int> ret; int carry = 0; string ans = "";
  if (m_digits.size() > b.m_digits.size()) {
    for (int i = 0; i < b.m_digits.size(); ++i) {
      int cur = m_digits[i] + b.m_digits[i] + carry;
      if (cur > 9) cur -= 10, carry = 1;
      else carry = 0;
      ret.push_back(cur);
    }
    for (int i = b.m_digits.size(); i < m_digits.size(); ++i) {
      int cur = m_digits[i] + carry;
      if (cur > 9) cur -= 10, carry = 1;
      else carry = 0;
      ret.push_back(cur);
    }
    if (carry) ret.push_back(1);
    // return BigNumber(ret);
  } else {
    for (int i = 0; i < m_digits.size(); ++i) {
      int cur = m_digits[i] + b.m_digits[i] + carry;
      if (cur > 9) cur -= 10, carry = 1;
      else carry = 0;
      ret.push_back(cur);
    }
    for (int i = m_digits.size(); i < b.m_digits.size(); ++i) {
      int cur = b.m_digits[i] + carry;
      if (cur > 9) cur -= 10, carry = 1;
      else carry = 0;
      ret.push_back(cur);
    }
    if (carry) ret.push_back(1);
  }
  // for (int i = ret.size() - 1; i >= 0; --i) cout << ret[i];
  // cout << endl;
  for (int i = ret.size() - 1; i >= 0; --i) ans += (ret[i] + '0');
  return BigNumber(ans);
}
private:
  std::vector<int> m_digits;
};

int T, N;
BigNumber dp[40005];

int main() {
  cin >> T;
  while (T--) {
    for (int i = 0; i <= N; ++i) dp[i] = 0;
    cin >> N;
    dp[0] = 1;
    for (int  i = 1; i <= sqrt(N); ++i) {
      for (int j = i * i; j <= N; ++j) {
        dp[j] = dp[j] + dp[j - i * i];
      }
    }
    cout << dp[N] << endl;
  }
  return 0;
}
