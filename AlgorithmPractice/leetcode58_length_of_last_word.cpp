#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    const int len = s.length();
    if (len == 0) return 0;
    int count = 0;
    bool alphabet = false;
    for (int i = len - 1; i >= 0; i--) {
      if (s[i] == ' ' && alphabet) {
        break;
      }
      if (s[i] != ' ') {
        alphabet = true;
        count++;
      }
    }
    return count;

    // even this simple problem has a possible better solution, that is, we can use functions like find_last_not_of or something like that
  }
};

int main() {
  Solution s;
  cout << s.lengthOfLastWord("hello1  world23 ") << endl;
  return 0;
}