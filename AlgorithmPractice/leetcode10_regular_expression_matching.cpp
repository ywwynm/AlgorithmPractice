#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int sLen = s.length(), pLen = p.length();
    if (pLen == 0) return sLen == 0;
    bool first_match = s.length() > 0 && (s[0] == p[0] || p[0] == '.');
    if (pLen >= 2 && p[1] == '*') {
      return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
    } else {
      return first_match && isMatch(s.substr(1), p.substr(1));
    }
  }
};

// int main() {
//   Solution solution;
//   string s, p;
//   cin >> s >> p;
//   cout << solution.isMatch(s, p) << endl;
//   return 0;
// }