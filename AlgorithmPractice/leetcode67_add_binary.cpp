#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    string ret = "";
    int l1 = a.length(), l2 = b.length();
    int i = l1 - 1, j = l2 - 1;
    int add = 0;
    while (i >= 0 || j >= 0) {
      int c1 = i >= 0 ? a[i] - '0' : 0;
      int c2 = j >= 0 ? b[j] - '0' : 0;
      int sum = c1 + c2 + add;
      if (sum < 2) {
        add = 0;
        ret = to_string(sum) + ret;
      } else {
        add = 1;
        ret = to_string(sum - 2) + ret;
      }
      i--; j--;
    }
    if (add != 0) ret = "1" + ret;
    return ret;
  }
};

int main() {
  Solution s;
  cout << s.addBinary("0", "0") << endl;
  cout << s.addBinary("0", "111") << endl;
  cout << s.addBinary("11", "1") << endl;
  cout << s.addBinary("1", "101") << endl;
  cout << s.addBinary("1010", "1011") << endl;
  return 0;
}