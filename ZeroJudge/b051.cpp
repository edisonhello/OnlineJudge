#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string s, ret, sss;
stringstream ss;
vector<string> vec;

int main() {
  while (getline(cin, s)) {
    ss.clear();
    vec.clear();
    ss << s;
    ss >> sss;
    while (ss >> sss) vec.push_back(sss);
    sort(vec.begin(), vec.end(), cmp);
    ret = "";
    for (int i = vec.size() - 1; i >= 0; --i) {cout << vec[i] << endl; ret += vec[i];}
    cout << ret << endl;
  }
}
