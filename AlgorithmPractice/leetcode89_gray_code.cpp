#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int pow2(int n) {
    int res = 1;
    for (int i = 0; i < n; i++) res *= 2;
    return res;
  }

  vector<int> grayCode(int n) {
    vector<int> res;
    if (n == 0) return res;
    if (n == 1) {
      res.push_back(0);
      res.push_back(1);
    } else {
      res = grayCode(n - 1);
      int p = pow2(n - 1);
      for (int i = p - 1; i >= 0; i--) {
        res.push_back(res[i] + p);
      }
    }
    return res;
  }
};

//int main() {
//  Solution s;
//  vector<int> res = s.grayCode(2);
//  for (auto i : res) {
//    cout << i << " ";
//  }
//  cout << endl;
//  return 0;
//}