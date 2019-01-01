#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    string ret = "/";
    const int len = path.size();
    if (path[len - 1] != '/') {
      path += '/';
    }
    int i = 1;
    string cur = "";
    while (i < len + 1) {
      char c = path[i];
      cur += c;
      if (c == '/') {
        if (cur == "../") {
          int retLen = ret.length();
          for (int j = retLen - 2; j >= 0; j--) {
            if (ret[j] == '/') {
              ret = ret.substr(0, j + 1);
              break;
            }
          }
        } else if (cur != "./" && cur != "/") {
          ret += cur;
        }
        cur = "";
      }
      i++;
    }
    int retLen = ret.length();
    if (ret[retLen - 1] == '/' && retLen > 1) {
      ret = ret.substr(0, retLen - 1);
    }
    return ret;
  }
};

//int main() {
//  Solution s;
//  cout << s.simplifyPath("/a/./b/../../c/") << endl;
//  return 0;
//}