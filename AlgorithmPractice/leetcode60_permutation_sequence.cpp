#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string getPermutation(int n, int k) {
    vector<int> factorials;
    vector<int> numbers;
    int accumulate = 1;
    for (int i = 1; i <= n; i++) {
      accumulate *= i;
      factorials.push_back(accumulate);
      numbers.push_back(i);
    }
    string ret = "";
    k--;
    for (int i = 1; i < n; i++) {
      int fac = factorials[n - i - 1];
      int idx = k / fac;
      ret += ('0' + numbers[idx]);
      numbers.erase(numbers.begin() + idx);
      k -= idx * fac;
    }
    ret += ('0' + numbers[0]);
    return ret;
  }
};

int main() {
  Solution s;
  cout << s.getPermutation(2, 2) << endl;
  return 0;
}