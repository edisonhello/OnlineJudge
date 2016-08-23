#include <iostream>
#include <string>

using namespace std;

bool nand(bool, bool);
bool* solve(bool*);
void render(bool*, int);
int solve2(bool*);
bool compare(bool*, bool*, int);
bool* convert(int);

int main() {
  string s1;
  int ans;
  bool input[5];
  bool output[3];
  while (getline(cin, s1)) {
    // getline(cin, s2);
    if (s1.length() == 5) {
      for (int i = 0; i < 5; ++i) {
        input[i] = (s1[i] == '1');
      }
      bool* result = solve(input);
      render(result, 3);
    } else {
      // render(input, 5);
      for (int i = 0; i < 3; ++i) {
        output[i] = (s1[i] == '1');
      }
      ans = solve2(output);
      cout << ans << endl;
    }
  }
  return 0;
}

bool nand(bool b1, bool b2) {
  if (b1 && b2) return false;
  else return true;
}

bool* solve(bool* input) {
  bool* output = new bool[3];
  bool tmp[4];
  for (int i = 0; i < 4; ++i) {
    tmp[i] = nand(input[i], input[i + 1]);
  }
  for (int i = 0; i < 3; ++i) {
    output[i] = nand(tmp[i], tmp[i + 1]);
  }
  return output;
}

void render(bool* output, int n) {
  for (int i = 0; i < n; ++i) {
    if (output[i]) cout << '1';
    else cout << '0';
  }
  cout << endl;
}

bool* convert(int num) {
  bool* ans = new bool[5];
  int k = 2;
  for (int i = 0; i < 5; ++i) {
    ans[i] = num % k;
    num -= num % k;
    k *= 2;
  }
  return ans;
}

bool compare(bool* b1, bool* b2, int n) {
  for (int i = 0; i < n; ++i) {
    if (b1[i] != b2[i]) return false;
  }
  return true;
}

int solve2(bool* output) {
  int ans = 0;
  for (int i = 0; i < 32; ++i) {
    bool* input = convert(i);
    // render(input, 5);
    bool* result = solve(input);
    if (compare(result, output, 3)) ans++;
  }
  return ans;
}
