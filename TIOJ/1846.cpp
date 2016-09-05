#include <iostream>
#include <cmath>
#include <iomanip>
// #define double double
using namespace std;

const double pi = acos(-1);

double f1(double a, double b, double c) {
  double s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

double f2(double a, double b, double c) {
  return acos((b * b + c * c - a * a) / (2 * b * c));
}

double f3(double r, double theta) {
  return r * r * theta / 2;
}

double dis(double x1, double y1, double x2, double y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
  // cout << pi << endl;
  int T;
  double x1, y1, r1, x2, y2, r2;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int c;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    if (r1 >= r2) {
      if (r1 >= dis(x1, y1, x2, y2) + r2) {
        c = 1;
      } else {
        if (r1 + r2 <= dis(x1, y1, x2, y2)) {
          c = 2;
        } else {
          if (dis(x1, y1, x2, y2) < r1) {
            c = 4;
          } else {
            c = 3;
          }
        }
      }
    } else {
      if (r2 >= dis(x1, y1, x2, y2) + r1) {
        c = 1;
      } else {
        if (r1 + r2 <= dis(x1, y1, x2, y2)) {
          c = 2;
        } else {
          if (dis(x1, y1, x2, y2) < r2) {
            c = 4;
          } else {
            c = 3;
          }
        }
      }
    }
    switch(c) {
      case 1:
        if (r1 >= r2) {
          cout << fixed << setprecision(2) << r2 * r2 * pi << endl;
        } else {
          cout << fixed << setprecision(2) << r1 * r1 * pi << endl;
        }
        break;
      case 2:
        cout << "0.00" << endl;
        break;
      case 3:
        double area = f1(r1, r2, dis(x1, y1, x2, y2)) * 2;
        double h = area * 2 / (dis(x1, y1, x2, y2));
        double theta1 = f2(h, r1, r1);
        double theta2 = f2(h, r2, r2);
        double a1 = f3(r1, theta1);
        double a2 = f3(r2, theta2);
        double ans = a1 + a2 - area;
        cout << fixed << setprecision(2) << ans << endl;
        break;
      case 4:
        double area2 = f1(r1, r2, dis(x1, y1, x2, y2)) * 2;
        double theta12 = 2 * f2(r2, r1, dis(x1, y1, x2, y2));
        double theta22 = 2 * f2(r1, r2, dis(x1, y1, x2, y2));
        double a12 = f3(r1, theta12);
        double a22 = f3(r2, theta22);
        double ans2 = a12 + a22 - area2;
        cout << fixed << setprecision(2) << ans2 << endl;
        break;
    }
  }
  return 0;
}
