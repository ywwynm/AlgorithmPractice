#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    if (s == "" || t == "") {
      return "";
    }
    vector<int> map(128, 0);
    for (char c : t) map[c]++;
    
    const int sLen = s.length(), tLen = t.length();
    int leftRequiredLen = tLen;
    int left = 0, right = 0;
    int head = 0;
    int minLen = 0x7f7f7f7f;
    while (right < sLen) {
      char c = s[right];
      if (map[c] > 0) { // 这个字符是t中的字符，并且之前还没能匹配到这个字符
        leftRequiredLen--;
      }
      map[c]--;
      while (leftRequiredLen == 0) {
        if (minLen > right - left + 1) {
          minLen = right - left + 1;
          head = left;
        }
        map[s[left]]++;
        if (map[s[left]] > 0) leftRequiredLen++;
        left++;
      }
      right++;
    }
    return minLen < 0x7f7f7f7f ? s.substr(head, minLen) : "";
  }
};

//int main() {
//  Solution s;
//  cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
//  return 0;
//}