  #include <iostream>
  #include <algorithm>
  #include <vector>
  #include <queue>
  using namespace std;

  int main() {
    priority_queue<int, vector<int>, less<int> > X;
    int i = 0;
    int x;
    while (cin >> x) {
      i++;
      X.push(x);
      if (i % 2 == 1) {
        cout << *(X.begin() + (i - 1) / 2) << endl;
      } else {
        cout << (X[i / 2 - 1] + X[i / 2]) / 2 << endl;
      }
    }
    return 0;
  }
