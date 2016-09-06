#include <iostream>
#include <string>
using namespace std;

struct color {
  int r, g, b;
};

color c[1000][1000];

void G();
void I();
void R();
void H();
void V();
int n;
int degree;

int main() {
  degree = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> c[i][j].r;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> c[i][j].g;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> c[i][j].b;
    }
  }
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); ++i) {
    switch(s[i]) {
      case 'G': G();
      case 'I': I();
      case 'R': R();
      case 'H': H();
      case 'V': V();
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << c[i][j].r << ' ';
    }
    cout << endl;
  }
  cout << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << c[i][j].g << ' ';
    }
    cout << endl;
  }
  cout << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << c[i][j].b << ' ';
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}

void G() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int avg = (c[i][j].r + c[i][j].g + c[i][j].b) / 3;
      c[i][j].r = avg;
      c[i][j].g = avg;
      c[i][j].b = avg;
    }
  }
}

void I() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      c[i][j].r = 255 - c[i][j].r;
      c[i][j].g = 255 - c[i][j].g;
      c[i][j].b = 255 - c[i][j].b;
    }
  }
}

void R() {

}

void H() {
  for (int i = 0; i < n / 2; ++i) {
    for (int j = 0; j < n; ++j) {
      color temp = c[i][j];
      c[i][j] = c[n - i + 1][j];
      c[n - i + 1][j] = temp;
    }
  }
  g += 2;
  if (g > 3) g -= 4;
}

void V() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n / 2; ++j) {
      color temp = c[i][j];
      c[i][j] = c[i][n - j + 1];
      c[i][n - j + 1] = temp;
    }
  }
}
