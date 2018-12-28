#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    if (x == 1 || x == 2) return 1;
    long long x_ll = (long long) x;
    long long start = 0, end = x;
    long long mid = (start + end) / 2;
    while (start != end) {
      if (mid * mid == x_ll) return (int) mid;
      if (mid * mid > x_ll && (mid - 1) * (mid - 1) < x_ll) {
        return (int) mid - 1;
      }
      if (mid * mid < x_ll) {
        start = mid;
      } else {
        end = mid;
      }
      mid = (start + end) / 2;
    }
    return (int) mid;
  }

  int newton(int x) {
    double xd = (double) x;
    double xn = xd / 2.0;
    while (fabs(xn * xn - xd) >= 0.1) {
      // xn = xn / 2.0 + xd / (2.0 * xn);
      xn = (xn + xd / xn) / 2.0;
    }
    return (int) xn;
  }
};

int main() {
  Solution s;
  cout << s.newton(2147395599) << endl;
  return 0;
}