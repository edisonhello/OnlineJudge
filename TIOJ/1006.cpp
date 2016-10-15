//
// Created by Wayne Tu on 3/6/16.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <string.h>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <string>

using namespace std;

class BigNumber
{
public:
    BigNumber() {
        // zero()
    }

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

    BigNumber(const char* digits) {

        m_digits.resize(strlen(digits));
        int i = 0;
        while (char ch = *digits++) {
            m_digits[m_digits.size() - i - 1] = ch - '0';
            i++;
        }
    }

    BigNumber(const BigNumber& bn, int n) {

        if (bn.isZero() || n == 0)
            return;

        int start = max(bn.length() - n, 0);
        for (int i = start; i < bn.length(); i++) {
            m_digits.push_back(bn.getDigit(i));
        }
    }

    int length() const {
        return m_digits.size();
    }

    // 取得第幾位數, 第0位 = 最小位數, 超過位數者回0
    //
    int getDigit(int i) const {
        if (i >= m_digits.size())
            return 0;
        else
            return m_digits[i];
    }


    BigNumber& addMSB(int value) {
        m_digits.push_back(value);
        return *this;
    }


    BigNumber& shift(int digits) {
        for (int i = 0; i < digits; i++)
            m_digits.insert(m_digits.begin(), 0);
        return *this;
    }


    BigNumber add(int n) const {
        if (isZero())
            return BigNumber(n);

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

        if (isZero())
            return BigNumber();

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

        if (dividend < divisor)
            return result;


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
            else {
                break;
            }
        } while (true);

        return result.trim();
    }

    static int divideOne(const BigNumber& dividend, const BigNumber& divisor, BigNumber& r) {
        BigNumber t = divisor;
        int q = 1;
        while (t <= dividend) {
            t = divisor * (++q);
        }

        q--;
        if (q <= 0) {
            r = dividend;
        }
        else {
            t = divisor * q;
            r = dividend - t;
        }
        r.trim();
        return q;
    }


    static bool lessThen(const BigNumber& l, const BigNumber& r, bool orEqual) {
        if (l.length() < r.length())
            return true;
        else if (l.length() > r.length())
            return false;
        else {
            int i = l.length() - 1;
            while (l.getDigit(i) == r.getDigit(i) && i >= 0) {
                i--;
            }

            if (i < 0) {
                return orEqual ? true : false;
            }
            else {
                return l.getDigit(i) < r.getDigit(i);
            }
        }
    }

    bool isZero() const {
        return m_digits.size() == 0 || (m_digits.size() == 1 && m_digits[0] == 0);
    }

    BigNumber& trim() {
        while (m_digits.size() > 0 && m_digits[m_digits.size()-1] == 0) {
            std::vector<int>::iterator it = m_digits.begin();
            std::advance(it, m_digits.size()-1);
            m_digits.erase(it);
        }
        return *this;
    }

    std::string printAsString() const {
        if (isZero())
            return "0";

        std::string ret = "";
        for (int i = m_digits.size() - 1; i >= 0; i--) {
            ret += m_digits[i] + '0';
        }
        return ret;
    }


    friend ostream& operator<<(ostream& os, const BigNumber& bn) {
        os << bn.printAsString();
        return os;
    }

    friend bool operator<(const BigNumber& l, const BigNumber& r) {
        // return true if l < r
        //
        return lessThen(l, r, false);
    }

    friend bool operator<=(const BigNumber& l, const BigNumber& r) {
        // return true if l <= r
        //
        return lessThen(l, r, true);
    }

    friend BigNumber operator+(const BigNumber& t, int value) {
        return t.add(value);
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

private:
    std::vector<int> m_digits;
};


void test_constructor() {
    cout << BigNumber(123) << endl;
    cout << BigNumber("123") << endl;
    cout << BigNumber() << endl;

    cout << BigNumber(BigNumber("1234"), 1) << endl;
    cout << BigNumber(BigNumber("1234"), 2) << endl;
    cout << BigNumber(BigNumber("1234"), 3) << endl;
    cout << BigNumber(BigNumber("1234"), 4) << endl;
    cout << BigNumber(BigNumber("1234"), 5) << endl;
}

void test_add() {
    cout << BigNumber(1234).add(2) << endl;
    cout << BigNumber(1234).add(9) << endl;
    cout << BigNumber(1234).add(89) << endl;
}

void test_multiply() {
    cout << BigNumber(1234).multiply(2) << endl;
    cout << BigNumber(1234).multiply(4) << endl;
    cout << BigNumber(1234).multiply(5) << endl;
    cout << BigNumber(1234).multiply(8) << endl;
}

void test_subtract() {
    BigNumber a_1234(1234);
    BigNumber a_345(345);
    BigNumber a_1230(1230);
    BigNumber a_1218(1218);
    BigNumber a_987(987);

    cout << a_1234.subtract(a_345) << endl;
    cout << a_1234.subtract(a_1230) << endl;
    cout << a_1234.subtract(a_1218) << endl;
    cout << a_1234.subtract(a_987) << endl;
    cout << a_1234.subtract(a_1234) << endl;
}

void test_divide() {
    BigNumber q;

    q = BigNumber::divide(BigNumber(40024), BigNumber(1));
    cout << "q=" << q << endl;

    q = BigNumber::divide(BigNumber(40024), BigNumber(10));
    cout << "q=" << q << endl;

    q = BigNumber::divide(BigNumber(40024), BigNumber(100));
    cout << "q=" << q << endl;

    q = BigNumber::divide(BigNumber(40024), BigNumber(1000));
    cout << "q=" << q << endl;

    q = BigNumber::divide(BigNumber(1234), BigNumber(1234));
    cout << "q=" << q << endl;

    q = BigNumber::divide(BigNumber(1235), BigNumber(1234));
    cout << "q=" << q << endl;

    q = BigNumber::divide(BigNumber(1234), BigNumber(1235));
    cout << "q=" << q << endl;

    q = BigNumber::divide(BigNumber(2345), BigNumber(1235));
    cout << "q=" << q << endl;

    q = BigNumber::divide(BigNumber(4567), BigNumber(1235));
    cout << "q=" << q << endl;

    q = BigNumber::divide(BigNumber(12340), BigNumber(1234));
    cout << "q=" << q << endl;

    q = BigNumber::divide(BigNumber(12350), BigNumber(1234));
    cout << "q=" << q << endl;

    q = BigNumber::divide(BigNumber(123400), BigNumber(1235));
    cout << "q=" << q << endl;

    q = BigNumber::divide(BigNumber(234589), BigNumber(1235));
    cout << "q=" << q << endl;

    q = BigNumber::divide(BigNumber(4567098), BigNumber(1235));
    cout << "q=" << q << endl;
}

void test_divideOne() {
    BigNumber r;
    int q;

    q = BigNumber::divideOne(BigNumber(1234), BigNumber(1234), r);
    cout << "q=" << q << " r=" << r << endl;

    q = BigNumber::divideOne(BigNumber(1235), BigNumber(1234), r);
    cout << "q=" << q << " r=" << r << endl;

    q = BigNumber::divideOne(BigNumber(1234), BigNumber(1235), r);
    cout << "q=" << q << " r=" << r << endl;

    q = BigNumber::divideOne(BigNumber(2345), BigNumber(1235), r);
    cout << "q=" << q << " r=" << r << endl;

    q = BigNumber::divideOne(BigNumber(4567), BigNumber(1235), r);
    cout << "q=" << q << " r=" << r << endl;
}

void test_compare() {
    cout << (BigNumber(123) < BigNumber(1234)) << endl;
    cout << (BigNumber(1234) < BigNumber(123)) << endl;
    cout << (BigNumber(1234) < BigNumber(1235)) << endl;
    cout << (BigNumber(1235) < BigNumber(1234)) << endl;
    cout << (BigNumber(1235) < BigNumber(2234)) << endl;
}

void test_more_divide(int loops) {
    srand(unsigned(std::time(0)));

    for (int i = 0; i < loops; i++) {
        int dividend = rand() % 10000000;
        int divisor = rand() % 10000 + 1;

        int answer = dividend / divisor;

        BigNumber bnDividend(dividend);
        BigNumber bnDivisor(divisor);
        BigNumber bnAnswer = bnDividend / bnDivisor;

        if (atoi(bnAnswer.printAsString().c_str()) != answer) {
            cout << "ERROR: " << dividend << " / " << divisor << " expect:" << answer << " get:" << bnAnswer << endl;
        }
    }
}

int main() {
    string bn1,bn2;
    cin>>bn1>>bn2;

    BigNumber b(bn1.c_str());
    BigNumber s(bn2.c_str());

    BigNumber q=BigNumber::divide(b,s);
    cout<<q<<endl;
    return 0;
}
